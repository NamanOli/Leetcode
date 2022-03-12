https://leetcode.com/problems/binary-tree-preorder-traversal/

https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/

https://youtu.be/RlUu72JrOCQ

https://youtu.be/Bfqd8BsPVuw

Solution 1 - Recursive

Intuition: In preorder traversal, the tree is traversed in this way: root, left, right. When we visit a node, we print its value, and then we want to visit the left child followed by the right child. The fundamental problem we face in this scenario is that there is no way that we can move from a child to a parent. To solve this problem, we use recursion and the recursive call stack to locate ourselves back to the parent node when execution at a child node is completed.

Approach: In preorder traversal, the tree is traversed in this way: root, left, right.

The algorithm approach can be stated as:

We first visit the root node and before visiting its children we print its value.
After this, we recursively visit its left child.
Then we recursively visit the right child.
If we encounter a node pointing to NULL, we simply return to its parent.

The preOrder Traversal is : 1 2 4 5 8 3 6 7 9 10 

Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

Explanation: It is very important to understand how recursion works behind the scenes to traverse the tree. For it we will see a simple case:

![image](https://user-images.githubusercontent.com/53824950/158008570-a4c3ea12-1be6-4e2e-8c7e-30ae0e665075.png)


Preorder traversal of this tree: 1,2,3.

![image](https://user-images.githubusercontent.com/53824950/158008578-8740969a-f4e5-4d1e-9188-731ce49db3e0.png)


Initially, we pass the root node pointing to 1 to our traversal function. The algorithm steps are as follows:

As we are doing a preorder traversal, the first thing we will do is to print the current node value, i.e 1.
Then we need to move left but how do we do so? Remember that our nodes only have pointers to the children and not to the parent, therefore we can move only from parent to child and not from a child to the parent.
The answer to this question is recursion. We call the same function with the current node pointing to the left child, i.e 2. This second function is then pushed to our call stack. We do our execution which is to visit node 2 print it and then again recursively call its both children. As both of them point to NULL, we will return from them and execution of the second function stops.
This second function will then be removed from our call stack and we will return to the first function. Then we again recursively call the function for the right child and do the execution.
The call stack diagram will help to understand the recursion better.

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
    vector<int>res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return res;
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};
```



Solution 2 - Iterative


Intuition: In preorder traversal, the tree is traversed in this way: root, left, right. When we visit a node, we print its value, and then we want to visit the left child followed by the right child. The fundamental problem we face in this scenario is that there is no way that we can move from a child to a parent. To solve this problem, we use an explicit stack data structure. While traversing we can insert node values to the stack in such a way that we always get the next node value at the top of the stack.

Approach: 

The algorithm approach can be stated as:

We first take an explicit stack data structure and push the root node to it.(if the root node is not NULL).
Then we use a while loop to iterate over the stack till the stack remains non-empty.
In every iteration we first pop the stack’s top and print it. 
Then we first push the right child of this popped node and then push the left child, if they are not NULL. We do so because stack is a last-in-first-out(LIFO) data structure. We need to access the left child first, so we need to push it at the last.
The execution continues and will stop when the stack becomes empty. In this process, we will get the preorder traversal of the tree.
Dry Run: In case you want to watch the dry run for this approach, please watch the video attached below.



The preOrder Traversal is : 1 2 4 5 8 3 6 7 9 10

Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: In the worst case, (a tree with every node having a single right child and left-subtree, follow the video attached below to see the illustration), the space complexity can be considered as O(N).

Iterative solution using stack --- O(n) time and O(n) space;
Recursive solution --- O(n) time and O(n) space (function call stack);
Morris traversal --- O(n) time and O(1) space.

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        if(root==NULL)
        {
            return res;
        }
        st.push(root);
        while(!st.empty())
        {
            TreeNode * curr=st.top();
            res.push_back(curr->val);
            st.pop();
            if(curr->right!=NULL)
            {
                st.push(curr->right);
            }
            if(curr->left!=NULL)
            {
                st.push(curr->left);
            }
        }
        return res;
    }
};
```

