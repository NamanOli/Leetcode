https://leetcode.com/problems/binary-tree-inorder-traversal/

https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/

https://www.youtube.com/watch?v=Z_NEgBgbRVI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=7

https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11

Solution 1 - Recursive

![image](https://user-images.githubusercontent.com/53824950/158007186-ddd1855f-0f52-4e5e-ab41-0d381c0aa3f4.png)


![image](https://user-images.githubusercontent.com/53824950/158007177-2f6a9a88-19e2-4f73-bfb2-d2cffc6e7a39.png)


```
Approach: In inorder traversal, the tree is traversed in this way: left, root, right.

The algorithm approach can be stated as:

We first recursively visit the left child and go on till we find a leaf node.
Then we print that node value.
Then we recursively visit the right child.
If we encounter a node pointing to NULL, we simply return to its parent.
Explanation: It is very important to understand how recursion works behind the scenes to traverse the tree. For it we will see a simple case:



Inorder traversal of this tree: 2,1,3

Initially, we pass the root node pointing to 1 to our traversal function. The algorithm steps are as follows:

As we are doing an inorder traversal, the first thing we will do is to recursively visit the left child. We continue till the time we find a leaf node. At node 2, as there is no more left child, we print its value.
Then we need to move back to node 1 but how do we do so? Remember that our nodes only have pointers to the children and not to the parent, therefore we can move only from parent to child and not from a child to the parent.
The answer to this question is recursion. When we move to node 2, we call it recursively. This second function is then pushed to our call stack. We do our execution which is to visit the left child of node 2, return from it as it is NULL, print current node value and then again recursively call its right child. 
This second function will then be removed from our call stack and we will return to the first function. Then we again recursively call the function for the right child and do the execution, i.e print 1 and then visit its right child.
The call stack diagram will help to understand the recursion better.



Dry Run: In case you want to watch the dry run for this approach, please watch the video attached below.

The inOrder Traversal is : 4 2 8 5 1 6 3 9 7 10 

Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
```

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};
```

Solution 2 - Iterative

```
Intuition: In inorder traversal, the tree is traversed in this way: root, left, right. We first visit the left child, after returning from it we print the current node value, then we visit the right child. The fundamental problem we face in this scenario is that there is no way that we can move from a child to a parent. To solve this problem, we use an explicit stack data structure. While traversing we can insert node values to the stack in such a way that we always get the next node value at the top of the stack.

Approach: 

The algorithm approach can be stated as:

We first take an explicit stack data structure and set an infinite loop.
In every iteration we check whether our current node is pointing to NULL or not.
If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have traversed the tree and we break out of the loop.
If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.
Stack is a Last-In-First-Out (LIFO) data structure, therefore when we encounter a node, we simply push it to the stack and try to find nodes on its left. When the current node points to NULL, it means that there is nothing left to traverse and we should move to the parent. This parent is always placed at the top of the stack. If the stack is empty, then we had already traversed the whole tree and should stop the execution.

Dry Run: In case you want to watch the dry run for this approach, please watch the video attached below.

Iterative solution using stack: O(n) time and O(n) space;
Recursive solution: O(n) time and O(n) space (function call stack);
Morris traversal: O(n) time and O(1) space.

The inOrder Traversal is : 4 2 8 5 1 6 3 9 7 10

Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: In the worst case (a tree with just left children), the space complexity will be O(N).

```

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};
```



