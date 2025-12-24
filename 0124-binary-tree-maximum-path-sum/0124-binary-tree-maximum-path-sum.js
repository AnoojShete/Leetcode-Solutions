let maxi = -Infinity;

function solve(root) {
    if(!root) return 0;
    const leftSum = solve(root.left);
    const rightSum = solve(root.right);
    const temp = Math.max(Math.max(leftSum, rightSum) + root.val, root.val);
    maxi = Math.max(maxi, Math.max(temp, leftSum + rightSum + root.val));
    return temp;
}

var maxPathSum = function(root) {
    maxi = -Infinity;
    solve(root);
    return maxi
};