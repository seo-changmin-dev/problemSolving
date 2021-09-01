import sys

sys.stdin = open("./datas/input.txt", 'r')


coef = [0.35, 0.45, 0.20]
grade = ["A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"]


def get_score(a: int, b: int, c: int) -> float:
    return a*coef[0] + b*coef[1] + c*coef[2]


for tc in range(int(input())):
    N, K = map(int, input().split())

    score = [0]*N
    for i in range(N):
        a, b, c = map(int, input().split())
        score[i] = get_score(a, b, c)

    s = score[K-1]
    score.sort(reverse=True)
    rank = score.index(s)

    print("#{} {}".format(tc+1, grade[rank//(N//10)]))
