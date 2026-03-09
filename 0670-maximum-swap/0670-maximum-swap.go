import "math"

func maximumSwap(num int) int {
    i, j, maxi, maxIdx := -1, -1, -1, -1
    temp, pos := num, 0
    for temp > 0 {
        digit := temp % 10
        if digit > maxi {
            maxi = digit
            maxIdx = pos
        } else if digit < maxi {
            i = pos
            j = maxIdx
        }
        temp /= 10
        pos++
    }
    if i == -1 { return num }
    digitI := (num / int(math.Pow(10, float64(i)))) % 10
    digitJ := (num / int(math.Pow(10, float64(j)))) % 10

    num -= digitI * int(math.Pow(10, float64(i)))
    num -= digitJ * int(math.Pow(10, float64(j)))
    
    num += digitI * int(math.Pow(10, float64(j)))
    num += digitJ * int(math.Pow(10, float64(i)))

    return num
}