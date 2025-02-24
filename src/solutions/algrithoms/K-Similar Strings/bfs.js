/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var kSimilarity = function(s1, s2) {
  const n = s1.length
  const visited = new Set() // Set 和 Array 的性能差别非常大，Set 的底层实现应该是 HashSet
  const queue = []
  queue.push([s1, 0 ,0])
  visited.add(s1)
  while (queue.length !== 0) {
      let [s1, index, count] = queue.shift()
      if (s1 === s2) {
          return count
      }
      while (index < n && s1[index] === s2[index]) {
          index++
      }
      for (let i = index + 1; i < n; i++) {
          if (s1[i] === s2[index]) {
              const str = swap(s1, index, i)
              if (visited.has(str)) {
                  continue
              }
              queue.push([str, index + 1, count + 1])
              visited.add(str)
          }
      }
  }
}

const swap = (s, i, j) => {
  const chars = Array.from(s)
  const temp = chars[i]
  chars[i] = chars[j]
  chars[j] = temp
  return chars.join('')
}
