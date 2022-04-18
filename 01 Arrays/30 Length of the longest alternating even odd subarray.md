https://www.geeksforgeeks.org/length-of-the-longest-alternating-even-odd-subarray/

```
int maxEvenOdd(int arr[], int n)
{
	int res = 1;
	int curr = 1;

	for(int i = 1; i < n; i++)
	{
			if((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0)
			   ||(arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
				{
					curr++;

					res = max(res, curr);
				}
				else
					curr = 1;
	}
	
	return res;
}
```

```
- Traverse the array from 1 index till last
- If the array i is even and i-1 is odd or vice versa then increment count++
- else count =1
```
