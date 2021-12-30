from decimal import Decimal, ROUND_HALF_UP
import sys
sys.stdin = open("./datas/input.txt", 'r')


T = int(input())
for tc in range(1, T+1):
    numbers = list(map(int, input().split()))
    ret = 0
    for e in numbers:
        ret += e

    print("#{} {}".format(tc, Decimal(ret/10).quantize(Decimal('0'), ROUND_HALF_UP)))