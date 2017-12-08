// This file is part of h5-memvol.
//
// This program is is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with h5-memvol.  If not, see <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <hdf5.h>

#define FILE "file-test.h5"

int main()
{
	herr_t	status;
	hid_t fprop;
	hid_t vol_id = H5VLregister_by_name("h5-esdm");

	hid_t       file_id, dataset_id, dataspace_id;  /* identifiers */
	hsize_t     dims[2];

	char name[1024];


	// SET VOL PLUGIN /////////////////////////////////////////////////////////
	fprop = H5Pcreate(H5P_FILE_ACCESS);
	H5Pset_vol(fprop, vol_id, &fprop);


	// MOCK SETUP /////////////////////////////////////////////////////////////
	/* Create a new file using default properties. */
	file_id = H5Fcreate(FILE, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

	/* Create the data space for the dataset. */
	dims[0] = 4; 
	dims[1] = 6; 
	dataspace_id = H5Screate_simple(2, dims, NULL);

	// CREATE /////////////////////////////////////////////////////////////////
	/* Create the dataset. */
	dataset_id = H5Dcreate2(file_id, "/dset", H5T_STD_I32BE, dataspace_id, 
			H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

	// CLOSE //////////////////////////////////////////////////////////////////
	/* End access to the dataset and release resources used by it. */
	status = H5Dclose(dataset_id);



	// OPEN ///////////////////////////////////////////////////////////////////
	// READ ///////////////////////////////////////////////////////////////////
	// WRITE //////////////////////////////////////////////////////////////////
	// GET ////////////////////////////////////////////////////////////////////
	// SPECIFIC ///////////////////////////////////////////////////////////////
	// OPTIONAL ///////////////////////////////////////////////////////////////



	// MOCK CLEANUP ///////////////////////////////////////////////////////////
	/* Terminate access to the data space. */ 
	status = H5Sclose(dataspace_id);

	/* Close the file. */
	status = H5Fclose(file_id);


	// Clean up ///////////////////////////////////////////////////////////////
	H5VLunregister(vol_id);

	return 0;
}
