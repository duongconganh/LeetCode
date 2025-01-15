class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt = bin(num2).count('1')  # Count set bits in num2
        min_xor = 0

        # Set higher bits of num1 in min_xor
        for i in range(31, -1, -1):
            if cnt <= 0:
                break
            if (num1 & (1 << i)) != 0:
                min_xor |= (1 << i)
                cnt -= 1

        # Set remaining bits in min_xor with minimal impact
        for i in range(32):
            if cnt <= 0:
                break
            if (min_xor & (1 << i)) == 0:
                min_xor |= (1 << i)
                cnt -= 1

        return min_xor