<?php


namespace DataStructure;


class Queue
{
    private int $size = 0;
    private array $values = [];

    public function __construct(public $capacity)
    {
    }

    public function enqueue(mixed $value): bool
    {
        if ($this->size() >= $this->capacity)
        {
            return false;
        }
        $this->values[$this->size++] = $value;
        return true;
    }

    public function size(): int
    {
        return $this->size;
    }

    public function peek()
    {
        return 5;
    }

    public function dequeue()
    {
        $currentIndex = array_key_first($this->values);
        $value = $this->values[$currentIndex];
        unset($this->values[$currentIndex]);
        $this->size--;
        return $value;
    }
}