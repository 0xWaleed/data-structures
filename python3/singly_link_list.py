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
