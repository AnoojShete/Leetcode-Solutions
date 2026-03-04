func twoSum(nums []int, target int) []int {
    mpp := make(map[int]int)
    for i, num := range nums {
        comp := target - num
        idx, ok := mpp[comp]
        if ok {
            return []int{idx, i}
        }
        mpp[num] = i
    }
    return []int{-1, -1}
}