/**
 * @param {string} customers
 * @return {number}
 */
var bestClosingTime = function(customers) {
    let n = customers.length;
    let count = 0;
    for(const ch of customers) count += ch === 'Y';
    let mini = count;
    let nn = 0;
    let ans = 0;
    for(let i = 0; i < n; ++i) {
        if(customers[i] == 'Y') {
            count--;
        } else nn++;
        if(nn + count < mini) {
            mini = nn + count;
            ans = i + 1;
        }
    }
    return ans;
};