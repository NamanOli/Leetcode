


As we know that the max average for a window of size k will be of the window having sum maximum.

```
class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        int idex = 0, sum = 0, maxsum = 0;
        for(int i=0; i<k; i++)
            sum += arr[i];
        maxsum = sum;
        
        for(int i=k; i<n; i++) {
            sum += arr[i]-arr[i-k];
            if(sum > maxsum) {
                maxsum = sum;
                idex = i-k+1;
            }
        }
        
        return idex;
    }
};

```

Time Complexity - O(n)
Space Complexity - O(1)

https://practice.geeksforgeeks.org/problems/maximum-average-subarray5859/1#
