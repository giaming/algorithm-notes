# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head and not head.next:
            return head

        dummy_node = ListNode(-1)
        dummy_node.next = head

        prev, curr = head, head.next
        while curr:
            if curr.val >= prev.val:
                prev = curr
                curr = curr.next
            else:
                # 找到小于 curr.val 的最大的节点
                p = dummy_node
                # 说明：这里的 p.next 不可能为空
                # 因为 p 从头开始，最远可以到达的节点是 curr 的前一个节点
                # 所以 p.next 不可能为 None，我这里加上 p.next 的判空，是我个人的习惯哟~
                while p.next and p.next.val < curr.val:
                    p = p.next
                # 将 curr 插入到 p 和 p.next 之间
                prev.next = curr.next
                curr.next = p.next
                p.next = curr

                curr = prev.next
        return dummy_node.next