/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {string[]}
 */
const wordBreak = function(s, wordDict) {
    const res = [];
    const tmp = [];
    backtrack(s, 0, wordDict, tmp, res);
    return res;
};

const backtrack = (s, index, wordDict, tmp, res) => {
    if (index === s.length) {
        res.push(tmp.join(' '));
        return;
    }
    for (const word of wordDict) {
        if (s.substring(index, index + word.length) === word) {
            tmp.push(word);
            backtrack(s, index + word.length, wordDict, tmp, res);
            tmp.pop();
        }
    }
};