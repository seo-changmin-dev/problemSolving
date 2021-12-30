# 1972
import sys


def D_surprising(input_str, n):
    temp_dict = {}
    for i in range(0, len(input_str) - 1 - n):
        composed_str = input_str[i] + input_str[i + n + 1]
        if composed_str in temp_dict:
            return False
        else:
            temp_dict[composed_str] = 1

    return True


def is_surprising(input_str):
    for i in range(len(input_str) - 1):
        if not D_surprising(input_str, i):
            return False

    return True


while True:
    input_str = sys.stdin.readline().rstrip()

    if input_str == '*':
        exit()

    if is_surprising(input_str):
        print(f"{input_str} is surprising.")
    else:
        print(f"{input_str} is NOT surprising.")