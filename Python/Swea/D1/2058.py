import sys

sys.stdin = open('./datas/input.txt', 'r')

arr = list(map(int, list(input())))
print(sum(arr))
