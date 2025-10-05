#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int front;
    int rear;
    int count;
    int size;

public:
   
    MyCircularQueue(int k) {
        size = k;
        q.resize(k);
        front = 0;
        rear = -1;
        count = 0;
    }

   
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }

   
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }

   
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

   
    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

   
    bool isEmpty() {
        return count == 0;
    }

   
    bool isFull() {
        return count == size;
    }
};


int main() {
    MyCircularQueue cq(3);  
    cout << cq.enQueue(10) << endl; 
    cout << cq.enQueue(20) << endl; 
    cout << cq.enQueue(30) << endl; 
    cout << cq.enQueue(40) << endl; 
    cout << cq.Rear() << endl;      
    cout << cq.isFull() << endl;    
    cout << cq.deQueue() << endl;   
    cout << cq.enQueue(40) << endl; 
    cout << cq.Rear() << endl;      
    return 0;
}