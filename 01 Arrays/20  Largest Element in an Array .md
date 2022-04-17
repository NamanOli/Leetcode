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
