import sys

sys.stdin = open("./datas/input.txt", 'r')


def is_palindrome(x: str) -> bool:
    for i in range(len(x)//2):
        if x[i] != x[-(i+1)]: return False

    return True


for tc in range(int(input())):
    print("#{} {}".format(tc+1, int(is_palindrome(input()))))
