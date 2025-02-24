type Trie struct {
  root *Node
}

type Node struct {
  val rune
  isEnd bool
  children []*Node
}

func Constructor() Trie {
  return Trie{ root: &Node{ val: ' ', isEnd: false, children: make([]*Node, 0) } }
}


func (this *Trie) Insert(word string)  {
  ptr := this.root
  for index, r := range word {
      var next *Node
      for _, child := range ptr.children {
          if child.val == r {
              next = child
          }
      }
      if next == nil {
          next = &Node{ val: r, isEnd: false, children: make([]*Node, 0) }
          ptr.children = append(ptr.children, next)
      }
      if index == len(word) - 1 {
          next.isEnd = true
      }
      ptr = next
  }
}


func (this *Trie) Search(word string) bool {
  ptr := this.root
  for index, r := range word {
      var next *Node
      for _, child := range ptr.children {
          if child.val == r {
              next = child
          }
      }
      if next == nil {
          return false
      }
      if index == len(word) - 1 && !next.isEnd {
          return false
      }
      ptr = next
  }
  return true
}


func (this *Trie) StartsWith(prefix string) bool {
  ptr := this.root
  for _, r := range prefix {
      var next *Node
      for _, child := range ptr.children {
          if child.val == r {
              next = child
          }
      }
      if next == nil {
          return false
      }
      ptr = next
  }
  return true
}


/**
* Your Trie object will be instantiated and called as such:
* obj := Constructor();
* obj.Insert(word);
* param_2 := obj.Search(word);
* param_3 := obj.StartsWith(prefix);
*/
