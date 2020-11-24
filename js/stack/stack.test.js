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
    })
})
