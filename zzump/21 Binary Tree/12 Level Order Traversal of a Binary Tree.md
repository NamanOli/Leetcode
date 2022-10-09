https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/

https://youtu.be/EoAsWbO7sqg

https://leetcode.com/problems/binary-tree-level-order-traversal/

![image](https://user-images.githubusercontent.com/53824950/158061964-31ed2391-6b03-425d-b5b1-44c668e26604.png)

Let us consider the example 1 given above.

We need to print a level by level traversal. Let us say, we store all the levels in a data structure named ‘ans’. We can use a vector<int> or List<int> to store our answer.

Now we need to store the first level to ‘ans’. In any given binary tree, the first level will always be the root node, so we can easily store it.


Next, we want to store the second level, this can be done by pushing the left child of root and then the right child of the root to our ‘ans’ data structure.


Now what about the next level? We just can’t keep writing root→left→left / root→left→right and so on to reach further levels. We need an additional data structure to store all the nodes of a level. When we are at level 1, we want its left child to be stored first, followed by the right child as the next level and store it in our data structure. Similarly at level 2, we want to access first the left child (which was added first to the data structure), to store the nodes of the next level.

As there is a first-in first-out (FIFO) operation, we will use the queue data structure.

Approach:

The algorithm steps are stated as:

Take a queue data structure and push the root node to the queue.
Set a while loop which will run till our queue is non-empty.
In every iteration, pop out from the front of the queue and assign it to a variable (say temp).
If temp has a left child, push it to the queue.
If temp has a right child, push it to the queue.
At last push the value of the temp node to our “ans” data structure.
Dry Run: 

We will discuss example 1.


First we insert the root node to the queue.
We set our while loop and pop its front element as temp Then we inserted the left child followed by the right child of temp to the queue.
Then we push the temp value to our ans list.
Then we follow these steps for all nodes till the time our queue is non-empty, as shown in the figures below.



![image](https://user-images.githubusercontent.com/53824950/158061985-afa7a86b-f64a-453f-a63f-19980e427b64.png)

  ![image](https://user-images.githubusercontent.com/53824950/158061989-80a473ba-7ab1-4959-a152-4a651bb3b9b0.png)

  ![image](https://user-images.githubusercontent.com/53824950/158061999-c8e19b2d-24aa-4fc2-9238-78ef4cbcffe0.png)

  
  ![image](https://user-images.githubusercontent.com/53824950/158062002-4dc45e00-4d4c-44a4-8aab-a17d6679cdb3.png)

  Time Complexity: O(N)

Space Complexity: O(N)
  
  What if we have to print the level numbers as well?

In the above approach we print the nodes level-wise but we can’t differentiate from our ans that whether two nodes are from the same level or not.

To store the level-order traversal along with individual levels stored together ( [[20],[10,30],[5,15,25,35]]), we need to make the following changes:

First we need to declare a 2d array to store our answer( vector<vector<int>> in C++ and List<List<int>> in Java).
Inside the while loop, first we declare a list to store nodes of a level (say level), then we need to set another for loop, which iterates for the size of the queue and inside this for loop we need to write the logic which we had discussed in the first approach
The for loop ensures that all the nodes of a particular level are inserted together and when the iteration of the for loop ends, the queue contains the elements of only one level at a time.
Inside the for loop we push the value of temp to ‘level’.
After the for loop ends, we push ‘level’ to the answer.
  
  
 
  
  
  ```
  class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                level.push_back(node->val); 
            }
            ans.push_back(level); 
        }
        return ans; 
    }
};
  ```
  
  
