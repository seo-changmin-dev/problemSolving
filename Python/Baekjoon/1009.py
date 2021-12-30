# 1009
import sys
T = int(sys.stdin.readline())
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())

    ret = pow(a, b, 10)
    if ret: print(ret)
    else: print(10)