class MyCircularQueue {
    int *arr;
    int f,r,size;
public:
    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        f=-1;
        r=-1;
    }
    
    bool enQueue(int val) {
        if(isFull())
        return false;
        if(f==-1)
        f=r=0;
        else if(r==size-1&&f!=0)
        r=0;
        else
        r++;
        arr[r]=val;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        return false;
        arr[f]=-1;
        if(f==r)
        f=r=-1;
        else if(f==size-1)
        f=0;
        else
        f++;
        return true;
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        else
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty())
        return -1;
        else
        return arr[r];
    }
    
    bool isEmpty() {
        if(f==-1)
        return true;
        else
        return false;
    }
    
    bool isFull() {
        if((f==0&&r==size-1)||(r==(f-1)%(size)))
        return true;
        else
        return false;
    }
};