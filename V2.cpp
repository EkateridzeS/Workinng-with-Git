#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int X;
bool kratn(int x) {
    return x % 2 != 0;
}

int main() {
    int n;
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

    vector<int>::iterator it = remove_if(vec.begin(), vec.end(), kratn);
    vec.erase(it, vec.end());


    vector<int> temp(vec);
    int MIN = *min_element(vec.begin(), vec.end());
    replace_if(vec.begin(),vec.end(),kratn,MIN);

    cout << "Новый вектор: ";

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    cout << *iter << " ";
    cout << endl;

    // Сортировка
    sort(vec.begin(), vec.end());
    cout << "Отсортированный вектор: ";

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    system("pause");
    return 0;
}