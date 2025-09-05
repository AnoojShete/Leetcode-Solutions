class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        k = 1
        while True:
            x = num1 - k * num2
            if x < k:
                return -1
            if k >= x.bit_count():
                return k
            k += 1
        return -1