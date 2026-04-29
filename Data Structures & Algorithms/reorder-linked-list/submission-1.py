# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next or not head.next.next:
            return

        d=deque()
        cur=head
        while cur:
            d.append(cur)
            cur=cur.next

        dum=ListNode(0)
        cur=dum

        while len(d)>1:
          
            a=d.popleft()
            b=d.pop()

            cur.next=a
            a.next=None
            cur=cur.next

            cur.next=b
            b.next=None
            cur=cur.next

        if d:
            cur.next=d.pop()
            cur.next.next=None

        head.val=dum.next.val
        head.next=dum.next.next
        