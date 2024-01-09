class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
        }
        
        inorder(root->left,v);
        inorder(root->right,v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first,second;
        inorder(root1,first);
        inorder(root2,second);

        if(first.size()!=second.size()) return false;
        for(int i=0;i<first.size();i++){
            if(first[i]!=second[i]) return false;
        }
        return true;
    }
};