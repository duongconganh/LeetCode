class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)

        # Check if the target is achievable
        if (total - target) % 2 != 0 or total < target:
            return 0

        subset_sum = (total - target) // 2

        # DP array for 1D DP
        dp = [0] * (subset_sum + 1)
        dp[0] = 1  # There's one way to make sum 0 (by choosing no elements)

        for num in nums:
            for j in range(subset_sum, num - 1, -1):
                dp[j] += dp[j - num]

        return dp[subset_sum]