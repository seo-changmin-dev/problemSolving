import sys

sys.stdin = open("datas/input.txt")

divisor = [50000, 10000, 5000, 1000, 500, 100, 50, 10]
T = int(input())
for tc in range(1, T+1):
    print("#{}".format(tc))

    ret = int(input())
    for div in divisor:
        print(ret//div, end=" ")
        ret %= div
    print()
