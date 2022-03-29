from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

# Nonblocking communications allow for computation and communications at the same time, which can make operations more efficient

if rank == 0:
    data = {'a': 7, 'b': 3.14}
    req = comm.isend(data, dest=1, tag=11)
    req.wait()
elif rank == 1:
    req = comm.irecv(source=0, tag=11)
    data = req.wait()
    print(data)