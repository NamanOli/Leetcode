https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/

https://www.youtube.com/watch?v=WszrfSwMz58

https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree/

Approach: A brute force approach would be to generate all paths and compare them. Generating all paths will be a time-costly activity therefore we need to look for something else.

We first need to define what is the maximum path sum through a given node (when that node is acting as the root node/curving point). At a given node with a value, if we find the max leftSumPath in the left-subtree and the max rightSumPath in the right subtree, then the maxPathSum through that node is value+(leftSumPath+rightSumPath).



Now we can apply this formula at every node by doing a simple tree traversal and storing the maximum value (our answer) in a reference variable.

For our recursion to work, it is very important to understand what value we return from our function. In our recursive function, we find and compare the maxPathSum from a given node when it is the root/turning point of the path. But what we return is the maxPathSum of that same node when it is NOT the root/turning point of the path. To find the latter maxPath, we no longer have the liberty to consider both leftMaxPath and rightMaxPath, we will simply take the maximum of the two and it to the value of the node.



To summarize:

Initialize a maxi variable to store our final answer.
Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).

![image](https://user-images.githubusercontent.com/53824950/159123265-11e48cb2-a69b-408c-89b2-465a78947ccf.png)

![image](https://user-images.githubusercontent.com/53824950/159123267-dcf14043-28af-485a-853b-24a9396c8d9b.png)

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
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN; 
        maxPathDown(root, maxi); 
        return maxi;  
    }
    
    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};
```

Time Complexity: O(N).

Reason: We are doing a tree traversal.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
