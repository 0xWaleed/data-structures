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

    public function peek(): mixed
    {
        $currentIndex = array_key_first($this->values);
        if ($currentIndex === null)
        {
            return null;
        }
        return $this->values[$currentIndex];
    }

    public function dequeue(): mixed
    {
        $currentIndex = array_key_first($this->values);
        if ($currentIndex === null)
        {
            return null;
        }
        $value = $this->values[$currentIndex];
        unset($this->values[$currentIndex]);
        $this->size--;
        return $value;
    }
}