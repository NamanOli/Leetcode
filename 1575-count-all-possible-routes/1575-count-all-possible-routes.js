/**
 * @param {number[]} locations
 * @param {number} start
 * @param {number} finish
 * @param {number} fuel
 * @return {number}
 */
var countRoutes = function(locations, start, finish, fuel) {
    const MOD = 10**9 + 7
    const n = locations.length
    const dp = Array(n).fill().map(() => Array(fuel+1).fill(0))
    dp[start][fuel] = 1

    for(let f = fuel; f >= 0; f--){
        for(let city = 0; city < n; city++){
            if (dp[city][f] === 0) continue
        for(let nextCity = 0; nextCity < n; nextCity++){
            const fromToCity = Math.abs(locations[city] - locations[nextCity])
            if(nextCity !== city && f >= fromToCity) dp[nextCity][f - fromToCity] = (dp[nextCity][f - fromToCity] + dp[city][f]) % MOD
        }
        }
    }

    return dp[finish].reduce((acc, val) => (acc + val) % MOD, 0);
};