import sys

sys.stdin = open("./datas/input.txt")


def is_valid(board: list) -> bool:
    # check row
    for i in range(0, 81, 9):
        row = set([board[i + k] for k in range(9)])
        if len(row) != 9:
            return False

    # check col
    for j in range(0, 9):
        col = set([board[j + 9 * k] for k in range(9)])
        if len(col) != 9:
            return False

    # check box
    box_idx = [0, 1, 2, 9, 10, 11, 18, 19, 20];
    for k in range(3):
        for l in range(3):
            box = set([board[i + 3 * l + 27 * k] for i in box_idx])
            if len(box) != 9:
                return False

    return True


if __name__ == "__main__":
    T = int(input())
    for tc in range(1, T + 1):
        board = []
        for _ in range(9):
            board += list(map(int, input().split()))

        ret = int(is_valid(board))
        print(f"#{tc} {ret}")
