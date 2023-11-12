package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummyHead := &ListNode{0, head}
	pre := dummyHead
	cur := head
	for i := 0; i < n; i++ {
		cur = cur.Next
	}
	for ; cur != nil; cur = cur.Next {
		pre = pre.Next
	}
	pre.Next = pre.Next.Next
	return dummyHead.Next
}
