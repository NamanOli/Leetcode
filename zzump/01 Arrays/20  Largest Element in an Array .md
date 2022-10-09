https://practice.geeksforgeeks.org/problems/help-a-thief5938/1/#

```
class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
      priority_queue<pair<int,int>>pq;
       for(int i=0;i<N;i++)
       {
           pq.push({B[i],A[i]});
       }
       int ans=0;
       if(T==0)
       {
           return 0;
       }
       while(T>0&&pq.size()>0)
       {
           int a=pq.top().first;
           int b=pq.top().second;
           while(b&&T)
           {
               ans=ans+a;
               T--;
               b--;
           }
           pq.pop();
       }
       return ans;
    }
};
```
```
- Create a priority queue with pair
- If t==0 then return null
- Until t is positive and priority size is positive
- Until b is not zero or t is not zero , ad a to answer
- pop the front of priority queue
- return answers
```

```
Time Complexity - O(N)
Space Complexity - O(N)
```
