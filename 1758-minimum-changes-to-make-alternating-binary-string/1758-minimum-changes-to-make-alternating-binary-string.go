import "math"

func minOperations(s string) int {
    count0, count1 := 0, 0
    for i, ch := range s {
        if i % 2 == 0 {
            if ch == '0' {count1++} else {count0++}
        } else {
            if ch == '1' {count1++} else {count0++}
        }
    }
    return int(math.Min(float64(count0), float64(count1)))
}