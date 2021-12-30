# import sys
#
# sys.stdin = open("./datas/sample_input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    K, N, M = map(int, input().split())

    a = list(0 for _ in range(N+1))
    for e in map(int, input().split()):
        a[e] = 1

    cnt = 0
    pos = 0
    while True:
        if pos + K >= N: break
        if 1 not in a[pos+1:pos+K+1]: cnt = 0; break

        cnt += 1
        for i in range(pos+K, pos, -1):
            if a[i] == 1: pos = i; break

    print(f"#{tc} {cnt}")