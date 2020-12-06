import unittest

from queue import Queue


class TestQueue(unittest.TestCase):

    def test_size_is_0_on_creation(self):
        self.assertEqual(0, Queue(5).size)

    def test_capacity_is_as_given_in_constructor(self):
        self.assertEqual(3, Queue(3).capacity)

    def test_enqueue_add_item_and_return_true(self):
        queue = Queue(5)
        self.assertTrue(queue.enqueue(5))
        self.assertTrue(queue.enqueue("Hello"))
        self.assertTrue(queue.enqueue(False))
        self.assertTrue(queue.enqueue(1.5))

    def test_enqueue_increments_size_on_successful_adding(self):
        queue = Queue(5)
        queue.enqueue(5)
        self.assertEqual(1, queue.size)
        queue.enqueue("Hello")
        self.assertEqual(2, queue.size)
        queue.enqueue(False)
        self.assertEqual(3, queue.size)

    def test_enqueue_return_false_and_not_increment_the_size_if_queue_full(self):
        queue = Queue(3)
        queue.enqueue(5)
        queue.enqueue("Hello")
        queue.enqueue(False)
        self.assertFalse(queue.enqueue(99))
        self.assertEqual(3, queue.size)

    def test_dequeue_return_first_add_item_and_remove_it(self):
        queue = Queue(3)
        queue.enqueue(5)
        queue.enqueue("Hello")
        queue.enqueue(False)
        self.assertEqual(5, queue.dequeue())
        self.assertEqual("Hello", queue.dequeue())
        self.assertEqual(False, queue.dequeue())

    def test_dequeue_decrements_the_size(self):
        queue = Queue(3)
        queue.enqueue(5)
        queue.enqueue("Hello")
        queue.enqueue(False)
        queue.dequeue()
        self.assertEqual(2, queue.size)
        queue.dequeue()
        self.assertEqual(1, queue.size)
        queue.dequeue()
        self.assertEqual(0, queue.size)

    def test_dequeue_returns_none_when_queue_is_empty(self):
        self.assertIsNone(Queue(3).dequeue())

    def test_peek_returns_first_added_value_without_removing_it(self):
        queue = Queue(3)
        queue.enqueue(5)
        queue.enqueue(4)
        self.assertEqual(5, queue.peek())
        self.assertEqual(2, queue.size)

    def test_peek_returns_none_when_queue_is_empty(self):
        self.assertIsNone(Queue(3).peek())


if __name__ == '__main__':
    unittest.main()
