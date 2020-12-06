class Queue:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.__size = 0
        self.__items = []

    @property
    def size(self):
        return self.__size

    def enqueue(self, item: object) -> bool:
        if self.size >= self.capacity:
            return False
        self.__size += 1
        self.__items.append(item)
        return True

    def dequeue(self) -> object:
        if self.size < 1:
            return None
        item = self.__items[0]
        del self.__items[0]
        self.__size -= 1
        return item

    def peek(self) -> object:
        if self.size < 1:
            return None
        return self.__items[0]
