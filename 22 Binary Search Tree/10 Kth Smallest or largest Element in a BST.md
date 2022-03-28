https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

https://www.youtube.com/watch?v=9TJYWh0adfk

![image](https://user-images.githubusercontent.com/53824950/160413589-b216a2cf-27e6-4a79-8eeb-1cec99afeeeb.png)

![image](https://user-images.githubusercontent.com/53824950/160413978-0d85c946-4e25-45f9-981e-7ed52e8acc37.png)

![image](https://user-images.githubusercontent.com/53824950/160414243-4ff5cf1b-0333-4b33-b3e6-af8e9025fab1.png)

![image](https://user-images.githubusercontent.com/53824950/160417426-9e67da5f-7584-484b-805d-abbf6fb08adf.png)

![image](https://user-images.githubusercontent.com/53824950/160417894-a633e19b-83de-45ab-9de8-2fdb6ba36742.png)

![image](https://user-images.githubusercontent.com/53824950/160418433-6f8be054-b43d-4851-b80d-98641f8d3dc1.png)

```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        int cnt = 0; 
        while(true){
            if(node != null){
                stack.push(node);
                node = node.left;
            }
            else{
                if(stack.isEmpty()){
                    break;
                }
                node = stack.pop();
                // inorder.add(node.val);
                cnt++; 
                if(cnt == k) return node.val; 
                node = node.right;
            }
        }
        return -1; 
    }
}
```

Time Complexity: O(min(K,N))

Space Complexity: O(min(K,N))
