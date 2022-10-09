https://leetcode.com/problems/validate-binary-search-tree/

https://youtu.be/f-sj7I5oXEI



![image](https://user-images.githubusercontent.com/53824950/160268753-bbe2801e-a43d-4aad-bd7c-ca2bcfe73582.png)

![image](https://user-images.githubusercontent.com/53824950/160268910-3f81847e-295a-4f23-9040-5b9d1ef3c64c.png)

Time - O(N)
Space - O(1)

```
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean isValidBST(TreeNode root, long minVal, long maxVal) {
        if (root == null) return true;
        if (root.val >= maxVal || root.val <= minVal) return false;
        return isValidBST(root.left, minVal, root.val) && isValidBST(root.right, root.val, maxVal);
    }
}
```
