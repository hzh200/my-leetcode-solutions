/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {string[]}
 */
const wordBreak = function(s, wordDict) {
    const storage = new Map();
    return backtrack(s, 0, wordDict, storage).map((res, _index, _array) => {
        return res.join(' ');
    });
};

const backtrack = (s, index, wordDict, storage) => {
    if (index === s.length) {
        return [[]];
    }
    if (!storage.has(index)) {
        const res = [];
        for (const word of wordDict) {
            if (s.substring(index, index + word.length) === word) {
                backtrack(s, index + word.length, wordDict, storage).forEach((subRes) => {
                    res.push([word, ...subRes]);
                });
            }
        }
        storage.set(index, res);
    }
    return storage.get(index);
};