function inBounds(row, col, m, n) {
    return row < m && col < n && row >= 0 && col >= 0;
}
function dfs(row, col, board, idx, word) {
    if(idx == word.length) {
        return true;
    }
    if (!inBounds(row, col, board.length, board[0].length)) return false;
    if (board[row][col] !== word[idx]) return false;
    const delta = [-1, 0, 1, 0, -1];
    const temp = board[row][col];
    board[row][col] = '.';
    let found = false;
    for(let i = 0; i < 4; ++i) {
        const nrow = row + delta[i], ncol = col + delta[i+1];
        if(dfs(nrow, ncol, board, idx+1, word)) {
            found = true;
            break;
        }
    }
    board[row][col] = temp;
    return found;
}
var exist = function(board, word) {
    let ans = false;
    for(let i = 0; i < board.length; ++i) {
        for(let j = 0; j < board[0].length; ++j) {
            if(board[i][j] == word[0]) {
                ans |= dfs(i, j, board, 0, word);
            }
        }
    }
    return ans;
};