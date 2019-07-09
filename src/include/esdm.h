/**
 * @file
 * @brief Public API of the ESDM. Inlcudes several other public interfaces.
 */
#ifndef ESDM_H
#define ESDM_H

#include <esdm-datatypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

///////////////////////////////////////////////////////////////////////////////
// ESDM ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// These functions must be used before calling init:
/**
 * Set the number of processes to use per node.
 * Must not be called after `init()`.
 *
 * @param [in] procs the number of processes to use per node
 *
 * @return status
 */
esdm_status esdm_set_procs_per_node(int procs);

/**
 * Set the total number of processes to use.
 * Must not be called after `init()`.
 *
 * @param [in] procs the number of processes to use
 *
 * @return status
 */
esdm_status esdm_set_total_procs(int procs);

/**
 * Set the configuration to use.
 * Must not be called after `init()`, and must not be called twice.
 *
 * @param [in] str a string containing configuration data in JSON format
 *
 * @return status
 */
esdm_status esdm_load_config_str(const char *str);

/**
 * Initialize ESDM:
 *	- allocate data structures for ESDM
 *	- allocate memory for node local caches
 *	- initialize submodules
 *	- initialize threadpool
 *
 * @return status
 */

esdm_status esdm_init();

/**
 * Display status information for objects stored in ESDM.
 *
 * @return status
 */

esdm_status esdm_finalize();

/**
 * Write data with a given size and offset.
 *
 * @param [in] dataset TODO, currently a stub, we assume it has been identified/created before...., json description?
 * @param [in] buf the pointer to a contiguous memory region that shall be written to permanent storage
 * @param [in] subspace an existing dataspace that describes the shape and location of the hypercube that is to be written
 *
 * @return status
 */

esdm_status esdm_write(esdm_dataset_t *dataset, void *buf, esdm_dataspace_t *subspace);

/**
 * Reads a data fragment described by desc to the dataset dset.
 *
 * @param [in] dataset TODO, currently a stub, we assume it has been identified/created before.... , json description?
 * @param [out] buf a contiguous memory region that shall be filled with the data from permanent storage
 * @param [in] subspace an existing dataspace that describes the shape and location of the hypercube that is to be read
 *
 * @return status
 */

esdm_status esdm_read(esdm_dataset_t *dataset, void *buf, esdm_dataspace_t *subspace);

///////////////////////////////////////////////////////////////////////////////
// Public API: Data Model Manipulators ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Container //////////////////////////////////////////////////////////////////

/**
 * Create a new container.
 *
 *  - Allocate process local memory structures.
 *  - Register with metadata service.
 *
 * @param [in] name string to identify the container, must not be empty
 * @param [out] out_container returns a pointer to the new container
 *
 * @return status
 *
 */

esdm_status esdm_container_create(const char *name, esdm_container_t **out_container);

/**
 * Open an existing container.
 *
 *  - Allocate process local memory structures.
 *  - Register with metadata service.
 *
 * @param [in] name string to identify the container, must not be empty
 * @param [out] out_container returns a pointer to the container
 *
 * @return status
 */
esdm_status esdm_container_open(const char *name, esdm_container_t **out_container);

/**
 * Make container persistent to storage.
 * Enqueue for writing to backends.
 *
 * Calling container commit may trigger subsequent commits for datasets that
 * are part of the container.
 *
 * @param [in] container pointer to an existing container which is to be committed to storage
 *
 * @return status
 *
 */

esdm_status esdm_container_commit(esdm_container_t *container);


esdm_status esdm_container_link_attribute(esdm_container_t *container, smd_attr_t *attr);

/* This function returns the attributes */
esdm_status esdm_container_get_attributes(esdm_container_t *container, smd_attr_t **out_metadata);

/**
 * Destruct and free a container object.
 *
 * @param [in] container an existing container object that is no longer needed
 *
 * "_destroy" sounds too destructive, this will be renamed to esdm_container_close().
 */

esdm_status esdm_container_destroy(esdm_container_t *container);

/*
 * Check if the dataset with the given name exists.
 *
 * @param [in] container an existing container to query
 * @param [in] name the identifier to check, must not be NULL
 *
 * @return true if the identifier already exists within the container
 */
bool esdm_container_dataset_exists(esdm_container_t * container, char const * name);

// Dataset

/**
 * Create a new dataset.
 *
 *  - Allocate process local memory structures.
 *	- Register with metadata service.
 *
 * @param [in] container pointer to an existing container to which the new dataset will be linked
 * @param [in] name identifier for the new dataset, must not be empty
 * @param [in] dataspace pointer to an existing dataspace which defines the shape of the data that will be stored within the dataset
 * @param [out] out_dataset returns a pointer to the new dataset
 *
 * @return status
 *
 */

esdm_status esdm_dataset_create(esdm_container_t *container, const char *name, esdm_dataspace_t *dataspace, esdm_dataset_t **out_dataset);

esdm_status esdm_dataset_name_dims(esdm_dataset_t *dataset, char **names);

esdm_status esdm_dataset_get_name_dims(esdm_dataset_t *dataset, char const *const **out_names);

esdm_status esdm_dataset_get_dataspace(esdm_dataset_t *dset, esdm_dataspace_t **out_dataspace);

esdm_status esdm_dataset_iterator(esdm_container_t *container, esdm_dataset_iterator_t **out_iter);

/**
 * Open a dataset.
 *
 *  - Allocate process local memory structures
 *  - Retrieve metadata
 *
 * @param [in] container pointer to an open container that contains the dataset that is to be opened
 * @param [in] name identifier of the dataset within the container, must not be empty
 * @param [out] out_dataset returns a pointer to the opened dataset
 *
 * @return status
 */
