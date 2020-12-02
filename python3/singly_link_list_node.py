class SinglyLinkListNode:
    next: 'SinglyLinkListNode'

    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next

    def traverse(self):
        values = []
        node = self
        while node is not None:
            values.append(node.value)
            node = node.next
        return values
