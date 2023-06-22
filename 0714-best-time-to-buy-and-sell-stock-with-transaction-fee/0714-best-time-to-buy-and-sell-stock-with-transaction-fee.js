var maxProfit = function(P, F) {
    let len = P.length, buying = 0, selling = -P[0]
    for (let i = 1; i < len; i++) {
        buying = Math.max(buying, selling + P[i] - F)
        selling = Math.max(selling, buying - P[i])
    }
    return buying
};