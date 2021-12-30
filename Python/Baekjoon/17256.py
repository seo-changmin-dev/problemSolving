# 17256
import sys


class CakeNumber:
    x: int = None
    y: int = None
    z: int = None


def OperationCake(a: CakeNumber, b: CakeNumber):
    return a.z + b.x, a.y * b.y, a.x + b.z


def InverseOperationCake(a: CakeNumber, c: CakeNumber):
    return c.x - a.z, int(c.y / a.y), c.z - a.x


a = CakeNumber()
c = CakeNumber()
a.x, a.y, a.z = map(int, sys.stdin.readline().split())
c.x, c.y, c.z = map(int, sys.stdin.readline().split())

for e in InverseOperationCake(a, c):
    print(e, end=" ")
