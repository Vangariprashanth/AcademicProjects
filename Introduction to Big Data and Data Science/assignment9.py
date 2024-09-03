from mpi4py import MPI
import math


##  Function to check if a number is prime
def is_prm(nm):
    if nm <= 1:
        return False
    if nm == 2:
        return True
    if nm % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(nm)) + 1, 2):
        if nm % i == 0:
            return False
    return True


# Find the maximum prime number within an interval
def fnd_mx_prme(st, ed):
    mx = 0
    for num in range(st, ed + 1):
        if is_prm(num) and num > mx:
            mx = num
    return mx

# Main function to distribute workload, gather results, and print maximum prime numbers
def main(st_range, en_range):
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    for N in range(st_range, en_range + 1):
        intrvl_sze = N // size
        st = rank * intrvl_sze + 1
        ed = st + intrvl_sze - 1
        if rank == size - 1:

            ed = N

        lcl_mx = fnd_mx_prme(st, ed)

        all_mx = comm.gather(lcl_mx, root=0)

        if rank == 0:

            mx_prime = max(all_mx)

            print("For N =", N, ", Maximum prime number found:", mx_prime)

if __name__ == "__main__":
    s = 1
    e = [100,100,1000]
    for end in e:
      print(f"___For Range 1, {end} _____")
      main(s, end)
      

