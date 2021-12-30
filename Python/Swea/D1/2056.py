import sys

sys.stdin = open("./datas/input.txt", 'r')

# -1 is a placeholder for indexing purposes.
_DAYS_IN_MONTH = [-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def is_valid(date: str) -> bool:
    if int(date[4:6]) not in range(1, 12+1):
        return False
    if int(date[6:]) not in range(1, _DAYS_IN_MONTH[int(date[4:6])] + 1):
        return False
    return True


T = int(input())
for tc in range(1, T + 1):
    date = input()
    if is_valid(date):
        print("#{} {}/{}/{}".format(tc, date[:4], date[4:6], date[6:]))
    else:
        print("#{} {}".format(tc, -1))
