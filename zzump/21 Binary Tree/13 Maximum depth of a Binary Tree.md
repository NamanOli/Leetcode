https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/

https://leetcode.com/problems/maximum-depth-of-binary-tree/

https://www.youtube.com/watch?v=eD3tmO66aBA

```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};
```

![image](https://user-images.githubusercontent.com/53824950/158064773-51329787-0c3a-4b95-afbc-babfaf2c1863.png)

Result: 4

Explanation: Maximum Depth in this tree is 4 if we follow path 5 – 1 – 3 – 8 or 5 – 1 – 3 – 11


If we have to do it recursively, then what we can think of is, If I have Maximum Depth of Left subtree and Maximum Depth of Right subtree then what will be the height or depth of the tree?

1 + max(depth of left subtree, depth of right subtree)
So, to calculate the Maximum Depth, we can simply take the maximum of the depths of the left and right subtree and add 1 to it.

Why take Maximum?? Because we need maximum depth so if we know left & right children’s maximum depth then we’ll definitely get to the maximum depth of the entire tree.

Approach : 

We start to travel recursively and do our work in Post Order.
 Reason behind using Post Order comes from our intuition , that if we know the result of  left and right child then we can calculate the result using that. 
This is exactly an indication of PostOrder, because in PostOrder we already calculated results for left and right children than we do it for current node.
So for every node post order, we do Max( left result , right result ) + 1 and return it to the previous call.
Base Case is when root == null so we need to return 0;

![image](https://user-images.githubusercontent.com/53824950/158065475-f977d082-f28f-43a7-9e0a-25c642a8f7a3.png)


Reach on Node 10 , Left child = null so 0 , Right child = null so 0 & add 1 for node 10 so max depth till node 10 is max(0,0) + 1 = 1. 
Reach on Node 2 , Left child = null so 0 , Right child = will give 1 & add 1 for node 2 so max depth till node 2 is max(0,1) + 1 = 2.
Reach on Node 8 , Left child = null so 0 , Right child = null so 0 & add 1 for node 8 so max depth till node 8 is max(0,0) + 1 = 1.
Reach on Node 11 , Left child = null so 0 , Right child = null so 0 & add 1 for node 11 so max depth till node 11 is max(0,0) + 1 = 1.
Reach on Node 3 , Left child will give 1 , Right child = will give 1 & add 1 for node 3 so max depth till node 3 is max(1,1) + 1 = 2.
Reach on Node 4 , Left child = null so 0 , Right child = null so 0 & add 1 for node 4 so max depth till node 4 is max(0,0) + 1 = 1.
Reach on Node 5 , Left child will give 2 , Right child = will give 1 & add 1 for node 5 so max depth till node 5 is max(2,1) + 1 = 3.
Reach on Node 12 , Left child will give 2 , Right child = will give 3 & add 1 for node 12 so max depth till node 12 is max(2,3) + 1 = 4.
Hence 4 is our final ans.

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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};
```

Time Complexity: O(N) 

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the binary tree.







