https://leetcode.com/problems/search-a-2d-matrix/

https://leetcode.com/problems/search-a-2d-matrix/discuss/1895847/C%2B%2B-oror-Algorithm-oror-Binary-Search-oror-Brute-Force

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int lo=0, hi=mat.size()-1;
        int mid;
        
		while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(mat[mid][0]==target)
                return true;
            else if(mat[mid][0]>target)
                    hi=mid-1;
            else    lo=mid+1;
        }
        
		if(hi==-1)           // Edge case if hi goes out of bound.
			return false;
		
		int row=hi;
        lo=0, hi=mat[0].size()-1;
        
		while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(mat[row][mid]==target)
                    return true;
            else if(mat[row][mid]>target)
                    hi=mid-1;
                else    lo=mid+1;
        }
        return false;
    }
};
```
