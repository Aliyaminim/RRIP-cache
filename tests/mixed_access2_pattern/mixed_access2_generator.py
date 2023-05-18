import random

size = int(input("Input cache size: "))
k = int(input("Input length of working set(less than cache size): "))
N = int(input("Input number of burst repeats: "))
A = int(input("Input number of working set repeats: "))
m = int(input("Input length of random set: "))
list = []

for i in range(N):
    for counter in range(A):
        for j in range(1, k + 1):
            list.append(j)

    for j in range(m):
        list.append(random.randint(k+1, m + k))

list_str = [str(i) for i in list]

with open("ma2_test.in", "w") as f:
    f.write(str(size) + " " + str((k*A + m)*N) + " ")
    f.write(" ".join(list_str))
