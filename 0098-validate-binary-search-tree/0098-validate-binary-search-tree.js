/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function helper(root, l, r) {
    if(!root) return true;
    if(root.val <= l || root.val >= r) return false;
    return helper(root.left, l, root.val) && helper(root.right, root.val, r);
}
var isValidBST = function(root) {
    return helper(root, Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
};