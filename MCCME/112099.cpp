#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int resI = 0, resJ = 0, i = 0;
    for (int j = 1; j < a.size(); j++) {
        if (a[resI] * a[j] > a[i] * a[resJ]) {
            resI = i;
            resJ = j;
        }
        if (a[i] > a[j])
            i = j;
    }
    
    if (a[resI] < a[resJ])
        cout << resI + 1 << " " << resJ + 1;
    else
        cout << "0 0";
}