import "strconv"

func isValid(s *string) bool {
    if len(*s) > 3 || (len(*s) > 1 && (*s)[0] == '0') { return false }
    n, _ := strconv.Atoi(*s)
    return n >= 0 && n <= 255
}

func solve(idx int, s *string, path []string, ans *[]string) {
    if len(path) == 4 {
        if idx == len(*s) {
            *ans = append(*ans, path[0]+"."+path[1]+"."+path[2]+"."+path[3]);
        }
        return;
    }
    for l := 1; l <= 3; l++ {
        if idx + l > len(*s) { break }
        temp := (*s)[idx : idx+l]
        if isValid(&temp) {
            path = append(path, temp)
            solve(idx + l, s, path, ans)
            path = path[:len(path)-1]
        }
    }
}

func restoreIpAddresses(s string) []string {
    ans, path := []string{}, []string{}
    solve(0, &s, path, &ans)
    return ans
}