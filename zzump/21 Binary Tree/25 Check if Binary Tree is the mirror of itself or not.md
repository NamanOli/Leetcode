https://practice.geeksforgeeks.org/problems/mirror-tree/1#

```
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL) return;
        mirror(node -> left);
        mirror(node -> right);
        Node *r = node -> right;
        node -> right = node -> left;
        node -> left = r;
    }
};
```
