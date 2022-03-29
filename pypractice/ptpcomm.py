from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

# Simple program that uses ptp blocking communications between nodes

if rank == 0:
    data = {'a':7, 'b':3.14}
    comm.send(data, dest=1, tag=11) # The tag part here isn't necessary
elif rank == 1:
    data = comm.recv(source=0, tag=11)
    print(data)
    print("Sending data to next node!")
    comm.send(data, dest=2, tag=13)

# You can add new nodes super easily and send data between them
elif rank == 2:
    data = comm.recv(source=1, tag=13)
    print(data)
    print("data recieved at final node")
