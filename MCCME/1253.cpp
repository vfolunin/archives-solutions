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
 
    int size, money;
    cin >> size >> money;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    int res = money, resI = -2, resJ = -2;
    for (int i = 0, j = 1; j < size; j++) {
        int cur = money / a[i] * b[j] + money % a[i];
        if (res < cur) {
            res = cur;
            resI = i;
            resJ = j;
        }
        if (a[i] > a[j])
            i = j;
    }

    cout << res << "\n" << resI + 1 << " " << resJ + 1;
}