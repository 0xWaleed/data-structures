<?php


use DataStructure\SinglyLinkListNode;

describe('SinglyLinkListNode', function ()
{
    describe('next', Closure::fromCallable('next_tests'));
    describe('value', Closure::fromCallable('value_tests'));
    describe('traverse', Closure::fromCallable('traverse_tests'));
});


function next_tests()
{
    beforeEach(function ()
    {
        $this->instance = new DataStructure\SinglyLinkListNode();
    });

    it('has next', function ()
    {
        /** @var SinglyLinkListNode $instance */
        $instance = $this->instance;
        expect(property_exists($instance, 'next'))->toBeTruthy();
    });
}

function value_tests()
{
    beforeEach(function ()
    {
        $this->instance = new SinglyLinkListNode();
    });

    it('has value', function ()
    {
        /** @var SinglyLinkListNode $instance */
        $instance = $this->instance;
        expect(property_exists($instance, 'value'))->toBeTruthy();
    });
}

function traverse_tests()
{
    beforeEach(function ()
    {
        $this->instance = new SinglyLinkListNode();
    });

    it('has traverse method', function ()
    {
        /** @var SinglyLinkListNode $instance */
        $instance = $this->instance;

        expect(method_exists($instance, 'traverse'))->toBeTruthy();
    });

    it('returns all items', function ()
    {
        /** @var SinglyLinkListNode $instance */
        $instance = $this->instance;
        $instance->value = 1;
        $instance->next = new SinglyLinkListNode(2, new SinglyLinkListNode(3));

        expect($instance->traverse())->toBe([1, 2, 3]);
    });

    it('returns empty array when the list is empty', function ()
    {
        /** @var SinglyLinkListNode $instance */
        $instance = $this->instance;
        expect($instance->traverse())->toBe([]);
    });
}