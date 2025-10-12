class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        
        n = len(nums)
        C = [[0]*60 for _ in range(60)]
        mod = int(1e9 + 7)
        for i in range(51):
            for j in range(i + 1):
                if j == 0:
                    C[i][j] = 1
                else:
                    C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod
        
        @lru_cache(None)
        def dfs(i: int, carry: int, r: int, rk: int) -> int:
            if rk < 0:
                return 0
            if i == 60:
                return 1 if carry == 0 and rk == 0 else 0
            res = 0
            if i < n:
                for j in range(r + 1):
                    mul = pow(nums[i], j, mod) * C[r][j] % mod
                    res = (res + dfs(i + 1, (carry + j)>>1, r - j, rk - ((carry + j)&1)) * mul % mod) % mod
            else:
                if r == 0:
                    res = (res + dfs(i + 1, carry>>1, r, rk - (carry&1))) % mod
            return res
        
        ans = dfs(0, 0, m, k)
        dfs.cache_clear()
        return ans