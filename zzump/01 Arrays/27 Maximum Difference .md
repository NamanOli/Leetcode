https://practice.geeksforgeeks.org/problems/maximum-difference-1587115620/1#

```
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      vector<int>left(n);
      vector<int>right(n);
      stack<int>st;
      for(int i=0;i<n;i++)
      {
          while((!st.empty())&&(st.top()>=A[i]))st.pop();
          if(st.empty())left[i]=0;
          else
          {
              left[i]=st.top();
          }
          st.push(A[i]);
      }
      while(!st.empty())st.pop();
      for(int i=n-1;i>=0;i--)
      {
          while((!st.empty())&&(st.top()>=A[i]))st.pop();
          if(st.empty())right[i]=0;
          else
          {
              right[i]=st.top();
          }
          st.push(A[i]);
      }
      int mx=-1;
      for(int i=0;i<n;i++)
      {
          mx=max(mx,abs(left[i]-right[i]));
      }
      return mx;
    }
};
```

```
Time Complexity - O(N)
Space Complexity - O(N)


- Create 2 vectors for storing the left and right closest smallest elements
- Create a stack for finding closest smallest number

- For left array
- Traverse the array and if element in stack are greater than current pop the top element
- If stack is empty put left[i] as 0
- else put left[i] as stack top
- push A[i] in stack

pop all elements for next iteration

- For right array
- Traverse the array in reverse order and if element in stack are greater than current pop the top element
- If stack is empty put right[i] as 0
- else put right[i] as stack top
- push A[i] in stack

- finally for loop from 0 to n and max abs value for left[i] - right[i]

```
