function solve(root) {
    if(!root) return [root, 0];
    const L = solve(root.left);
    const R = solve(root.right);
    if(L[1] > R[1]) return [L[0], L[1] + 1];
    else if(R[1] > L[1]) return [R[0], R[1] + 1];
    return [root, L[1] + 1];
}

var subtreeWithAllDeepest = function(root) {
    return solve(root)[0];
};