https://www.youtube.com/watch?v=0ca1nvR0be4

https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

https://leetcode.com/problems/boundary-of-binary-tree/#

![image](https://user-images.githubusercontent.com/53824950/158368683-f069af23-ebea-4995-8da9-1e1b72ec7183.png)


```
class Solution {
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = tmp.size()-1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
public:
    vector <int> printBoundary(Node *root)
    {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res); 
        
        // add leaf nodes
        addLeaves(root, res);

        addRightBoundary(root, res); 
        return res;
    }
};
```

Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

Part 1: Left Boundary of the tree (excluding the leaf nodes).
Part 2: All the leaf nodes travelled in the left to right direction.
Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
We take a simple data structure like a vector/Arraylist to store the Boundary Traversal. The root node is coming from both the boundaries (left and right). Therefore, to avoid any confusion, we push it on our list at the very start.



We will now see the approach to finding these three parts.

Part 1:  Left Boundary



To traverse the left boundary, we can set a simple iteration. Initially, we make the cur pointer point to the root’s left. In every iteration, if the cur node is not a leaf node, we print it. Then we always try to move left of the cur pointer. If there is no left child, then we move to the right of cur and in the next iteration, again try to move to the left first. We stop our execution when cur is pointing to NULL. 



Part 2: Leaf nodes



To print the leaf nodes, we can do a simple preorder traversal, and check if the current node is a leaf node or not. If it is a leaf node just print it.

Please note that we want the leaves to come in a specific order which is bottom-left to top-right, therefore a level order traversal will not work because it will print the upper-level leaves first. Therefore, we use a preorder traversal.



Part 3: Right Boundary



We need to print the right boundary in the Reverse direction. It is very similar to the left boundary traversal. We initialize our cur pointer to the right child of the root node and set an iterative loop. To achieve the reverse direction, we take an auxiliary list. In every iteration, we check if the current node is not a leaf node then we push it to the auxiliary list. Then we first try to move right of cur, if there is no right child only then we move left. We stop our execution once cur points to NULL.

Now the auxiliary list contains the nodes of the right boundary. We iterate from the end to start off this list and in every iteration, push the value to our main boundary traversal list. This way we get the nodes in the reverse direction.


