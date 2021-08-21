# import sys
# sys.stdin = open("./datas/input.txt", "r")
T = int(input())

for tc in range(1, T+1):
    ret = 0
    nums = list(map(int, input().split()))
    for e in nums:
        if e % 2 == 1:
            ret += e
    print("#{} {}".format(tc, ret))