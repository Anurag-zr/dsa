#include<bits/stdc++.h>
using namespace std;



class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        
        while(!s.empty() && price>=s.top().first){
            cnt+= s.top().second;
            s.pop();
        }
        
        s.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


int main(){

    StockSpanner* stockSpannerObj = new StockSpanner();
    cout << stockSpannerObj->next(23) << endl;
    cout << stockSpannerObj->next(232) << endl;
    cout << stockSpannerObj->next(233) << endl;
    cout << stockSpannerObj->next(2) << endl;
    cout << stockSpannerObj->next(4) << endl;
    cout << stockSpannerObj->next(253) << endl;
    cout << stockSpannerObj->next(243) << endl;
}