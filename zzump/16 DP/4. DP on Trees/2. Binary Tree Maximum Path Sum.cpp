// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        
        maxPath(root, maxSum);
        return maxSum;
    }
    int maxPath(TreeNode* root, int &maxSum)
    {
        if(root == NULL) return 0;
        // if the sum is negative the don't include that, instead return 0; 
        
        //leftSubTreeSum
        int leftSum = max(0, maxPath(root->left, maxSum));
        int rightSum = max(0, maxPath(root->right, maxSum));
        
        // updating maxSum
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        
        // return max sum for each node
        return root->val + max(leftSum, rightSum);
    }
};
