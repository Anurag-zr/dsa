#include<bits/stdc++.h>
using namespace std;


class MyCalendar {
private: 
    vector<pair<int,int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto p : bookings){
            if(max(p.first,start)<min(p.second,end)) return false;
        }
        
        bookings.push_back({start,end});
        return true;
    }
};

int main(){

    MyCalendar obj;
    cout << obj.book(10, 20) << endl;
    cout<<obj.book(15, 25)<<endl;
    cout << obj.book(20, 30) << endl;
}