<?php

use DataStructure\SinglyLinkList;
use DataStructure\SinglyLinkListNode;

describe('Singly Link List', function ()
{
    describe('initialize', Closure::fromCallable('initialize_tests'));
    describe('add', Closure::fromCallable('add_tests'));
    describe('remove', Closure::fromCallable('remove_tests'));
});

function initialize_tests()
{

    beforeEach(function ()
    {
        $this->instance = new SinglyLinkList();
    });

    it('expects size to be 0', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        expect($instance->size())->toBe(0);
    });

    it('expects head is null', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        expect($instance->head())->toBe(null);
    });

    it('expects tail is null', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        expect($instance->tail())->toBe(null);
    });
}

function add_tests()
{
    beforeEach(function ()
    {
        $this->instance = new SinglyLinkList();
    });

    it('expects to add first item to head and tail', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->add(5);

        expect($instance->head()->value)->toBe(5);
        expect($instance->tail()->value)->toBe(5);
    });

    it('expects head not to be changed if it is not null', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->add(5);
        $instance->add(4);

        expect($instance->head()->value)->toBe(5);
    });

    it('expects second node to be next to the head', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->add(5);
        $instance->add(4);

        expect($instance->head()->next->value)->toBe(4);
    });

    it('expects tail to point to last node', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->add(5);
        $instance->add(4);

        expect($instance->tail()->value)->toBe(4);
    });

    it('able to add multiple items', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->add(5);
        $instance->add(4);
        $instance->add(3);
        $instance->add(2);
        $instance->add(1);

        expect($instance->head()->value)->toBe(5);
        expect($instance->head()->next->value)->toBe(4);
        expect($instance->head()->next->next->value)->toBe(3);
        expect($instance->head()->next->next->next->value)->toBe(2);
        expect($instance->head()->next->next->next->next->value)->toBe(1);
    });

    it('expects size to be incremented', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->add(5);
        expect($instance->size())->toBe(1);

        $instance->add(5);
        expect($instance->size())->toBe(2);

        $instance->add(5);
        expect($instance->size())->toBe(3);
    });
}

function remove_tests()
{
    beforeEach(function ()
    {
        $node = new SinglyLinkList();
        $node->add(2);
        $node->add(4);
        $node->add(6);
        $this->instance = $node;
    });

    it('removes first node', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->remove(2);

        expect($instance->head()->traverse())->toBe([4, 6]);
    });

    it('removes second node', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->remove(4);

        expect($instance->head()->traverse())->toBe([2, 6]);
    });

    it('removes last node', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        $instance->remove(6);

        expect($instance->head()->traverse())->toBe([2, 4]);
    });

    it('decrements the size', function ()
    {
        /** @var SinglyLinkList $instance */
        $instance = $this->instance;

        expect($instance->size())->toBe(3);
        $instance->remove(6);
        expect($instance->size())->toBe(2);
        $instance->remove(4);
        expect($instance->size())->toBe(1);
        $instance->remove(2);
        expect($instance->size())->toBe(0);

    });
}