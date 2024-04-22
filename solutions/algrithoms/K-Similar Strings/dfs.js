/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
let res;
const kSimilarity = function(s1, s2) {
    const len = s1.length;
    res = len;
    // const visited = new Set(); // 深度优先不能用 visited
    dfs(s1, s2, 0, 0, len)
    return res;
};

const dfs = (cur, s2, index, level, len) => {
    if (res <= level || res <= level + heuristic(cur, s2)) {
        return;
    }
    if (cur === s2) {
        res = res > level ? level: res;
        return;
    }
    while (index < len && s2[index] === cur[index]) {
        index++;
    }
    for (let i = index + 1; i < len; i++) {
        if (cur[i] === s2[index]) {
            const next = swap(cur, i, index);
            dfs(next, s2, index + 1, level + 1, len);
        }
    }
}

const swap = (str, i, j) => {
    const arr = [...str];
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return arr.join('');
}

const heuristic = (s1, s2) => {
    let count = 0;
    for (let i = 0; i < s1.length; i++) {
        if (s1[i] !== s2[i]) {
            count++;
        }
    }
    return Math.floor((count + 1) / 2);
}
