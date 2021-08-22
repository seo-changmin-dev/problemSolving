import sys

sys.stdin = open('./datas/input.txt', 'r')

N = int(input())
arr = list(map(int, input().split()))
print(sorted(arr)[N // 2])
