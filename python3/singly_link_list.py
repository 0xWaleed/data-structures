from singly_link_list_node import SinglyLinkListNode


class SinglyLinkList:
    head: SinglyLinkListNode = None
    tail: SinglyLinkListNode = None
    __size: int = 0

    @property
    def size(self):
        return self.__size

    def add(self, value):
        node = SinglyLinkListNode(value)
        self.__size += 1
        if self.head is None:
            self.head = node
            self.tail = node
            return

        self.tail.next = node
        self.tail = node

    def remove(self, value):
        node: SinglyLinkListNode = self.head
        left: SinglyLinkListNode = None
        self.__size -= 1
        while node is not None:

            if value == node.value:
                if left is None:
                    self.head = node.next
                else:
                    left.next = node.next

            left = node
            node = node.next
