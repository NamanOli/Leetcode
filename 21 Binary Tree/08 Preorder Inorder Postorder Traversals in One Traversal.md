https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/

https://bit.ly/3rlXpTX

https://youtu.be/ySp2epYvgTE

Intuition: If we study the preorder, inorder and postorder traversals, we will observe a pattern. To understand this pattern, we take a simple example:



The number inside the red boxes is the visit when we print the node. In preorder traversal, we print a node at the first visit itself. Whereas, in inorder traversal at the first visit to a node, we simply traverse to the left child. It is only when we return from the left child and visit that node the second time, that we print it. Similarly, in postorder traversal, we print a node in its third visit after visiting both its children.

Approach: 

The algorithm steps can be described as follows:

We take a stack data structure and push a pair<val, num> to it. Here Val is the value of the root node and num the visit to the node. Initially, the num is 1 as we are visiting the root node for the first time. We also create three separate lists for preorder, inorder and postorder traversals. Then we set an iterative loop to run till the time our stack is non-empty.

In every iteration, we pop the top of the stack (say, T). Then we check the second value(num) of T. Three cases can arise:

Case 1 : When num==1
This means that we are visiting the node for the very first time, therefore we push the node value to our preorder list. Then we push the same node with num=2(for Case 2). After this, we want to visit the left child. Therefore we make a new pair Y(<val, num>) and push it to the stack (if there exists a left child). The val of Y is equal to the left child’s node value and num is equal to 1.

Case 2 : When num==2
This means that we are visiting the node for the second time, therefore on our second visit to the node, we push the node value to our inorder list. Then we push the same node with num=3( for Case 3). After this, we want to visit the right child. Therefore as in the first case, we check if there exists a right child or not. If there is, we push the right child and num value=1 as a pair to our stack.

Case 3 When num==3
This means that we are visiting the node for the third time. Therefore we will push that node’s value to our postorder list. Next, we simply want to return to the parent so we will not push anything else to the stack.



The preorder Traversal is: 1 2 4 5 3 6 7
The inorder Traversal is: 4 2 5 1 6 3 7
The postorder Traversal is: 4 5 2 6 7 3 1

Time Complexity: O(N)

Reason: We are visiting every node thrice therefore time complexity will be O(3*N), which can be assumed as linear time complexity.

Space Complexity: O(N)

Reason: We are using three lists and a stack to store the nodes. The time complexity will be about O(4*N), which can be assumed as linear time complexity.


![image](https://user-images.githubusercontent.com/53824950/158044683-626cd211-7022-44bd-a67d-9ad02022d63b.png)

![image](https://user-images.githubusercontent.com/53824950/158044940-af18f2cf-a3d3-44d1-bbfd-9bb660222817.png)

```
// LC link : https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st; 
        st.push({root, 1}); 
        vector<int> pre, in, post;
        if(root == NULL) return post;

        while(!st.empty()) {
            auto it = st.top(); 
            st.pop(); 

            // this is part of pre
            // increment 1 to 2 
            // push the left side of the tree
            if(it.second == 1) {
                pre.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }

            // this is a part of in 
            // increment 2 to 3 
            // push right 
            else if(it.second == 2) {
                in.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            // don't push it back again 
            else {
                post.push_back(it.first->val); 
            }
        } 

        return post; 
    }
};
```
