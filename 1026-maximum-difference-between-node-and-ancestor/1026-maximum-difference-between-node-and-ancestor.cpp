class Solution {
private:
    void dfs(TreeNode* root, int mx, int mn){
        if(root== NULL) return;

        //update mx and mn value to get max diff
        if(root->val> mx) mx = root->val;
        else if(root->val < mn) mn = root->val;
        int tmp = max(abs(mx- root->val), abs(mn- root->val));
        if(tmp> ans) ans = tmp;

        // cout<<root->val<<" "<<mx<<" "<<mn<<endl;
        dfs(root->left, mx, mn);
        dfs(root->right, mx, mn);
    }

public:
    //DSF: carry 2 variable mx & mn
    int ans = -1;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};