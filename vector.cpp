#include <iostream>

#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int X;
bool kratn(int x) {
    return x % X == 0;
}

int main() {
    int n;
    cout << "X="; cin >> X;
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


    vector<int> temp(vec);
    int MAX = *max_element(vec.begin(), vec.end());
    replace_if(vec.begin(), vec.end(), kratn, MAX);

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    system("pause");
    return 0;
}