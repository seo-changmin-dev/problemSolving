# 20254
import sys


def WeightedScore(Ur, Tr, Uo, To, scores):
    ret = Ur * scores[0] + Tr * scores[1] + Uo * scores[2] + To * scores[3]
    return ret


scores = list(map(int, sys.stdin.readline().split()))
print(WeightedScore(56, 24, 14, 6, scores))
