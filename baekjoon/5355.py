# 5355
import sys


def calc(num, op):
    if op == '@':
        return num * 3
    elif op == '%':
        return num + 5
    elif op == '#':
        return num - 7
    else:
        return num


tc = int(sys.stdin.readline())

for _ in range(tc):
    line = sys.stdin.readline().split()
    ret = float(line[0])

    for i in range(1, len(line)):
        ret = calc(ret, line[i])

    print(f"{ret:.2f}")