import unittest

from singly_link_list import SinglyLinkList


class TestSinglyLinkList(unittest.TestCase):

    def test_size_is_0_on_creation(self):
        self.assertEqual(0, SinglyLinkList().size)

    def test_head_should_be_none_on_creation(self):
        self.assertIsNone(SinglyLinkList().head)

    def test_tail_should_be_none_on_creation(self):
        self.assertIsNone(SinglyLinkList().tail)

    def test_adding_a_first_item_will_become_head(self):
        node = SinglyLinkList()
        node.add(5)
        self.assertIsNotNone(node.head)
        self.assertEqual(5, node.head.value)

    def test_head_should_not_be_changed_when_it_contains_value(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(4)
        self.assertEqual(5, node.head.value)

    def test_second_item_will_be_attached_to_head(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(4)
        self.assertEqual(4, node.head.next.value)

    def test_tail_should_point_to_last_added_node(self):
        node = SinglyLinkList()
        node.add(5)
        self.assertEqual(5, node.tail.value)
        node.add(4)
        self.assertEqual(4, node.tail.value)

    def test_adding_multiple_items(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(3)
        node.add(1)
        self.assertEqual(5, node.head.value)
        self.assertEqual(3, node.head.next.value)
        self.assertEqual(1, node.head.next.next.value)
        self.assertEqual(1, node.tail.value)

    def test_size_should_be_incremented_when_adding(self):
        node = SinglyLinkList()
        node.add(5)
        self.assertEqual(1, node.size)
        node.add(3)
        self.assertEqual(2, node.size)
        node.add(1)
        self.assertEqual(3, node.size)

    def test_remove_first_node(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(3)
        node.add(1)
        node.remove(5)
        self.assertEqual([3, 1], node.head.traverse())

    def test_remove_middle_node(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(3)
        node.add(1)
        node.remove(3)
        self.assertEqual([5, 1], node.head.traverse())

    def test_remove_last_node(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(3)
        node.add(1)
        node.remove(1)
        self.assertEqual([5, 3], node.head.traverse())

    def test_size_should_be_decremented_when_removing(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(3)
        node.add(1)
        node.remove(5)
        self.assertEqual(2, node.size)
        node.remove(3)
        self.assertEqual(1, node.size)
        node.remove(1)
        self.assertEqual(0, node.size)

    def test_able_to_find_a_node_by_value(self):
        node = SinglyLinkList()
        node.add(5)
        node.add(3)
        node.add(1)
        _node = node.find(3)
        self.assertEqual(3, _node.value)

    def test_return_none_when_node_not_exist(self):
        node = SinglyLinkList()
        _node = node.find(3)
        self.assertIsNone(_node)


if __name__ == '__main__':
    unittest.main()
