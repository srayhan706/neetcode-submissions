class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        vis = set()

        def dfs(i, j):
            if (
                i < 0 or i >= row or
                j < 0 or j >= col or
                grid[i][j] == 0 or
                (i, j) in vis
            ):
                return 0

            vis.add((i, j))
            area = 1
            area += dfs(i + 1, j)
            area += dfs(i - 1, j)
            area += dfs(i, j + 1)
            area += dfs(i, j - 1)
            return area

        ans = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1 and (i, j) not in vis:
                    ans = max(ans, dfs(i, j))

        return ans
