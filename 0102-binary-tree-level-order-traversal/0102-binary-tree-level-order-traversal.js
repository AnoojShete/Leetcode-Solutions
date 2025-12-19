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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    const ans = [];
    if(!root) return ans;
    const queue = [root];
    while(queue.length != 0) {
        let sz = queue.length;
        const level = [];
        while(sz--) {
            const front = queue.shift();
            level.push(front.val);
            if(front.left) queue.push(front.left);
            if(front.right) queue.push(front.right);
        }
        ans.push(level);
    }
    return ans;
};