import sys

sys.stdin = open('./datas/input.txt', 'r')


T = int(input())
for tc in range(1, T+1):
    arr = list(map(int, input().split()))
    print(f"#{tc} {max(arr)}")
