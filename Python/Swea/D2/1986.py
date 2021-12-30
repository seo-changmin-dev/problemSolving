import sys

sys.stdin = open("./datas/input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    ret = ((N+1)//2) * (1 if (N&1) else -1)
    print(f"#{tc} {ret}")