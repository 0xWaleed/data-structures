const expect = chai.expect;
const describe = Mocha.describe;
const it = Mocha.it;
const xit = Mocha.xit;
const afterEach = Mocha.afterEach;
const beforeEach = Mocha.beforeEach;


describe('Stack', () =>
{
    describe('initialization', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new Stack();
        });

        it('should be empty', async () =>
        {
            expect(s.isEmpty()).to.be.true;
        });

        it('should not be full', async () =>
        {
            expect(s.isFull()).to.be.false;
        });

        it('should have size of 0', async () =>
        {
            expect(s.size()).to.equals(0);
        });

        it('should have default max size of 64', async () =>
        {
            expect(s.maxSize()).to.equals(64);
        });

        it('should able to change the max size', async () =>
        {
            const stack = new Stack(24);
            expect(stack.maxSize()).to.equals(24);
        });
    });

    describe('push', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new Stack();
        });

        it('should increment the size everytime we push', async () =>
        {
            s.push();
            expect(s.size()).to.equals(1);
            s.push();
            expect(s.size()).to.equals(2);
            s.push();
            expect(s.size()).to.equals(3);
        });

        it('should not add item to a full stack', async () =>
        {
            const stack = new Stack(2);
            stack.push(2)
            stack.push(3)
            stack.push(4)
            expect(stack.size()).to.equals(2);
        });
    });

    describe('pop', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new Stack();
        });

        it('should decrement the size everytime we pop', async () =>
        {
            s.push(2)
            s.push(3)
            expect(s.size()).to.equals(2);
            s.pop();
            expect(s.size()).to.equals(1);
            s.pop();
            expect(s.size()).to.equals(0);
        });

        it('should not decrement the empty stack', async () =>
        {
            expect(s.size()).to.equals(0);
            s.pop();
            expect(s.size()).to.equals(0);
        });

        it('should return last push item', async () =>
        {
            s.push(2)
            s.push(3)
            expect(s.pop()).to.equals(3);
            expect(s.pop()).to.equals(2);
        });

        it('should return undefined when stack is empty', async () =>
        {
            expect(s.pop()).to.be.undefined;
        });
    });

    describe('peek', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new Stack();
        });

        it('should return last pushed item without removing it', async () =>
        {
            s.push(2);
            s.push(3);
            expect(s.size()).to.equals(2);
            expect(s.peek()).to.equals(3);
            expect(s.size()).to.equals(2);
        });

    });

    describe('is full', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new Stack();
        });

        it('should not be full when stack is empty', async () =>
        {
            expect(s.isFull()).to.be.false;
        });

        it('should be full when size == max size', async () =>
        {
            const stack = new Stack(2);
            stack.push(1);
            stack.push(2);
            expect(stack.isFull()).to.be.true;
        });

        it('should not be full when size < max size', async () =>
        {
            const stack = new Stack(3);
            stack.push(1);
            stack.push(2);
            expect(stack.isFull()).to.be.false;
        });

        it('should not be full when we remove from full stack', async () =>
        {
            const stack = new Stack(3);
            stack.push(1);
            stack.push(2);
            stack.push(3);
            stack.pop();
            expect(stack.isFull()).to.be.false;
        });
    });

    describe('is empty', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new Stack();
        });

        it('should be empty when stack is empty', async () =>
        {
            expect(s.isEmpty()).to.be.true;
        });

        it('should not be empty when stack has item(s)', async () =>
        {
            s.push(2);
            expect(s.isEmpty()).to.be.false;
        });

        it('should become empty when removing all items', async () =>
        {
            s.push(2);
            s.push(3);
            s.push(4);
            expect(s.isEmpty()).to.be.false;
            s.pop();
            s.pop();
            s.pop();
            expect(s.isEmpty()).to.be.true;
        });
    });
})
