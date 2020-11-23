<?php

namespace DataStructure;

class Stack
{

    /** @var mixed */
    private $items = [];

    private int $size = 0;
    private bool $isFull = false;
    private bool $isEmpty = true;

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
        $this->isEmpty = false;
        $this->isFull = $this->size >= $this->maxSize();
    }

    public function isFull(): bool
    {
        return $this->isFull;
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
        $this->isFull = $this->size >= $this->maxSize();
        $this->isEmpty = $this->size === 0;
        return $item;
    }

    public function isEmpty(): bool
    {
        return $this->isEmpty;
    }
}