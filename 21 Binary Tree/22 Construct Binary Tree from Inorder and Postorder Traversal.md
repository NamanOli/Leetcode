https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

https://www.youtube.com/watch?v=LgLRTaEMRVc

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if (inorder.size() != postorder.size())
            return NULL;
        map<int,int> hm;
        for (int i=0;i<inorder.size();++i)
            hm[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,hm);
    }
    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ri = hm[postorder[pe]];
        TreeNode* leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        TreeNode* rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root->left = leftchild;
        root->right = rightchild;
        return root;
    }
};
```

![image](https://user-images.githubusercontent.com/53824950/159149952-0151fc8f-1d4f-43d3-8254-b6f85599e4ad.png)
