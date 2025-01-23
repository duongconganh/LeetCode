class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        rows = [False] * m
        for r in range(m):
            count = sum(grid[r])
            if count > 1:
                res += count
                rows[r] = True
        for c in range(n):
            total = counted = 0
            for r in range(m):
                if grid[r][c]:
                    total += 1
                    if rows[r]:
                        counted += 1
            if total > 1:
                res += total - counted
        return res