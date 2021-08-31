import sys

sys.stdin = open("./datas/input.txt", 'r')
for tc in range(int(input())):
    a = list(map(int, input().split()))

    minute = a[1] + a[3]
    carry = minute//60
    minute %= 60

    hour = a[0] + a[2] + carry
    hour %= 12
    if hour == 0:
        hour = 12
    print(f"#{tc+1} {hour} {minute}")