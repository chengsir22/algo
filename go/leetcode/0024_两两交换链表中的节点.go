package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// func swapPairs(head *ListNode) *ListNode {
// 	if head == nil || head.Next == nil {
// 		return head
// 	}
// 	next:= head.Next
// 	head.Next = swapPairs(next.Next)
// 	next.Next = head
// 	return next
// }

func swapPairs(head *ListNode) *ListNode {
	dummyHead := &ListNode{0, head}
	cur := dummyHead
	for cur.Next != nil && cur.Next.Next != nil {
		node1, node2 := cur.Next, cur.Next.Next
		cur.Next, node1.Next, node2.Next = node2, node2.Next, node1
		cur = node1
	}
	return dummyHead.Next
}
