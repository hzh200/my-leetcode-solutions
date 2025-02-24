func findWords(board [][]byte, words []string) []string {
  root := Node{val: 0, isLeaf: false, word: "", children: make([]*Node, 0)}
  trie := Trie{root: &root, cur: &root}
  for _, word := range words {
      trie.AddNode(word)
  }
  stash := make(map[string]string)
  n, m := len(board), len(board[0])
  visited := make([][]int, n)
  for i := 0; i < n; i++ {
      visited[i] = make([]int, m)
  }
  for i := 0; i < n; i++ {
      for j := 0; j < m; j++ {
          findWordsCore(board, &trie, i, j, visited, stash)
      }
  }

  res := make([]string, 0)
  for k := range stash {
      res = append(res, k)
  }
  return res
}

func findWordsCore(board [][]byte, trie *Trie, x int, y int, visited [][]int, stash map[string]string) {
  if visited[x][y] == 1 {
      return
  }
  for _, child := range trie.cur.children {
      if child.val == board[x][y] {
          if child.isLeaf {
              stash[child.word] = child.word
          }

          pre := trie.cur
          trie.cur = child
          visited[x][y] = 1
          if x > 0 {
              findWordsCore(board, trie, x - 1, y, visited, stash)
          }
          if x < len(board) - 1 {
              findWordsCore(board, trie, x + 1, y, visited, stash)
          }
          if y > 0 {
              findWordsCore(board, trie, x, y - 1, visited, stash)
          }
          if y < len(board[0]) - 1 {
              findWordsCore(board, trie, x, y + 1, visited, stash)
          }
          visited[x][y] = 0
          trie.cur = pre
      }
  }
}

type Node struct {
  val byte
  isLeaf bool
  word string
  children []*Node
}

type Trie struct {
  root *Node
  cur *Node
}

func (trie *Trie) AddNode(word string) {
  cur := trie.root
  for i, r := range []byte(word) {
      pre := cur
      for _, child := range cur.children {
          if child.val == r {
              cur = child
              break
          }
      }
      if pre == cur {
          newNode := Node{val: r, isLeaf: false, word: "", children: make([]*Node, 0)}
          cur.children = append(cur.children, &newNode)
          cur = &newNode
      }
      if i == len(word) - 1 {
          cur.isLeaf = true
          cur.word = word
      }
  }
}

