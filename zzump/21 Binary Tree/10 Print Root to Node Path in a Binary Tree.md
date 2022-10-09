https://takeuforward.org/data-structure/print-root-to-node-path-in-a-binary-tree/

https://www.interviewbit.com/problems/path-to-given-node/

https://youtu.be/fmflMqVOC7k

![image](https://user-images.githubusercontent.com/53824950/158054401-c208916c-4983-4f0f-88c9-d1e3a144244c.png)

First of all, we need to find the node V in our tree for which we need to find the path. We can use any depth-first traversal technique (preorder, inorder, postorder) in order to find the required node.

If we look at the diagram below, we see that whenever we find the required node, its path is well present in our recursion call stack. We just need to figure out how we can use the recursive calls to print the required path.



Approach: 

We will use an external list to store our path. This list will be passed by reference to our recursive function. Moreover, we can set the return value of our function as boolean, this will help us to know whether node V was found in a subtree or not.

The algorithm steps can be stated as follows:

We pass the function with our root node, the path list and node V.
For the base case, if root is pointing to NULL, we return false as clearly node V can’t be found.
Now we first push the node to our path list.
Then we check whether the current node is the target node or not, if it is then no further execution is needed and we return to the parent function.
If not, then we recursively call its left and right child to find the target node V. If any one of them returns true, it means we have found node V at lower levels and return true from the current function.
If the value is not found at the current node and neither in any of the recursive calls, it means that the value is not present in the current sub-tree, therefore we pop out the current node from the path list and return false.

![image](https://user-images.githubusercontent.com/53824950/158054420-369fc988-2890-4724-b526-708fb1b06104.png)

```
bool getPath(TreeNode *root, vector<int> &arr, int x) {
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->val);   
     
    // if it is the required node
    // return true
    if (root->val == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;  
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr; 
    if(A == NULL) {
        return arr; 
    }
    getPath(A, arr, B);
    return arr; 
}
```
