/**
 * @param {number[][]} grid
 * @return {number}
 */
const largestIsland = (grid) => {
    const n = grid.length;
    const islands = [];
    const belong = Array(n).fill(-1).map(() => Array(n).fill(-1));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1 && belong[i][j] === -1) {
                islands.push(search(i, j, n, islands.length, grid, belong));
            }
        }
    }
    let res = 0;
    for (const island of islands) {
        res = Math.max(res, island);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) 
                continue;
            const conjunctions = new Set();
            if (i > 0 && grid[i - 1][j] === 1) {
                conjunctions.add(belong[i - 1][j]);
            }
            if (j > 0 && grid[i][j - 1] === 1) {
                conjunctions.add(belong[i][j - 1]);
            }
            if (i < n - 1 && grid[i + 1][j] === 1) {
                conjunctions.add(belong[i + 1][j]);
            }
            if (j < n - 1 && grid[i][j + 1] === 1) {
                conjunctions.add(belong[i][j + 1]);
            }
            let size = 1;
            for (const conjunction of Array.from(conjunctions)) {
                size += islands[conjunction];
            }
            res = Math.max(res, size);
        }
    }
    return res;
};

const search = (i, j, n, islandNumber, grid, belong) => {
    if (grid[i][j] === 0 || belong[i][j] !== -1)
        return 0;
    belong[i][j] = islandNumber;
    let size = 1;
    if (i > 0) {
        size += search(i - 1, j, n, islandNumber, grid, belong);
    }
    if (i < n - 1) {
        size += search(i + 1, j, n, islandNumber, grid, belong);
    }
    if (j > 0) {
        size += search(i, j - 1, n, islandNumber, grid, belong);
    }
    if (j < n - 1) {
        size += search(i, j + 1, n, islandNumber, grid, belong);
    }
    console.log(size);
    return size;
};