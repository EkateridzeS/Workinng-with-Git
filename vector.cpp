#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
    int n, X, Y;
    cout << "X="; cin >> X;
    cout << "Y="; cin >> Y;
    cout << "n = "; cin >> n;
    vector<int>vec;
    int x;
    for (int i = 0;i < n;i++) {
        cout << "a[" << i << "]=";
        cin >> x;
        vec.push_back(x);
    }

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
        cout << endl;

    replace(vec.begin(), vec.end(), X, Y);
    
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    system("pause");
    return 0;
}