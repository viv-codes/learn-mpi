#include "mpi.h"

MPI_Info myinfo;
MPI_File myfile;
MPI_Comm mycomm;

MPI_Info_create(&myinfo);
MPI_Info_set(myinfo, "access_style", "read_once,sequential");
MPI_File_open(mycomm, "myfile", MPI_MODE_RDONLY, myinfo, &myfile);
MPI_Info_free(&myinfo);

int MPI_Ibcast(void* buffer, int count, MPI_datatype database, int root, MPI_Comm comm, MPI_Request *request)

	MPI_Comm comm[5] = {c_my, c_north, c_south, c_east, c_west};
	MPI_Request rq[5];
	for (i=0; i < 5; ++i {
		MPI_Iscatter(sbf[i], ct, dt, rbf[i], ct, dt, 0, comm[i], &rq[i]);
	}
	MPI_Waitall(5, rq, MPI_STATUSES_IGNORE);
