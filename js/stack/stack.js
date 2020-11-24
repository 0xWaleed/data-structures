class Stack
{

    constructor(maxSize = 64)
    {
        this._maxSize = maxSize;
        this._size = 0;
        this._items = [];
        this._isFull = false;
        this._isEmpty = true;
    }

    size()
    {
        return this._size;
    }

    isFull()
    {
        return this._isFull;
    }

    isEmpty()
    {
        return this._isEmpty;
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
        this._isFull = this.size() >= this.maxSize();
        this._isEmpty = false;
    }

    pop()
    {
        if (this.size() === 0) {
            return;
        }
        let item = this._items[this._size-- - 1];
        this._isFull = this.size() >= this.maxSize();
        this._isEmpty = this.size() >= 0;
        return item;
    }

    peek()
    {
        return this._items[this._size - 1]
    }
}
