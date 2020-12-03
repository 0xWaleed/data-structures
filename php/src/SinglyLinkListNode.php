<?php


namespace DataStructure;


class SinglyLinkListNode
{
    public function __construct(public $value = null, public ?SinglyLinkListNode $next = null)
    {
    }

    public function traverse(): array
    {
        $arr = [];

        if (! $this->value)
        {
            return $arr;
        }

        $arr[] = $this->value;

        if (! $this->next)
        {
            return $arr;
        }

        $values = $this->next->traverse();
        $arr = array_merge($arr, $values);

        return $arr;
    }

    public function remove(mixed $value)
    {

    }
}