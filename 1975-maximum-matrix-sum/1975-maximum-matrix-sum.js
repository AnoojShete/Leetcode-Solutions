var maxMatrixSum = function(matrix) {
    const n = matrix.length;
    let count = 0, sum = 0;
    let mini = Infinity;
    for(let i = 0; i < n; ++i) {
        for(let j = 0; j < n; ++j) {
            if(matrix[i][j] < 0) count++;
            sum += Math.abs(matrix[i][j]);
            mini = Math.min(mini, Math.abs(matrix[i][j]));
        }
    }
    if(count & 1) return sum - 2 * mini;
    return sum;
};