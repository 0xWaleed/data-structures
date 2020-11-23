class Stack:
    def __init__(self, max_size=64):
        self.size = 0
        self.max_size = max_size
        self.is_full = False
        self.is_empty = True
        self.__items = []

    def push(self, item):
        if self.size < self.max_size:
            self.__items.append(item)
            self.is_empty = False
            self.size += 1
        self.is_full = True

    def peek(self):
        return self.__items[self.size - 1]

    def pop(self):
        if self.size > 0:
            self.size -= 1
        else:
            return None
        self.is_full = self.size >= self.max_size
        self.is_empty = self.size == 0
        item = self.__items[self.size]
        del self.__items[self.size - 1]
        return item

    def __str__(self):
        self.__items.reverse()
        header = '[ {}, {} ]\n'.format(
            str(self.is_empty).replace('False', 'not empty').replace('True', 'empty')
            , str(self.is_full).replace('True', 'full').replace('False', 'not full'))
        items_as_string = '\n'.join(str(x) for x in self.__items) + '\n'
        footer = ('~' * 12)
        return header + items_as_string + footer
