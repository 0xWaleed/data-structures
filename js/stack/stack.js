class Stack
{

    constructor(maxSize = 64)
    {
        this._maxSize = maxSize;
    }

    size()
    {
        return 0;
    }

    isFull()
    {
        return false;
    }

    isEmpty()
    {
        return true;
    }

    maxSize()
    {
        return this._maxSize;
    }
}
