// This file is part of h5-memvol.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with h5-memvol.  If not, see <http://www.gnu.org/licenses/>.

#include <assert.h>
#include <hdf5.h>
#include <stdio.h>

#define FILE "file-test.h5"

int main() {
  hid_t fprop;
  hid_t vol_id = H5VLregister_by_name("h5-esdm");

  herr_t status;
  hid_t file_id;

  char name[1024];

  // SET VOL PLUGIN /////////////////////////////////////////////////////////
  fprop = H5Pcreate(H5P_FILE_ACCESS);
  H5Pset_vol(fprop, vol_id, &fprop);

  // TODO
  // MOCK SETUP /////////////////////////////////////////////////////////////
  // MOCK CLEANUP ///////////////////////////////////////////////////////////

  // CREATE /////////////////////////////////////////////////////////////////
  // OPEN ///////////////////////////////////////////////////////////////////
  // CLOSE //////////////////////////////////////////////////////////////////
  // READ ///////////////////////////////////////////////////////////////////
  // WRITE //////////////////////////////////////////////////////////////////
  // GET ////////////////////////////////////////////////////////////////////
  // SPECIFIC ///////////////////////////////////////////////////////////////
  // OPTIONAL ///////////////////////////////////////////////////////////////

  // Clean up ///////////////////////////////////////////////////////////////
  H5VLunregister(vol_id);

  return 0;
}
