import sys

sys.stdin = open("./datas/input.txt", 'r')

stk = []
local_max = []

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    a = list(map(int, input().split()))
    stk.append(a[0])

    for i in range(N):
        if stk[-1] > a[i]:
            local_max.append((stk[-1], i-1))
        stk.append(a[i])
    local_max.append((a[N-1], N-1))

    local_max.sort(reverse=True)

    ans = 0
    curr = 0
    for e in local_max:
        if curr >= e[1]: continue

        for i in range(curr, e[1]):
            if e[0] > a[i]:
                ans += e[0] - a[i]
        curr = e[1]

    print(f"#{tc} {ans}")
    stk.clear()
    local_max.clear()
