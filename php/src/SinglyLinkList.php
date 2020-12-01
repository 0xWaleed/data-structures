<?php


namespace DataStructure;


class SinglyLinkList
{

    private ?SinglyLinkListNode $head = null;
    private ?SinglyLinkListNode $tail = null;
    private int $size = 0;

    public function size(): int
    {
        return $this->size;
    }

    public function tail(): ?SinglyLinkListNode
    {
        return $this->tail;
    }

    public function add($value)
    {
        $node = new SinglyLinkListNode($value);
        $this->size++;
        if (! $this->head)
        {
            $this->head = $node;
            $this->tail = $this->head;
            return;
        }

        $this->tail->next = $node;
        $this->tail = $node;
    }

    public function remove($value)
    {
        $node = $this->head();
        $left = null;

        while ($node)
        {
            if ($value == $node->value)
            {
                if (! $left)
                {
                    $this->head = $node->next;
                }
                else
                {
                    $left->next = $node->next;
                }
                $this->size--;
                break;
            }

            $left = $node;
            $node = $node->next;
        }
    }

    public function head(): ?SinglyLinkListNode
    {
        return $this->head;
    }

    public function find($value): ?SinglyLinkListNode
    {
        $node = $this->head();

        while ($node)
        {
            if ($value == $node->value)
            {
                return $node;
            }

            $node = $node->next;
        }

        return null;
    }
}