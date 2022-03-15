https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

https://www.youtube.com/watch?v=3OXWEdlIGl4

![image](https://user-images.githubusercontent.com/53824950/158321024-9702f442-dbd4-4f92-8752-cef5a1a0df05.png)


![image](https://user-images.githubusercontent.com/53824950/158321099-aebb30e2-d0c2-4ecf-a4ab-36fb8b513f83.png)

Intuition: Considering the fact that we need to print the nodes, level by level, our first guess would definitely be that it must be related to level order traversal. If we closely examine, for even levels we need to go from left to right while for odd levels we need to go from right to left. 

Approach: The above idea, could be implemented with a queue. We initially keep an empty queue and push the root node. We also need to keep the left to right bool variable that keeps check of the current level we are in. As we traverse nodes in the queue, we need to push them in a temporary array. If left to right is false we need to reverse the array and push it in our data structure or else, simply push it in our data structure. In the end, when we have finished traversing the current level, we need to toggle our left to the right variable.

Time Complexity: O(N)   

Space Complexity: O(N)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while ( !nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
```
