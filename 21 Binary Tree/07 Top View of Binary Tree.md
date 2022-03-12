https://takeuforward.org/data-structure/top-view-of-a-binary-tree/

youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24

https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Intuition:  We can mark straight lines like in the image below and mark them with +ve and -ve indexes. The first node of every line will be my top view.

![image](https://user-images.githubusercontent.com/53824950/158026713-dfadc202-fa9f-407d-8559-5db838583aee.png)


Approach: 

First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
Then we need a map data structure to store the lines and the nodes. This map will store the data in the form of sorted orders of keys(Lines).
Here we will follow the level order traversal.
Traverse through the nodes starting with root,0 and store them to the queue.
Until the queue is not empty, store the node  and line no. in 2 separate variable .
Then check if that line is present in the map or not
If not present then store the line and the node->val to the map
Otherwise store the node->left and node->right along with there line nos. to the queue.
Then print the node->val from the map

Time Complexity: O(N)

Space Complexity: O(N)

```
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};
```
