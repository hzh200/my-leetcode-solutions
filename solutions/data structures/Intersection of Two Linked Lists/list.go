/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func getIntersectionNode(headA, headB *ListNode) *ListNode {
  countA := 0
  for p := headA; p != nil; p = p.Next {
      countA++
  }
  countB := 0
  for p := headB; p != nil; p = p.Next {
      countB++
  }
  if countA > countB {
      for i := 0; i < countA - countB; i++ {
          headA = headA.Next
      }
  } else {
      for i := 0; i < countB - countA; i++ {
          headB = headB.Next
      }
  }
  for headA != headB {
      headA = headA.Next
      headB = headB.Next
  }
  return headA
}
