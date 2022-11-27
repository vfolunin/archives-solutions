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

    vector<int> a(10);
    for (int &value : a)
        cin >> value;

    int num = 0, den = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 2 || i + 1 == a.size() || a[i + 1] == 2) {
            num += a[i];
            den++;
        }
    }

    cout << num / den;
}