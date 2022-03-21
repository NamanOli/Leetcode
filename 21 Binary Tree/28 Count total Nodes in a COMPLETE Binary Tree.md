https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=35

https://leetcode.com/problems/count-complete-tree-nodes/

![image](https://user-images.githubusercontent.com/53824950/159338257-d2d61fb5-00e3-458d-b499-a2200b7df5fa.png)

![image](https://user-images.githubusercontent.com/53824950/159338369-debe4425-2277-4f9d-898c-1096fe936648.png)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    int findHeightLeft(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
};
```

