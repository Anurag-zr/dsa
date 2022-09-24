#include<bits/stdc++.h>
using namespace std;


/*----------------------------------------------------------------

       *
      *  *
    *   *   *
   *  *   *   * 


*/


int main(){
    int row;
    cin >> row;

    for (int i = 1; i <= row;i++){
        for (int j = row - i; j >= 1;j--){
            cout << " ";
        }

        for (int j = 1; j <=2 * i - 1;j++){
            if(j&1)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }
}