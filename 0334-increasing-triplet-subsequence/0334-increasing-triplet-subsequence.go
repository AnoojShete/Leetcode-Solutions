import "math"

func increasingTriplet(nums []int) bool {
    first, second := math.MaxInt, math.MaxInt
    for _, num := range(nums) {
        if num <= first {
            first = num
        } else if num <= second {
            second = num
        } else {
            return true
        }
    }
    return false
}