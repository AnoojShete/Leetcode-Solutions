import "math"

func minimumDistance(nums []int) int {
    mpp := make(map[int][]int)
    for i, v := range(nums) {
        mpp[v] = append(mpp[v], i)
    }
    ans := math.MaxInt
    for _, idx := range(mpp) {
        if len(idx) < 3 { continue }
        for i := 0; i + 2 < len(idx); i++ {
            dist := 2 * (idx[i+2] - idx[i])
            if dist < ans {
                ans = dist
            }
        }
    }
    if ans == math.MaxInt { return -1 }
    return ans
}