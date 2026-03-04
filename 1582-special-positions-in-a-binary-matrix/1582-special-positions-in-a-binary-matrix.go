func numSpecial(mat [][]int) int {
    m := len(mat)
    n := len(mat[0])
    countRow := make([]int, m)
    countCol := make([]int, n)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            countRow[i] += mat[i][j]
            countCol[j] += mat[i][j];
        }
    }
    ans := 0
    for i := 0; i < m; i++ {
        if countRow[i] > 1 {
            continue;
        }
        for j := 0; j < n; j++ {
            if countCol[j] > 1 {
                continue
            }
            if mat[i][j] == 1 {
                ans++;
            }
        }
    }
    return ans
}