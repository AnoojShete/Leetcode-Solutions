/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    const adj = Array.from({ length: numCourses }, () => []);
    const indegree = new Array(numCourses).fill(0);
    prerequisites.forEach((pre)=>{
        const u = pre[0], v = pre[1];
        adj[v].push(u);
        indegree[u]++;
    });
    const q = [];
    for(let i = 0; i < numCourses; ++i) if(indegree[i] === 0) q.push(i);
    let count = 0;
    while(q.length) {
        const node = q.shift();
        count++;
        adj[node].forEach((nei)=>{
            if(--indegree[nei] === 0) q.push(nei);
        })
    }
    return count === numCourses;
};