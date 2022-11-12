#include<bits/stdc++.h>
using namespace std;


class MedianFinder {
public:
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // cout<<maxHeap.top()<<" "<<minHeap.top()<<endl;
    }
    
    double findMedian() {
        
        if(maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top())/2.0;
        
        return minHeap.top();
    }
    
private:
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
};



int main(){
 MedianFinder *obj = new MedianFinder();

 obj->addNum(90);
 cout << obj->findMedian() << endl;
 obj->addNum(2);
 cout << obj->findMedian() << endl;
 obj->addNum(23);
 cout << obj->findMedian() << endl;
 obj->addNum(34);
 cout << obj->findMedian() << endl;
 obj->addNum(934);
 cout << obj->findMedian() << endl;
 obj->addNum(1);
 cout << obj->findMedian() << endl;
 obj->addNum(23);
 cout << obj->findMedian() << endl;
 obj->addNum(26);
 cout << obj->findMedian() << endl;
 obj->addNum(6);
 cout << obj->findMedian() << endl;
}