class Stack
{

    constructor(maxSize = 64)
    {
        this._maxSize = maxSize;
        this._size = 0;
        this._items = [];
    }

    size()
    {
        return this._size;
    }

    isFull()
    {
        return this.size() >= this.maxSize();
    }

    isEmpty()
    {
        return this.size() === 0;
    }

    maxSize()
    {
        return this._maxSize;
    }

    push(item)
    {
        if (this.size() >= this.maxSize()) {
            return;
        }
        this._items[this._size++] = item;
    }

    pop()
    {
        if (this.size() === 0) {
            return;
        }
        let item = this._items[this._size - 1];
        delete this._items[this._size-- - 1];
        return item;
    }

    peek()
    {
        return this._items[this._size - 1]
    }
}
