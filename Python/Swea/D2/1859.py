import sys

sys.stdin = open("./datas/input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    a = list(map(int, input().split()))

    ret = 0

    curr = a[N-1]
    for e in reversed(a):
        if e >= curr: curr = e
        else: ret += curr-e

    print(f"#{tc} {ret}")
