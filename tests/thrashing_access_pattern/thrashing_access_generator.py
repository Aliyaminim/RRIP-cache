import random

size = int(input("Input cache size: "))
k = int(input("Input length of working set(less than cache size): "))
N = int(input("Input number of burst repeats: "))
list = []

for i in range(N):
    for j in range(1, k + 1):
        list.append(j)

list_str = [str(i) for i in list]

<<<<<<< HEAD
with open("ta_test6.in", "w") as f:
=======
with open("ta_test.in", "w") as f:
>>>>>>> parent of 8cded9a (Tests are done)
    f.write(str(size) + " " + str(k*N) + " ")
    f.write(" ".join(list_str))


