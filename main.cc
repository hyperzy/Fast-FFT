//
// Created by himalaya on 12/9/18.
//

#include <iostream>
#include "complex.h"
#include "input_image.h"
#include <mpi.h>
#define DBG 1

using namespace std;

int main(int argc, char **argv) {
	int rank, size, rc;
	rc = MPI_Init(&argc, &argv);
	if (rc != MPI_SUCCESS)
	{
		cerr << "mpi initialization error" << endl;
		MPI_Finalize();
		return 1;
	}
	if (argc != 2)
	{
		cerr << "unexpected arguments" << endl;
		MPI_Finalize();
		return 1;
	}
	int width, height;				// the length of discrete sequence
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0)
	{
		InputImage in(argv[1]);
#if DBG
		cout << "width is " << in.get_width() << " and height is" << in.get_height() << endl;
#endif
		width = in.get_width();
		height = in.get_height();

	}
	MPI_Bcast(&width, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&height, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
#if DBG
	cout << "rank " << rank << ": width is " << width << " and height is " << height << endl;
#endif

	MPI_Finalize();

	return 0;
}