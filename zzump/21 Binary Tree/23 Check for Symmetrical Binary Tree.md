https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/

https://leetcode.com/problems/symmetric-tree/submissions/

https://www.youtube.com/watch?v=nKggNAiEpBE

![image](https://user-images.githubusercontent.com/53824950/159150639-7c6fde71-4b55-4b0b-9300-c408f751827d.png)

![image](https://user-images.githubusercontent.com/53824950/159150648-22555387-a9c5-4243-91f3-6eb5bd75595b.png)

![image](https://user-images.githubusercontent.com/53824950/159150654-1fa59266-19f0-455b-8d09-6dbd14ebe124.png)

![image](https://user-images.githubusercontent.com/53824950/159150656-61a32cb7-ebf1-4e0c-bf03-db05d7d7ef05.png)

Intuition: We need to understand the property of the mirror. We can ignore the root node as it is lying on the mirror line. In the next level, for a symmetric tree, the node at the root’s left should be equal to the node at the root’s right.

If we take two variables root1 and root2 to represent the left child of root and right child of the root, then

Further, we need to understand that when root1’s value is equal to root2’s value, we need to further check for its children. As we are concerned about node positions through a mirror, root1’s left child should be checked with root2’s right child and root1’s right child should be checked with root2’s left child.





Approach: 

The algorithm steps can be summarized as follows::

We take two variables root1 and root2 initially both pointing to the root.
Then we use any tree traversal to traverse the nodes. We will simultaneously change root1 and root2 in this traversal function.
For the base case, if both are pointing to NULL, we return true, whereas if only one points to NULL and other to a node, we return false.
If both points to a node, we first compare their value, if it is the same we check for the lower levels of the tree.
We recursively call the function to check the root1’s left child with root2’s right child; then we again recursively check the root1’s right child with root2’s left child.
When all three conditions ( node values of left and right and two recursive calls) return true, we return true from our function else we return false.

![image](https://user-images.githubusercontent.com/53824950/159150687-08c1e220-894a-4e02-9d4d-a2ebcff0fb0e.png)


![image](https://user-images.githubusercontent.com/53824950/159150690-eadfb111-f4cf-4f66-9fa0-862ed4e7bd2b.png)


![image](https://user-images.githubusercontent.com/53824950/159150694-fc825213-2a95-4872-81b3-79d4844cc520.png)


![image](https://user-images.githubusercontent.com/53824950/159150695-8eed8bec-09a0-4c75-8b85-d99955568c5e.png)

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
    bool f(TreeNode *root1, TreeNode* root2) {
       if (root1 == NULL || root2 == NULL) 
           return root1 == root2;
        
    return (root1->val == root2->val) && f(root1->left, root2->right) && f(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return f(root->left, root->right);
    }
};
```


The tree is symmetrical

Time Complexity: O(N)

Reason: We are doing simple tree traversal and changing both root1 and root2 simultaneously.

Space Complexity: O(N)

Reason: In the worst case (skewed tree), space complexity can be O(N).
