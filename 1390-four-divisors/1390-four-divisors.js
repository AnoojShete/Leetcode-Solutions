var sumFourDivisors = function(nums) {
    let sum = 0;
    for(const num of nums) {
        let temp = 0;
        let count = 0;
        for(let i = 1; i * i <= num; ++i) {
            if(num % i === 0) {
                let j = num / i;
                count++;
                temp += i;
                if(i != j) {
                    count++;
                    temp += j;
                }
            }
        }
        if(count === 4) sum += temp;
    }
    return sum;
};