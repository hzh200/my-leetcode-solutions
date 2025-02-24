/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
  const dp = Array(s.length + 1);
  for (let i = 0; i < s.length + 1; i++) {
      dp[i] = Array(p.length + 1).fill(false);
  }
  dp[0][0] = true;

  for (let i = 1; i <= p.length; i++) {
      if (i < p.length && p[i] === '*') {
          dp[0][i + 1] = true;
          i++;
      } else {
          break;
      }
  }

  for (let i = 1; i <= s.length; i++) {
      for (let j = 1; j <= p.length; j++) {
          if (j < p.length && p[j] === '*') {
              if (p[j - 1] === '.') {
                  dp[i][j] = false;
                  dp[i][j + 1] = dp[i][j - 1] || dp[i - 1][j];
              }
              dp[i][j + 1] = dp[i][j - 1] || dp[i - 1][j + 1] && (p[j - 1] === '.' || p[j - 1] === s[i - 1]);
              j++;
          } else {
              if (p[j - 1] === '.' || p[j - 1] === s[i - 1]) {
                  dp[i][j] = dp[i - 1][j - 1];
              } else {
                  dp[i][j] = false;
              }
          }
      }
  }
  // console.log(dp);
  return dp[s.length][p.length];
};
