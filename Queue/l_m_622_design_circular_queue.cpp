#include<bits/stdc++.h>
using namespace std;



class MyCircularQueue {
private: 
    int maxi;
    int front; int rear;
    vector<int> cir_queue;
    
public:
    MyCircularQueue(int k) {
        this->maxi = k;
        cir_queue.resize(maxi);
        
        front =-1;
        rear =-1;
    }
    
    bool enQueue(int value) {
        
        if(front==0 && rear==maxi-1) return false;  //overflow
        if(front!=0 && rear==front-1) return false; //overflow
        
        if(front==-1 && rear==-1){//  queue is empy: insert first element
            front=0;
            rear =0;
        }
        else if(rear==maxi-1 && front!=0) {
            rear=0;
        }
        else{
            rear=rear+1;
        }
        
        cir_queue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(front==-1 && rear==-1){ return false;} // deletion not possible:underflow
        
        int val = cir_queue[front];
        if(front==rear) {
            front=-1;
            rear=-1;
        }
        else if(front==maxi-1) front=0;
        else front =front+1;
        
        return true;

    }
    
    int Front() {
        if(front==-1 && rear==-1) return -1;
        return cir_queue[front];
    }
    
    int Rear() {
        if(front==-1 && rear==-1) return -1;
        return cir_queue[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1) return true;
        
        return false;
    }
    
    bool isFull() {
        if(front==0 && rear==maxi-1) return true;  //overflow
        if(front!=0 && rear==front-1) return true; //overflow
        
        return false;
    }
};


int main(){
// ["MyCircularQueue","enQueue","Rear","Rear","deQueue",
// "enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
// [[6],[6],[],[],[],[5],[],[],[],[],[],[]]

MyCircularQueue *cir_queue = new MyCircularQueue(4);
cout << cir_queue->enQueue(6) << endl;
cout << cir_queue->enQueue(5) << endl;
cout << cir_queue->enQueue(4) << endl;
cout << cir_queue->deQueue() << endl;
cout << cir_queue->deQueue() << endl;
cout << cir_queue->enQueue(7) << endl;
cout << cir_queue->enQueue(8) << endl;
cout << cir_queue->enQueue(9) << endl;
cout << cir_queue->enQueue(10) << endl;

cout << cir_queue->Rear() << endl;
cout << cir_queue->Rear() << endl;
cout << cir_queue->deQueue()<< endl;
cout << cir_queue->enQueue(5)<< endl;
cout << cir_queue->Rear()<< endl;
cout << cir_queue->deQueue()<<endl;
cout << cir_queue->Front()<<endl;
cout << cir_queue->deQueue()<<endl;
cout << cir_queue->deQueue()<<endl;
cout << cir_queue->deQueue()<<endl;
}