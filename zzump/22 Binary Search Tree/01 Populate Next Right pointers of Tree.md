https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/1654181/C%2B%2BPythonJava-Simple-Solution-w-Images-and-Explanation-or-BFS-%2B-DFS-%2B-O(1)-Optimized-BFS


```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node * rightNode =NULL;
            for(int i=q.size();i;i--)
            {
                auto cur=q.front();
                q.pop();
                cur->next=rightNode;
                rightNode=cur;
                if(cur->right)
                {
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};
```

Time Complexity : O(N), where N is the number of nodes in the given tree. We only traverse the tree once using BFS which requires O(N).
Space Complexity : O(W) = O(N), where W is the width of given tree. This is required to store the nodes in queue. Since the given tree is a perfect binary tree, its width is given as W = (N+1)/2 ≈ O(N)

```
It's important to see that the given tree is a perfect binary tree. This means that each node will always have both children and only the last level of nodes will have no children.



Now, we need to populate next pointers of each node with nodes that occur to its immediate right on the same level. This can easily be done with BFS. Since for each node, we require the right node on the same level, we will perform a right-to-left BFS instead of the standard left-to-right BFS.

Before starting the traversal of each level, we would initialize a rightNode variable set to NULL. Then, since we are performing right-to-left BFS, we would be starting at rightmost node of each level. We set the next node of cur as rightNode and update rightNode = cur. This would ensure that each node would be assigned its rightNode properly while traversing from right to left.
Also, if cur has a child, we would first push its right child and only then its left child (since we are doing right-to-left BFS). Once BFS is completed (after queue becomes empty), all next node would be populated and we can finally return root.
```
