<?php

use DataStructure\Queue;

describe('Queue', function ()
{
    beforeEach(function ()
    {
        $this->instance = new Queue(5);
    });

    describe('initialize', Closure::fromCallable('queue_initialize_tests'));
    describe('enqueue', Closure::fromCallable('queue_enqueue_tests'));
    describe('dequeue', Closure::fromCallable('queue_dequeue_tests'));
});


function queue_initialize_tests()
{
    it('expects size to be 0', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;

        expect($instance->size())->toBe(0);
    });

    it('expects capacity to be 5', function ()
    {
        expect((new Queue(5))->capacity)->toBe(5);
    });
}

function queue_enqueue_tests()
{
    it('return true for enqueued value', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;

        expect($instance->enqueue(5))->toBe(true);
        expect($instance->peek())->toBe(5);
    });

    it('expect size to be incremented', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;

        $instance->enqueue(5);

        expect($instance->size())->toBe(1);
    });

    it('able to add multiple items', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;

        $instance->enqueue(5);
        $instance->enqueue(10);
        $instance->enqueue(15);

        expect($instance->size())->toBe(3);
    });

    it('should not add when size >= capacity', function ()
    {
        $instance = new Queue(3);
        $instance->enqueue(5);
        $instance->enqueue(10);
        $instance->enqueue(15);
        expect($instance->enqueue(20))->toBe(false);
        expect($instance->size())->toBe(3);
    });
}

function queue_dequeue_tests()
{
    beforeEach(function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;

        $instance->enqueue(2);
        $instance->enqueue(4);
        $instance->enqueue(6);
    });

    it('should return first in order value', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;
        expect($instance->dequeue())->toBe(2);
    });

    it('should remove the value', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;
        $instance->dequeue();
        expect($instance->size())->toBe(2);
    });

    it('should return value in order as FIFO', function ()
    {
        /** @var Queue $instance */
        $instance = $this->instance;
        expect($instance->dequeue())->toBe(2);
        expect($instance->dequeue())->toBe(4);
        expect($instance->dequeue())->toBe(6);
    });
}