# Beats 90% || BFS | Bitmask | Dominance Pruning || C++

# Code
```cpp []
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].length();
        int mpp[401] = {}, k = 0;
        int sx, sy;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                char ch = classroom[i][j];
                if(ch == 'L') mpp[i*n + j] = k++;
                else if(ch == 'S') sx = i, sy = j;
            }
        }
        using T = tuple<int, int, int, int>;
        queue<pair<T, int>> q;
        vector<vector<int>> max_energy(m * n, vector<int>(1 << k, -1));
        q.push({{sx, sy, energy, 0}, 0});
        max_energy[sx * n + sy][0] = energy;
        int delta[] = {0, 1, 0, -1, 0};
        auto inBounds = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            auto &[r, c, en, mask] = p.first; int moves = p.second;
            if(mask == (1 << k) - 1) return moves;
            for(int i = 0; i < 4; ++i) {
                int nr = r + delta[i], nc = c + delta[i + 1];
                if(inBounds(nr, nc) && classroom[nr][nc] != 'X' && en > 0) {
                    int newEn = en - 1, newMask = mask;
                    if(classroom[nr][nc] == 'L') newMask = mask | (1 << mpp[nr*n + nc]);
                    else if(classroom[nr][nc] == 'R') newEn = energy;
                    if(max_energy[nr*n + nc][newMask] >= newEn) continue;
                    q.push({{nr, nc, newEn, newMask}, moves+1});
                    max_energy[nr*n + nc][newMask] = newEn;
                }
            }
        }
        return -1;
    }
};
```