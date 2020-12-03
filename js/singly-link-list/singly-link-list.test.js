describe('SinglyLinkList', () =>
{

    describe('initialization', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new SinglyLinkList();
        });

        it('expects head to be null', async () =>
        {
            expect(s.head).to.be.null
        });

        it('expects tail to be null', async () =>
        {
            expect(s.tail).to.be.null
        });

        it('expects size to be 0', async () =>
        {
            expect(s.size).to.equals(0)
        });
    });

    describe('add', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new SinglyLinkList();
        });

        it('expects first item to be head', async () =>
        {
            s.add(5);
            expect(s.head.value).to.equals(5)
        });

        it('expects head not to be changed when it has a node', async () =>
        {
            s.add(5);
            s.add(4);
            expect(s.head.value).to.equals(5)
        });

        it('expects tail to point to last node', async () =>
        {
            s.add(5);
            expect(s.tail.value).to.equals(5)
            s.add(4);
            expect(s.tail.value).to.equals(4)
        });

        it('should add second item to head.next', async () =>
        {
            s.add(5);
            s.add(4);
            expect(s.head.next.value).to.equals(4)
        });

        it('should able to add and chain multiple nodes', async () =>
        {
            s.add(5);
            s.add(4);
            s.add(3);
            s.add(2);
            expect(s.head.value).to.equals(5)
            expect(s.head.next.value).to.equals(4)
            expect(s.head.next.next.value).to.equals(3)
            expect(s.head.next.next.next.value).to.equals(2)
        });

        it('expects size to be incremented', async () =>
        {
            s.add(5);
            expect(s.size).to.equals(1)
            s.add(4);
            expect(s.size).to.equals(2)
            s.add(3);
            expect(s.size).to.equals(3)
        });
    });

    describe('remove', () =>
    {
        let s;
        beforeEach(() =>
        {
            s = new SinglyLinkList();
            s.add(2);
            s.add(4);
            s.add(6);
        });

        it('should able to remove from the start', async () =>
        {
            s.remove(2)
            expect(s.head.traverse()).to.deep.equals([4, 6]);
        });

        it('should able to remove from the middle', async () =>
        {
            s.remove(4)
            expect(s.head.traverse()).to.deep.equals([2, 6]);
        });

        it('should able to remove from the end', async () =>
        {
            s.remove(6)
            expect(s.head.traverse()).to.deep.equals([2, 4]);
        });

        it('should decrement the size', async () =>
        {
            s.remove(2);
            expect(s.size).to.equals(2);
            s.remove(4);
            expect(s.size).to.equals(1);
            s.remove(6);
            expect(s.size).to.equals(0);
        });
    });
});
