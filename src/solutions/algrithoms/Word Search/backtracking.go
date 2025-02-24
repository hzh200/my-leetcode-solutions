func exist(board [][]byte, word string) bool {
  m, n := len(board), len(board[0])
  visited := make([][]bool, m)
  for i := 0; i < m; i++ {
      visited[i] = make([]bool, n)
  }
  for i := 0; i < m; i++ {
      for j := 0; j < n; j++ {
          if existCore(board, word, 0, i, j, visited) {
              return true
          }
      }
  }
  return false
}

func existCore(board [][]byte, word string, index int, i int, j int, visited [][]bool) bool {
  if visited[i][j] || board[i][j] != word[index] {
      return false
  }
  if index == len(word) - 1 {
      return true
  }
  visited[i][j] = true
  if i < len(board) - 1 && existCore(board, word, index + 1, i + 1, j, visited) {
      return true
  }
  if i > 0 && existCore(board, word, index + 1, i - 1, j, visited) {
      return true
  }
  if j < len(board[0]) - 1 && existCore(board, word, index + 1, i, j + 1, visited) {
      return true
  }
  if j > 0 && existCore(board, word, index + 1, i, j - 1, visited) {
      return true
  }
  visited[i][j] = false
  return false;
}
