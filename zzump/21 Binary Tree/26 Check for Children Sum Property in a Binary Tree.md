https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/

https://www.youtube.com/watch?v=fnmisPM6cVo

![image](https://user-images.githubusercontent.com/53824950/159206042-e8376cc7-6cdc-4aa7-b193-105658754cc8.png)

![image](https://user-images.githubusercontent.com/53824950/159206060-14d25f54-fbff-493c-b382-d4b71b1eb0ac.png)

Time Complexity: O(N)

Reason: We are doing a simple tree traversal.

Space Complexity: O(N)

Reason: In the worst case( skewed tree), space complexity can be O(N).

```
void reorder(BinaryTreeNode < int > * root) {
    if(root == NULL) return; 
    int child = 0;
    if(root->left) {
        child += root->left->data; 
    }
    if(root->right) {
        child += root->right->data; 
    }
    
    if(child >= root->data) root->data = child; 
    else {
        if(root->left) root->left->data = root->data; 
        else if(root->right) root->right->data = root->data; 
    }
    
    reorder(root->left); 
    reorder(root->right); 
    
    int tot = 0; 
    if(root->left) tot += root->left->data; 
    if(root->right) tot+= root->right->data; 
    if(root->left or root->right) root->data = tot;  
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root); 
}  
```
