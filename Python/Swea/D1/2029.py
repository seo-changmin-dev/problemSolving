import sys


sys.stdin = open("./datas/input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    a, b = map(int, input().split())
    print("#{} {} {}".format(tc, a//b, a%b))