esdm_status esdm_dataset_open(esdm_container_t *container, const char *name, esdm_dataset_t **out_dataset);

/**
 * Make dataset persistent to storage.
 * Schedule for writing to backends.
 *
 * @param [in] dataset pointer to an existing dataset which is to be committed to storage
 *
 * @return status
 */

esdm_status esdm_dataset_commit(esdm_dataset_t *dataset);

/**
 * Destruct and free a dataset object.
 *
 * @param [in] dataset an existing dataset object that is no longer needed
 *
 * @return status
 *
 * "_destroy" sounds too destructive, this will be renamed to esdm_dataset_close().
 */
esdm_status esdm_dataset_destroy(esdm_dataset_t *dataset);

/* This function adds the metadata to the ESDM */

esdm_status esdm_dataset_link_attribute(esdm_dataset_t *dset, smd_attr_t *attr);

/* This function returns the attributes */
esdm_status esdm_dataset_get_attributes(esdm_dataset_t *dataset, smd_attr_t **out_metadata);

// Dataspace

/**
 * Create a new dataspace.
 *
 *  - Allocate process local memory structures.
 *
 * @param [in] dims count of dimensions of the new dataspace
 * @param [in] sizes array of the sizes of the different dimensions, the length of this array is dims. Must not be `NULL` unless `dims == 0`
 * @param [in] type the datatype for each data point
 * @param [out] out_dataspace pointer to the new dataspace
 *
 * @return status
 *
 */

esdm_status esdm_dataspace_create(int64_t dims, int64_t *sizes, esdm_type_t type, esdm_dataspace_t **out_dataspace);

/**
 * Reinstantiate dataspace from serialization.
 */

esdm_status esdm_dataspace_deserialize(void *serialized_dataspace, esdm_dataspace_t **out_dataspace);

/**
 * Define a dataspace that is a subset of the given dataspace.
 *
 * - Allocates process local memory structures.
 *
 * @param [in] dataspace an existing dataspace that encloses the subspace
 * @param [in] dims length of the `size` and `offset` arguments, must be equal to the number of dimensions of the given `dataspace`
 * @param [in] size size of the hypercube of data within the subspace
 * @param [in] offset location of the first data point within the subspace
 * @param [out] out_dataspace pointer to the new sub-dataspace
 *
 * @return `ESDM_SUCCESS` on success, `ESDM_INVALID_ARGUMENT_ERROR` if the provided `dims`, `size`, or `offset` arguments do not agree with the provided `dataspace`
 */
esdm_status esdm_dataspace_subspace(esdm_dataspace_t *dataspace, int64_t dims, int64_t *size, int64_t *offset, esdm_dataspace_t **out_dataspace);

/**
 * Destruct and free a dataspace object.
 *
 * @param [in] dataspace an existing dataspace object that is no longer needed
 *
 * @return status
 *
 * "_destroy" sounds too destructive, this will be renamed to esdm_dataspace_close().
 */
esdm_status esdm_dataspace_destroy(esdm_dataspace_t *dataspace);

/**
 * Serializes dataspace description.
 *
 * e.g., to store along with fragment
 */

esdm_status esdm_dataspace_serialize(esdm_dataspace_t *dataspace, void **out);

uint64_t esdm_dataspace_element_count(esdm_dataspace_t *dataspace);

uint64_t esdm_dataspace_size(esdm_dataspace_t *dataspace);


// Fragment

/**
 * Reinstantiate fragment from serialization.
 */

esdm_status esdm_fragment_deserialize(void *serialized_fragment, esdm_fragment_t **_out_fragment);

esdm_status esdm_fragment_retrieve(esdm_fragment_t *fragment);

/**
 * Make fragment persistent to storage.
 * Schedule for writing to backends.
 *
 * @param [in] fragment pointer to an existing fragment which is to be committed to storage
 *
 * @return status
 */

esdm_status esdm_fragment_commit(esdm_fragment_t *fragment);

/**
 * Destruct and free a fragment object.
 *
 * @param [in] fragment an existing fragment object that is no longer needed
 *
 * @return status
 *
 * "_destroy" sounds too destructive, this will be renamed to esdm_fragment_close().
 */
esdm_status esdm_fragment_destroy(esdm_fragment_t *fragment);

/**
 * Serializes fragment for storage.
 *
 * @startuml{fragment_serialization.png}
 *
 * User -> Fragment: serialize()
 *
 * Fragment -> Dataspace: serialize()
 * Fragment <- Dataspace: (status, string)
 *
 * User <- Fragment: (status, string)
 *
 * @enduml
 *
 */


void esdm_fragment_print(esdm_fragment_t *fragment);

void esdm_dataspace_print(esdm_dataspace_t *dataspace);

//size_t esdm_sizeof(esdm_type_t type);
#define esdm_sizeof(type) (type->size)

/**
  * Initialize backend by invoking mkfs callback for matching target
  *
  * @param [in] enforce_format  force reformatting existing system (may result in data loss)
  * @param [in] target  target descriptor
  *
  * @return status
  */

enum esdm_format_flags{
  ESDM_FORMAT_DELETE = 1,
  ESDM_FORMAT_CREATE = 2,
  ESDM_FORMAT_IGNORE_ERRORS = 4,
  ESDM_FORMAT_PURGE_RECREATE = 7
};

esdm_status esdm_mkfs(int format_flags, data_accessibility_t target);

//// LOGGING

/*
Loglevel for stdout.
*/
void esdm_loglevel(esdm_loglevel_e loglevel);
void esdm_log_on_exit(int on);
/*
 Keeps a log to record last messages for crashes
 Must be called from a single master thread
 NOTE: logging into the shared buffer costs performance.
*/
void esdm_loglevel_buffer(esdm_loglevel_e loglevel);


#endif
