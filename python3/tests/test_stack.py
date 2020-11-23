import unittest

from stack import Stack


class TestStack(unittest.TestCase):

    def test_is_empty_on_creation(self):
        self.assertTrue(Stack().is_empty)

    def test_is_not_full_on_creation(self):
        self.assertFalse(Stack().is_full)

    def test_size_is_0_on_creation(self):
        self.assertEqual(0, Stack().size)

    def test_can_change_the_max_size(self):
        self.assertEqual(20, Stack(20).max_size)

    def test_default_max_size(self):
        self.assertEqual(64, Stack().max_size)

    def test_can_push_an_item(self):
        s = Stack()
        s.push(5)
        self.assertEqual(5, s.peek())

    def test_is_empty_should_be_false_when_stack_has_items(self):
        s = Stack()
        s.push(5)
        self.assertFalse(s.is_empty)

    def test_can_pop_last_item(self):
        s = Stack()
        s.push(5)
        self.assertEqual(5, s.pop())

    def test_pop_should_remove_item(self):
        s = Stack()
        s.push(5)
        self.assertEqual(5, s.pop())
        self.assertTrue(s.is_empty)

    def test_push_multiple_items_and_increment_the_size(self):
        s = Stack()
        s.push(5)
        self.assertEqual(1, s.size)
        s.push(4)
        self.assertEqual(2, s.size)
        s.push(3)
        self.assertEqual(3, s.size)

    def test_pop_decrements_size_of_stack(self):
        s = Stack()
        s.push(5)
        s.push(4)
        s.push(3)
        self.assertEqual(3, s.size)
        s.pop()
        self.assertEqual(2, s.size)
        s.pop()
        self.assertEqual(1, s.size)
        s.pop()
        self.assertEqual(0, s.size)

    def test_size_should_not_go_under_0_when_stack_is_empty(self):
        s = Stack()
        s.pop()
        s.pop()
        self.assertEqual(0, s.size)

    def test_should_not_be_able_to_push_to_full_stack(self):
        s = Stack(1)
        s.push(2)
        s.push(3)
        self.assertTrue(s.is_full)
        self.assertEqual(2, s.peek())
        self.assertTrue(s.is_full)

    def test_stack_should_not_be_full_when_removing_an_item_from_full_stack(self):
        s = Stack(1)
        s.push(2)
        self.assertTrue(s.is_full)
        self.assertEqual(2, s.pop())
        self.assertFalse(s.is_full)

    def test_pop_return_last_pushed_item(self):
        s = Stack()
        s.push(2)
        s.push(3)
        self.assertEqual(3, s.pop())
        self.assertEqual(2, s.pop())

    def test_stack_should_not_empty_if_stack_remove_items_and_size_not_0(self):
        s = Stack()
        s.push(5)
        s.push(4)
        s.push(3)
        s.pop()
        s.pop()
        self.assertFalse(s.is_empty)

    def test_stack_should_be_empty_when_removing_all_items(self):
        s = Stack()
        s.push(5)
        s.push(4)
        s.push(3)
        s.pop()
        s.pop()
        s.pop()
        self.assertTrue(s.is_empty)


if __name__ == '__main__':
    unittest.main()
