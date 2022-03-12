https://takeuforward.org/data-structure/right-left-view-of-binary-tree/

https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=25

Intuition: We have to do a Recursive Level Order Traversal.

Root Right Left     —-> for Right view

Root Left Right     —–> for Left view

The First Node of every level will be the Right View.

The last Node of Every level will be the Left View.



Approach: 

Create an vector data structure inside both the left and the right side view function
Call for the recursive _left and recursive_right function respectively with the (root,level,vector). Here level will be initially passed as 0.
Return the vector.
Now in the recursive_left function
If vector size is equal to the level then push_back its node value to the vector data structure.
Otherwise call recursive_left for (node->left,level+1,vector)
Call recursive_left for (node->right,level+1,vector)
Now in the recursive_right function
If vector size is equal to the level then push_back its node value to the vector data structure.
Otherwise call recursive_right for (node->right,level+1,vector)
Call recursive_right for (node->left,level+1,vector)
Tip: The Code for the Left and the Right View is almost identical. 

In the Right view code first, you have to call the recursive function for the right then the left node

AND

![image](https://user-images.githubusercontent.com/53824950/158020903-e80c66fc-c253-4ee9-a487-3764b70356c4.png)

![image](https://user-images.githubusercontent.com/53824950/158020955-170170df-a997-4874-9aa7-aebc541ea878.png)


In the Right view code first, you have to call the recursive function for the Left than the right node

Time Complexity: O(N)

Space Complexity: O(H)       (H -> Height of the Tree)


```
void recursion(Node * root,int level,vector<int > &res)
{
    if(root==NULL)
   {
       return ;
   }
   if(res.size()==level)res.push_back(root->data);
   recursion(root->left,level+1,res);
   recursion(root->right,level+1,res);
}
vector<int> leftView(Node *root)
{
   vector<int>res;
   recursion(root,0,res);
   return res;
}
```



