func solve(i, n int, temp string, ans *string, st map[string]struct{}) {
    if *ans != "" { return }
    if i == n {
        if _, ok := st[temp]; !ok {
            *ans = temp
        }
        return
    }
    solve(i + 1, n, temp+"0", ans, st)
    solve(i + 1, n, temp+"1", ans, st)
}

func findDifferentBinaryString(nums []string) string {
    st := make(map[string]struct{})
    for _, s := range nums {
        st[s] = struct{}{}
    }
    ans := ""
    solve(0, len(nums), "", &ans, st)
    return ans
}