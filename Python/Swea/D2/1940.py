import sys


sys.stdin = open("./datas/input.txt", 'r')


class Car:
    def __init__(self, speed: int = 0):
        self.speed = speed

    def acceleration(self, dirr: int, change: int = 0):
        if dirr == 1: self.speed += change
        elif dirr == 2: self.speed -= change

        if self.speed < 0: self.speed = 0
        return

    def get_speed(self):
        return self.speed


for tc in range(int(input())):
    car = Car()
    ret = 0
    for _ in range(int(input())):
        a = list(map(int, input().split()))
        a.append(0)

        car.acceleration(a[0], a[1])
        ret += car.get_speed()

    print("#{} {}".format(tc+1, ret))
