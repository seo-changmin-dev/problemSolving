# 2476
import sys


def prize(a, b, c):
    if a == b == c:
        return 10000 + a * 1000
    elif a == b or a == c:
        return 1000 + a * 100
    elif b == c:
        return 1000 + b * 100
    else:
        return max(a, b, c) * 100


N = int(sys.stdin.readline())
ret = -1
for _ in range(N):
    a, b, c = map(int, sys.stdin.readline().split())
    ret = max(ret, prize(a, b, c))

print(ret)