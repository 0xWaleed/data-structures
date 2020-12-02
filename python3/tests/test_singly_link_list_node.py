import unittest

from singly_link_list_node import SinglyLinkListNode


class TestSinglyLinkListNode(unittest.TestCase):

    def test_next_should_be_none_on_creation(self):
        self.assertIsNone(SinglyLinkListNode().next)

    def test_value_should_be_none_on_creation(self):
        self.assertIsNone(SinglyLinkListNode().value)

    def test_able_to_set_next(self):
        root = SinglyLinkListNode()
        node = SinglyLinkListNode()
        node.value = 5
        root.next = node
        self.assertEqual(5, root.next.value)

    def test_able_to_set_value(self):
        root = SinglyLinkListNode()
        root.value = 5
        self.assertEqual(5, root.value)

    def test_traverse(self):
        _1 = SinglyLinkListNode(5)
        _2 = SinglyLinkListNode(6)
        _3 = SinglyLinkListNode(7)
        _1.next = _2
        _2.next = _3
        self.assertEqual([5, 6, 7], _1.traverse())


if __name__ == '__main__':
    unittest.main()
