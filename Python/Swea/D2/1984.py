import sys
from decimal import Decimal, ROUND_HALF_UP

sys.stdin = open("./datas/input.txt", 'r')
for tc in range(int(input())):
    arr = list(map(int, input().split()))
    min_val, max_val = min(arr), max(arr)

    ret = 0
    for e in arr:
        if e != min_val and e != max_val:
            ret += e

    print(f"#{tc+1} {Decimal(ret/8).quantize(Decimal(0), rounding=ROUND_HALF_UP)}")
