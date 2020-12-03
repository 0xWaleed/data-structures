class SinglyNode
{
    constructor(value)
    {
        this.next = null;
        this.value = value;
    }

    traverse()
    {
        let node = this;
        const values = [];
        while (node) {
            values.push(node.value);
            node = node.next;
        }
        return values;
    }
}
