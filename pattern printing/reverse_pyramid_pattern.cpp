#include <bits/stdc++.h>
using namespace std;


int main(){
	int row;
	cin>>row;

    for (int i = 1; i <= 2 * row - 1;i++)
        cout << "*";
    cout << endl;
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j <= row - i; j++)
            cout << "*";
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= row - i; j++)
            cout << "*";

        cout << endl;
        }
}