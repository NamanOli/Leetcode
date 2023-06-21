/**
 * @param {number[]} nums
 * @param {number[]} cost
 * @return {number}
 */
var minCost = function(nums, cost) {
       nums = nums.map((num, i) => [num, cost[i]])
       .sort(([b], [a]) => b - a);

   let prefixCost = 0;
   const costSum = cost.reduce((acc, cur) => acc + cur);
   const [median] = nums.find(([_, cost]) => (prefixCost += cost) >= costSum / 2);
    
   return nums
        .reduce((acc, [num, cost]) => acc + Math.abs(num - median) * cost, 0);

};