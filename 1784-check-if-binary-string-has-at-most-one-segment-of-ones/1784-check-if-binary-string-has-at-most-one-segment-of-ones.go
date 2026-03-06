func checkOnesSegment(s string) bool {
    for i := 1; i < len(s)-1; i++ {
        if s[i] == '0' && s[i+1] == '1' { return false }
    }
    return true
}