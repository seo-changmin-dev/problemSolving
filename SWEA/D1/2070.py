# import sys
#
# sys.stdin = open('./datas/input.txt')


def compare_int(a: int, b: int) -> str:
    if a > b:
        return '>'
    elif a < b:
        return '<'
    else:
        return '='


T = int(input())
for tc in range(1, T+1):
    a, b = map(int, input().split())
    print("#{} {}".format(tc, compare_int(a, b)))
