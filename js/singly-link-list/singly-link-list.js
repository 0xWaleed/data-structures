class SinglyLinkList
{
    constructor()
    {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    add(value)
    {
        this.size++;
        if (!this.head) {
            this.head = new SinglyNode(value)
            this.tail = this.head;
            return;
        }
        const node = new SinglyNode(value);
        this.tail.next = node;
        this.tail = node;
    }

    remove(value)
    {
        let node = this.head;
        let left;
        while (node) {

            if (value === node.value) {
                if (!left) {
                    this.head = node.next;
                }
                else {
                    left.next = node.next;
                }
                this.size--;
                break;
            }

            left = node;
            node = node.next;
        }
    }
}
