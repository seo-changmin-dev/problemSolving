import sys

sys.stdin = open("datas/input.txt")

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    arr = map(int, input().split())

    print("#{}".format(tc), *sorted(arr))