<?php

namespace DataStructure;

class Stack
{

    /** @var mixed */
    private $items = [];

    private int $size = 0;

    private int $maxSize;

    public function __construct(int $maxSize = 64)
    {
        $this->maxSize = $maxSize;
    }

    public function size(): int
    {
        return $this->size;
    }

    public function peek()
    {
        return $this->items[$this->size - 1];
    }

    public function push($item)
    {
        if ($this->isFull())
        {
            return;
        }
        $this->items[$this->size++] = $item;
    }

    public function isFull(): bool
    {
        return $this->size() >= $this->maxSize();
    }

    public function maxSize(): int
    {
        return $this->maxSize;
    }

    public function pop()
    {
        if ($this->isEmpty())
        {
            return null;
        }
        $item = $this->items[$this->size - 1];
        unset($this->items[$this->size-- - 1]);
        return $item;
    }

    public function isEmpty(): bool
    {
        return $this->size() === 0;
    }
}