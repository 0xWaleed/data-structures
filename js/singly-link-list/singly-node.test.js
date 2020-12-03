describe('SinglyNode', () =>
{
    describe('initialization', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new SinglyNode();
        });

        it('expects next to be null', async () =>
        {
            expect(s.next).to.be.null;
        });

        it('expects value to be undefined', async () =>
        {
            expect(s.value).to.be.undefined;
        });
    });

    describe('traverse', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new SinglyNode(2);
            const _4 = new SinglyNode(4);
            _4.next = new SinglyNode(6)
            s.next = _4
        });

        it('expects to return values as array', async () =>
        {
            expect(s.traverse()).to.deep.equals([2, 4, 6]);
        });
    });
});
