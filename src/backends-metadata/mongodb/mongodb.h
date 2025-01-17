/* This file is part of ESDM.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with ESDM.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MONGODB_H
#define MONGODB_H

#include <esdm.h>

// Internal functions used by this backend.
typedef struct {
  const char *type;
  const char *name;
  const char *target;

  mongoc_client_t *client;
  mongoc_database_t *database;
  mongoc_collection_t *collection;

} mongodb_backend_options_t;

// Internal functions used by this backend.
typedef struct {
  mongodb_backend_options_t *options;
  int other;

  mongoc_client_t *client;
  mongoc_database_t *database;
  mongoc_collection_t *collection;
} mongodb_backend_data_t;

// forward declarations

static void mongodb_test();

static void log(const char *format, ...);

static int mkfs(esdm_backend_t *backend);

/**
 * Similar to the command line counterpart fsck for ESDM plugins is responsible
 * to check and potentially repair the "filesystem".
 *
 */

static int fsck();

static int entry_create(const char *path);

static int entry_retrieve(const char *path);

static int entry_update(const char *path, void *buf, size_t len);

static int entry_destroy(const char *path);

static int container_create(esdm_backend_t *backend, esdm_container_t *container);

static int container_retrieve(esdm_backend_t *backend, esdm_container_t *container);

static int container_update(esdm_backend_t *backend, esdm_container_t *container);

static int container_destroy(esdm_backend_t *backend, esdm_container_t *container);

static int dataset_create(esdm_backend_t *backend, esdm_dataset_t *dataset);

static int dataset_retrieve(esdm_backend_t *backend, esdm_dataset_t *dataset);

static int dataset_update(esdm_backend_t *backend, esdm_dataset_t *dataset);

static int dataset_destroy(esdm_backend_t *backend, esdm_dataset_t *dataset);

static int fragment_update(esdm_backend_t *backend, esdm_fragment_t *fragment);

static int mongodb_backend_performance_estimate(esdm_backend_t *backend);

static int mongodb_create(esdm_backend_t *backend, char *name);

static int mongodb_open(esdm_backend_t *backend);

static int mongodb_write(esdm_backend_t *backend);

static int mongodb_read(esdm_backend_t *backend);

static int mongodb_close(esdm_backend_t *backend);

static int mongodb_allocate(esdm_backend_t *backend);

static int mongodb_update(esdm_backend_t *backend);

static int mongodb_lookup(esdm_backend_t *backend);

/**
* Initializes the POSIX plugin. In particular this involves:
*
*	* Load configuration of this backend
*	* Load and potentially calibrate performance model
*
*	* Connect with support services e.g. for technical metadata
*	* Setup directory structures used by this POSIX specific backend
*
*	* Populate esdm_backend_t struct and callbacks required for registration
*
* @return pointer to backend struct
*/

esdm_backend_t *mongodb_backend_init(esdm_config_backend_t *config);

/**
* Initializes the POSIX plugin. In particular this involves:
*
*/

int mongodb_finalize();

static void mongodb_test();

#endif
