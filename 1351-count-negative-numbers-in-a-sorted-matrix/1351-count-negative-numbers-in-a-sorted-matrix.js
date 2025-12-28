var countNegatives = function(grid) {
    const m = grid.length, n = grid[0].length;
    let i = m-1, j = 0;
    let count = 0;
    while(i >= 0 && j < n) {
        if(grid[i][j] < 0) {
            count += n - j;
            i--;
        }
        else j++;
    }
    return count;
};