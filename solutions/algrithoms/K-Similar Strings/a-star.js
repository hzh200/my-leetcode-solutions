/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
const kSimilarity = function(s1, s2) {
  const len = s1.length;
  const queue = [];
  const visited = new Set(); // Set 和 Array 的性能差别非常大，Set 的底层实现应该是 HashSet
  queue.push([s1, 0, 0, len]); // cost + h(x) h() ~ 启发函数
  visited.add(s1);
  while (queue.length !== 0) {
      let [cur, index, level, _] = queue.shift();
      if (cur === s2) {
          return level;
      }
      while (index < len && cur[index] === s2[index]) {
          index++;
      }
      for (let i = index + 1; i < len; i++) {
          if (cur[i] === s2[index]) {
              const next = swap(cur, i, index);
              if (!visited.has(next)) {
                  queue.push([next, index + 1, level + 1, level + 1 + minSwap(next, s2)]);
                  queue.sort((a, b) => a[3] - b[3]);
                  visited.add(next);
              }
          }
      }
  }
  return -1;
};

const swap = (str, index1, index2) => {
  const arr = [...str];
  const temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
  return arr.join('');
};

const heuristic = (s1, s2) => {
  let count = 0;
  for (let i = 0; i < s1.length; i++) {
      if (s1[i] !== s2[i]) {
          count++;
      }
  }
  return Math.floor((count + 1) / 2);
}
