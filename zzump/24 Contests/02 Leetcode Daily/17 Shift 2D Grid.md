https://leetcode.com/problems/shift-2d-grid/

https://leetcode.com/problems/shift-2d-grid/discuss/458848/C%2B%2B-Straight-forward-solution

```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m * n; ++i) {
            int ori_y = i / n;
            int ori_x = i % n;
            int new_y = (ori_y + (ori_x + k) / n) % m;
            int new_x = (ori_x + k) % n;
            
            ans[new_y][new_x] = grid[ori_y][ori_x];
        }
        return ans;
    }
};
```
