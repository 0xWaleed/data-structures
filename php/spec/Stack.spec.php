<?php

use DataStructure\Stack;


describe('Stack', function ()
{
    it('should be exist', function ()
    {
        expect(new Stack())->toBeAnInstanceOf('\DataStructure\Stack');
    });

    initialization_tests();

    push_tests();

    peek_tests();

    pop_tests();

    isEmpty_tests();

    isFull_tests();
});

function initialization_tests(): void
{
    describe('initialization', function ()
    {
        it('expects the size to be zero', function ()
        {
            $s = new Stack();

            $size = $s->size();
            expect($size)->toBe(0);
        });

        it('empty', function ()
        {
            $s = new Stack();

            $size = $s->isEmpty();
            expect($size)->toBe(true);
        });

        it('should not to be full', function ()
        {
            $s = new Stack();

            $size = $s->isFull();
            expect($size)->toBe(false);
        });

        it('has a default max size as 64', function ()
        {
            $s = new Stack();

            $size = $s->maxSize();
            expect($size)->toBe(64);
        });

        it('should able to change the max size', function ()
        {
            $s = new Stack(5);

            $size = $s->maxSize();
            expect($size)->toBe(5);
        });
    });
}

function peek_tests(): void
{
    describe('peek', function ()
    {
        it('should be exist', function ()
        {
            expect(method_exists(new Stack(), 'peek'))->toBeTruthy();
        });

        it('should return the top of stack without removing it', function ()
        {
            $s = new Stack();
            $s->push(5);
            expect($s->peek())->toBe(5);
            expect($s->size())->toBe(1);
        });

        it('peeks last pushed item', function ()
        {
            $s = new Stack();
            $s->push(5);
            expect($s->peek())->toBe(5);
            $s->push(6);
            expect($s->peek())->toBe(6);
            $s->push('a');
            expect($s->peek())->toBe('a');
        });
    });
}

function push_tests(): void
{
    describe('push', function ()
    {
        it('should increment the size', function ()
        {
            $s = new Stack();
            $s->push(5);
            expect($s->size())->toBe(1);
        });

        it('pushes item on top', function ()
        {
            $s = new Stack();
            $s->push(5);
            expect($s->peek())->toBe(5);
        });

        it('pushes multiple elements', function ()
        {
            $s = new Stack();
            $s->push(5);
            $s->push(4);
            $s->push(3);
            expect($s->size())->toBe(3);
        });

        it('pushes the exact item', function ()
        {
            $s = new Stack();
            $s->push(5);
            $s->push('a');
            $s->push(5.2);
            expect($s->pop())->toBe(5.2);
            expect($s->pop())->toBe('a');
            expect($s->pop())->toBe(5);
        });

        it('should not add the item if stack already full', function ()
        {
            $s = new Stack(1);
            $s->push(3);
            $s->push(6);
            expect($s->peek())->toBe(3);
        });
    });
}


function pop_tests()
{
    describe('pop', function ()
    {
        it('return the top item', function ()
        {
            $s = new Stack();
            $s->push(5);
            expect($s->pop())->toBe(5);
        });

        it('decrements the size', function ()
        {
            $s = new Stack();
            $s->push(5);
            $s->pop();
            expect($s->size())->toBe(0);
        });

        it('must return the last pushed item', function ()
        {
            $s = new Stack();
            $s->push(5);
            $s->push(4);
            expect($s->pop())->toBe(4);
        });

        it('must remove the item', function ()
        {
            $s = new Stack();
            $s->push(5);
            $s->push(4);
            expect($s->pop())->toBe(4);
            expect($s->peek())->toBe(5);
        });

        it('should not decrement the size if stack is empty', function ()
        {
            $s = new Stack();
            $s->pop();
            expect($s->size())->toBe(0);
        });

        it('should return null if the stack already empty', function ()
        {
            $s = new Stack();
            $s->pop();
            expect($s->pop())->toBeNull();
        });
    });
}


function isEmpty_tests()
{
    describe('is empty', function ()
    {
        it('should not be empty when stack has item(s)', function ()
        {
            $s = new Stack();
            $s->push(15);
            expect($s->isEmpty())->toBe(false);
        });

        it('should be empty when removing last item', function ()
        {
            $s = new Stack();
            $s->push(15);
            $s->pop();
            expect($s->isEmpty())->toBe(true);
        });
    });
}


function isFull_tests()
{
    describe('is full', function ()
    {
        it('should be true when items size reach the max size', function ()
        {
            $s = new Stack(2);
            $s->push(15);
            expect($s->isFull())->toBe(false);
            $s->push(20);
            expect($s->isFull())->toBe(true);
        });

        it('should be false when removing an item from full stack', function ()
        {
            $s = new Stack(2);
            $s->push(15);
            $s->push(20);
            expect($s->isFull())->toBe(true);
            $s->pop();
            expect($s->isFull())->toBe(false);
        });
    });
}
