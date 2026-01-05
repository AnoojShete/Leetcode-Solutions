var maxMatrixSum = function(matrix) {
    let count = 0, flag = false, sum = 0;
    let mini = Infinity;
    for(const row of matrix) {
        for(const val of row) {
            if(val < 0) count++;
            sum += Math.abs(val);
            mini = Math.min(mini, Math.abs(val));
        }
    }
    if(count % 2 === 0 || flag) return sum;
    return sum - 2 * mini;
};