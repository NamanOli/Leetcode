class Solution 
{
public:
    void inorder(TreeNode* node, int &low, int &high, int &sum)
    {
        if(!node) return;
        inorder(node->left, low, high, sum);
        if(node->val >= low && node->val <= high) sum += node->val;
        inorder(node->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int sum=0;
        inorder(root, low, high, sum);
        return sum;  
    }
};