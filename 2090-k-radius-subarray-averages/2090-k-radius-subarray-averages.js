var getAverages = function(nums, k) {
    const ans = new Array(nums.length).fill(-1);

    if (nums.length < 2 * k + 1) return ans;

    let sum = 0;

    for(let i = 0; i <= 2 * k; i++) 
        sum += nums[i];
    
    for(let i = k; i + k < nums.length; i++) {
        ans[i] = Math.floor(sum / (2 * k + 1));
        sum -= nums[i - k];
        sum += nums[i + k + 1];
    }

    return ans;
};