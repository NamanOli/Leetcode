 function countPaths(grid) {
        const m = grid.length;
        const n = grid[0].length;
        const modulo = 1000000007;
        const memo= new Array(m).fill(0).map(() => new Array(n).fill(0));
        let count = 0;

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                const t = maxCell(grid, memo, i, j, 0);
                count = (count + t) % modulo;
            }
        }

        return count;
    }

    function maxCell(grid, memo, i, j, val) {
        const m = grid.length;
        const n = grid[0].length;
        const modulo = 1000000007;
        if (i < 0 || i === m || j < 0 || j === n) return 0;
        if (grid[i][j] <= val) return 0;
        if (memo[i][j] !== 0) return memo[i][j];
        let res = 1;

        res = (res + maxCell(grid, memo, i + 1, j, grid[i][j])) % modulo;
        res = (res + maxCell(grid, memo, i - 1, j, grid[i][j])) % modulo;
        res = (res + maxCell(grid, memo, i, j + 1, grid[i][j])) % modulo;
        res = (res + maxCell(grid, memo, i, j - 1, grid[i][j])) % modulo;

        memo[i][j] = res;
        return res;
    }
