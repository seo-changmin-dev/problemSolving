# import sys
#
# sys.stdin = open("./datas/input.txt", 'r')

for _ in range(int(input())):
    tc = int(input())
    a = [0 for _ in range(101)]
    for e in map(int, input().split()):
        a[e] += 1

    ret = 100
    for i in range(100, -1, -1):
        if a[i] > a[ret]:
            ret = i

    print(f"#{tc} {ret}")
