import random

size = int(input("Введите размер кэша: "))
n = int(input("Введите количество запросов: "))
N = int(input("Введите количество повторений: "))
k = int(input("Введите длину рабочего набора(меньше размера кэша): "))
m = n - k
list = []

for i in range(N):
    for j in range(1, k + 1):
        list.append(j)
    for j in range (k, 0, -1):
        list.append(j)
    for j in range(m):
        list.append(random.randint(1, m))

print('Итоговый тест:',list)




