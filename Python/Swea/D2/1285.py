import sys

sys.stdin = open("./datas/input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    arr = list(map(lambda x: abs(int(x)), input().split()))

    min_val = min(arr)
    cnt = arr.count(min_val)

    print("#{} {} {}".format(tc, min_val, cnt))
