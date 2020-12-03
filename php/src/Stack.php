<?php

namespace DataStructure;

class Stack
{

    private mixed $items = [];

    private int $size = 0;


    public function __construct(public int $maxSize = 64)
    {
    }

    public function size(): int
    {
        return $this->size;
    }

    public function peek()
    {
        return $this->items[$this->size - 1];
    }

    public function push(mixed $item)
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

    public function pop(): mixed
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