var longestArithSeqLength = function(nums) {
     const n = nums.length;
  if (n <= 2) return n;

  // Initialize a dynamic programming table
  const dp = new Array(n);
  for (let i = 0; i < n; i++) {
    dp[i] = new Map();
  }

  let maxLength = 2; // Minimum length of arithmetic subsequence is 2

  // Traverse the array
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const diff = nums[j] - nums[i];

      // Check if we have seen this difference before
      if (dp[i].has(diff)) {
        dp[j].set(diff, dp[i].get(diff) + 1);
      } else {
        // If not, set the initial length of the subsequence to 2
        dp[j].set(diff, 2);
      }

      // Update the maximum length
      maxLength = Math.max(maxLength, dp[j].get(diff));
    }
  }

  return maxLength;
};