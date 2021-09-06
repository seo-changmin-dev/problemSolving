import sys

sys.stdin = open("./datas/input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    P, Q, R, S, W = map(int, input().split())

    payment_A = P*W
    payment_B = Q + (0 if W <= R else (W-R)*S)

    print("#{} {}".format(tc, min(payment_A, payment_B)))
