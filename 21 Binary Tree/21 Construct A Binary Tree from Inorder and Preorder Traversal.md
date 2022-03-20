https://www.youtube.com/watch?v=aZNaLrVebKQ

https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal/

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

![image](https://user-images.githubusercontent.com/53824950/159131209-bfc0b50a-e91f-4aa7-8cb0-23dd428f89e5.png)


norder traversal is a special traversal that helps us to identify a node and its left and right subtree. Preorder traversal always gives us the root node as the first element. Using these properties we can construct the unique binary tree.

Given this example:



Here 10 (first element of preorder) is the root element. So we can find its index in the inorder traversal(say elem). The left subtree of the root will be present to the left side of in order whereas the right subtree of root will be present on the right side of elem in the inorder traversal: 

We can define a recursive function that creates one node at a time. First, we create the root node, and then we can take the help of recursion to create its left and right subtrees. In order to make recursion work, we need to provide the correct inorder and preorder traversal of the subtree for every recursive call.



To make more efficient function calls we can use variables (inStart, inEnd) and (preStart and preEnd) in order to point to the start and end of the inorder and preorder traversal respectively, and avoid copying of arrays. 

Next, we need to figure out how we are going to search the root index in the inorder traversal. For this, we have two options: Linear Search and Hashmaps. We will choose the second one because it will return us the index in constant time. Before making the first recursive call, we will simply add all the (value, index) pairs to a map and pass it to our recursive function.

If n is the size of the Inorder traversal/Preorder traversal. Then our first function call will be : 



Now the main task left is to pass the correct preStart, preEnd, inStart, inEnd to the respective recursive calls for the left and right subtree. We can calculate the number of elements in the left subtree from the root index, say nElems (elem – InStart, where elem is the index of root in inorder traversal). As inorder is [left, root, right] and preorder is [root, left, right] the number of elements (nElems) will easily tell us the preorder and inorder traversal of the subtrees according to the following table:



The base case will be when inStart> inEnd or preStart > preEnd, in that case, we can simply return NULL.

Approach:

The algorithm approach can be stated as:

Create a map to store the inorder indexes.
Call the function constructTree with all 7 parameters as shown above.
In the recursive function, first check the base case, if (preStart,>preEnd || inStart> inEnd) then return NULL.
Construct a node (say root) with the root value( first element of preorder). 
Find the index of the root, say elem from the hashmap.
Find the number of elements ( say nElem) in the left subtree  = elem – inStart
 Call recursively for the left subtree with correct values (shown in the above table) and store the answer received in root->left.
Call recursively for the right subtree with correct values (shown in the above table) and store the answer received in root->right.
Return root

![image](https://user-images.githubusercontent.com/53824950/159131267-8c816e0c-0d39-4ab8-a1b1-0330f5fa1fb7.png)

![image](https://user-images.githubusercontent.com/53824950/159131272-03ba9638-f5f6-4c5f-b12a-764199332dbe.png)

![image](https://user-images.githubusercontent.com/53824950/159131276-2366021e-ee23-4f95-82ac-9113b5e7d22b.png)

![image](https://user-images.githubusercontent.com/53824950/159131288-e196cbaa-5732-4458-8c16-92d103da8213.png)

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};
```


Time Complexity: O(N)

Assumption: Hashmap returns the answer in constant time.

Space Complexity: O(N)

Reason: We are using an external hashmap of size ‘N’.
