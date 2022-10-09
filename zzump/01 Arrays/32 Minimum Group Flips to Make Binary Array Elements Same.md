https://www.geeksforgeeks.org/minimum-group-flips-to-make-binary-array-elements-same/

```
Input : arr[] = {1, 1, 0, 0, 0, 1}
Output :  From 2 to 4
Explanation : We have two choices, we make all 0s or do all 1s.  We need to do two group flips to make all elements 0 and one group flip to make all elements 1.  Since making all elements 1 takes least group flips, we do this.
Input : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
Output :  
From 1 to 3
From 5 to 6
From 8 to 8
Input : arr[] = {0, 0, 0}
Output :  
Explanation : Output is empty, we need not to make any change
Input : arr[] = {1, 1, 1}
Output :  
Explanation : Output is empty, we need not to make any change
Input : arr[] = {0, 1}
Output :   
From 0 to 0  
OR
From 1 to 1
Explanation :  Here number of flips are same either we make all elements as 1 or all elements as 0.


Time Complexity:  O(n)
Auxiliary Space:  O(1)


```


```
void printGroups(int arr[], int n)
{ 
	for(int i = 1; i < n; i++)  /// traverse from 1 till n
	{
		if(arr[i] != arr[i - 1]) // if the elements are different
		{
			if(arr[i] != arr[0]) // if element is different from first index element then that will be one answer from...
                cout << "From " << i << " to ";
			else
                cout << i - 1 << endl; // if we find element similar to first then element before that has to b swapped
		}
	}

	if(arr[n - 1] != arr[0])
        cout << n - 1 << endl;
}
```
