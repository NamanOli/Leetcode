https://youtu.be/UmJT3j26t1I

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

1. Traverse the array the first element will be the root . Keep on putting the smaller element to the left and greater element to the right.

Time Complexity - O(N * N)

2. Find the inorder of the array by sorting the preorder arrar. Then create the BST using preorder and inorder.

Time Complexity - O(NlogN) + O(N)
Space Complexity - O(N)


3. Using Upper Bound

Time Complexity - O(N)
Space Complexity - O(1)

![image](https://user-images.githubusercontent.com/53824950/160255587-4ea858ec-55b4-41ba-b6a0-094f98069352.png)


![image](https://user-images.githubusercontent.com/53824950/160255594-4caf4c39-2ec3-4f72-b91d-b279102779ce.png)


![image](https://user-images.githubusercontent.com/53824950/160255609-4ee5d305-b56d-4dd8-b988-30c90c16e244.png)

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
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};
```
