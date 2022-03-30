#include "mpi.h"

MPI_Info myinfo;
MPI_File myfile;
MPI_Comm mycomm;

MPI_Info_create(&myinfo);
MPI_Info_set(myinfo, "access_style", "read_once,sequential");
MPI_File_open(mycomm, "myfile", MPI_MODE_RDONLY, myinfo, &myfile);
MPI_Info_free(&myinfo);
