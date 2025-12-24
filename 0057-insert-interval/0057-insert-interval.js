/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
function bs(intervals, x, flag) {
    let low = 0, high = intervals.length-1;
    while(low <= high) {
        const mid = low + Math.floor((high - low) / 2);
        if(flag) {
                if(intervals[mid][1] >= x) high = mid - 1;
                else low = mid + 1;
        }
        else {
            if(intervals[mid][0] <= x) low = mid + 1;
            else high = mid - 1;
        }
    }
        return flag ? low : high;
    }
var insert = function(intervals, newInterval) {
    if(!intervals.length) return [newInterval];
    const start = newInterval[0], end = newInterval[1];
    intervals.sort((a, b)=>a[0]-b[0]);
    
    const startIdx = bs(intervals, start, true);
    const endIdx = bs(intervals, end, false);

    if (startIdx <= endIdx) {
        newInterval[0] = Math.min(newInterval[0], intervals[startIdx][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[endIdx][1]);
    }
    const deleteCount = (endIdx - startIdx) + 1;
    intervals.splice(startIdx, deleteCount, newInterval);
    return intervals;
};