function getSum(root) {
    if(!root) return 0n;
    return BigInt(root.val) + getSum(root.left) + getSum(root.right);
}

let maxProd = 0n, totalSum = 0n, MOD = 1000000007n;

function solve(root) {
    if(!root) return 0n;
    const sum = BigInt(root.val) + solve(root.left) + solve(root.right);
    const product = sum * (totalSum - sum);
    if(product > maxProd) maxProd = product;
    return sum;
}

var maxProduct = function(root) {
    maxProd = 0n;
    totalSum = getSum(root);
    solve(root);
    return Number(maxProd % MOD);
};