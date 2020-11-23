

from stack import Stack

if __name__ == '__main__':
    s = Stack(3)
    s.push(5)
    s.push(8)
    s.push(9)
    s.push(10)
    s.pop()
    s.pop()
    print(s)

