https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=43

```
int floorInBST(TreeNode<int> * root, int key)
{
    int floor = -1; 
    while (root) {
 
        if (root->val == key) {
            floor = root->val;
            return floor;
        }
 
        if (key > root->val) {
            floor = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}
```

![image](https://user-images.githubusercontent.com/53824950/160408931-83781284-3f81-4efa-ab0f-54a8a82866da.png)


