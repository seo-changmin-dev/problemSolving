# 7567
import sys
a = sys.stdin.readline().rstrip()


base = ret = 0
for _ in a:
    if _ == base:
        ret += 5
    else:
        ret += 10
        base = _

print(ret)