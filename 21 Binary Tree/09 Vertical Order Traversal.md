https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

https://www.youtube.com/watch?v=q_a6lpbKJdw

https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/


Vertical Order Traversal, as the name suggests is a traversal in which we divide the binary tree in verticals from left to right, and in every vertical, we print the nodes from top to bottom.



Note:

There can be duplicate values among the nodes (here 10 is repeated twice).
If two or more nodes are overlapping at the same position(here 10 and 9), then they will be printed in ascending order. 
Solution :
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Intuition: First of all, we need to assign a vertical and a level to every node. Once we assign them, we need to figure out a suitable data structure to store them. This data structure should give us the nodes with left-side vertical first and in every vertical, top-level node should appear first.

Approach: 

We will perform a tree traversal and assign a vertical and level to every node. Based on this vertical and node, we store the node in our special data structure. For easy understanding, we break it into these steps:

Step-1: Assigning vertical and level to every node

We can perform any tree traversal for this step. Here we are taking the example of level order traversal. In the initial step when we push the node to our queue, we will push two more variables to it, one for the vertical and one for the level (both initialized as zero). Now whenever we push the left child of the node, we decrease vertical by 1 and increase level by 1, whereas whenever we push the right child of the node, we increase both vertical and level by one.



Verticals and levels will be marked as follows:



Step-2: Storing Verticals and levels to our data structure

When we are assigning the verticals and levels, it is very important to store them in a suitable data structure. After assigning we have:



In the vertical order traversal, we need to print the nodes of the left vertical first, therefore in our example, nodes of -2 vertical will be the first to  be printed. Therefore, we need a data structure that can store nodes according to their vertical value and give us the nodes of least values first. Hence we will use a map as it satisfies both criterias.



Now, we will explore X. In a single vertical we want to get the nodes by their levels. In our example, vertical 0 has nodes of three different levels, we will print level 0 first (node 1), then level 2 (node 9 and 10) and at last level 4 (node 6). Therefore as in the case of our verticals, we will again use map to store nodes level-wise inside the vertical. So, our data structure will become:



Now, we will explore Y. There can be a case that two or more nodes overlap at the same vertical and level, as with case of node 9 and node 10 at vertical 0 and level 2. In such a case we will print nodes with lesser value first. Therefore for every level, we need a data-structure which can store node values in a sorted order. Moreover, as duplicate values are allowed in our tree, our data structure needs to handle this well. This is acheived by using multiset in C++. Multiset is similar to a set which keeps elements in sorted order but also allows duplicates. In Java, we can use priority queues as it gives us the minimum value at the top.

Therefore, our final data structure will be:



Note: This is not the only choice for the data structure. You are free to choose any other data structure as well but the requirements remain the same. Instead of a multiset/priority queue, simple lists can also be used but then we will need to sort them in our last step.

Step 3: Printing vertical order traversal from our data structure

In the last step, we iterate over our verticals by using the data structure of step 2. In every iteration, we take a list(to store all nodes of that vertical) and again iterate over the levels. We then push the nodes of the level (stored in the multiset/priority queue) and push it to our vertical list. Once we iterate over all verticals we get our vertical order traversal.


![image](https://user-images.githubusercontent.com/53824950/158046885-8eb24f9c-f379-4f1c-82d1-081f80f716e2.png)

![image](https://user-images.githubusercontent.com/53824950/158046888-27f13543-af00-4b4f-8224-a316e7d43d52.png)

![image](https://user-images.githubusercontent.com/53824950/158046889-b16cbd2a-e7e6-4208-bb0d-795e80dd6740.png)

![image](https://user-images.githubusercontent.com/53824950/158046891-6361e753-f8dd-40b1-b457-b161f763c9dd.png)

![image](https://user-images.githubusercontent.com/53824950/158046900-44d3b723-ae24-4c05-8e75-d8fdf957c815.png)

![image](https://user-images.githubusercontent.com/53824950/158046902-91adb616-aa76-48bf-a461-631f11eec1e2.png)

![image](https://user-images.githubusercontent.com/53824950/158046905-05fea0e8-4df7-4806-bff1-7d6e9cd8dc61.png)

![image](https://user-images.githubusercontent.com/53824950/158046912-f00ecfbf-e208-4b51-a685-4f0b0bf4b6fb.png)

The Vertical Traversal is : 

4 

2 5 

1 9 10 6 

3 

10 

Time Complexity: O(N*logN*logN*logN)

Space Complexity: O(N)

```
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
```
