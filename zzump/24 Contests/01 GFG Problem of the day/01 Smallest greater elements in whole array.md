int* greaterElement(int arr[], int n)
{
    // Complete the function
    int *res=new int[n];
    set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        auto it=s.find(arr[i]);
        it++;
        if(it!=s.end())
        {
            res[i]=*it;
        }
        else
        {
            res[i]= -10000000;
        }
    }
    return res;
}
  
  Time Complexity - O(NlogN)
  Space Complexity - O(N)
  
  Another approach using 2 loops
