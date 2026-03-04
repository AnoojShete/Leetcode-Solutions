func divide(dividend int, divisor int) int {
    if dividend == -2147483648 && divisor == -1 {
		return 2147483647
	}
    ans := 0
    neg := (dividend < 0) != (divisor < 0)
    a := int64(dividend)
	if a < 0 { a = -a }
	b := int64(divisor)
	if b < 0 { b = -b }
    for i := 31; i >= 0; i-- {
        if b << i <= a {
            a -= b << i
            ans |= 1 << i
        }
    }
    if neg {
        return -ans
    }
    return ans
}