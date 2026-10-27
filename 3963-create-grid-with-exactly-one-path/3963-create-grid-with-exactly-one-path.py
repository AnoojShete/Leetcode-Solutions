class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = [("." + "#"*(n-1)) for i in range(m-1)]
        ans.append("."*n)
        return ans