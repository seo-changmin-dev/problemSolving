import sys

sys.stdin = open("./datas/sample_input.txt")
T = int(input())
for tc in range(1, T+1):
    N, M = map(int, input().split())

    prefix_sum = [0]
    for e in map(int, input().split()):
        prefix_sum.append(e)

    for i in range(1, N+1):
        prefix_sum[i] += prefix_sum[i-1]

    min_diff = 987654321
    max_diff = -987654321

    for i in range(0, N-M+1):
        diff = prefix_sum[i + M] - prefix_sum[i]
        min_diff = min(min_diff, diff)
        max_diff = max(max_diff, diff)

    print(f"#{tc} {max_diff - min_diff}")
