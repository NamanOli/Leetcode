https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/1201679/C%2B%2B-Python3-No-Heap-No-BS-Simple-Sort-99.20

https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/


```
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        for(int i=0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        for(int i=0; i<k; i++){
            ans[i]=mat[i][n];            
        }
        return ans;
    }
};
```
