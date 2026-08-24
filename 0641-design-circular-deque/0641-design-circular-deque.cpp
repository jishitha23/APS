#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> dq;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        dq.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
            dq[front] = value;
        } else {
            front = (front - 1 + capacity) % capacity;
            dq[front] = value;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
            dq[rear] = value;
        } else {
            rear = (rear + 1) % capacity;
            dq[rear] = value;
        }

        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (size == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (size == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return dq[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return dq[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};