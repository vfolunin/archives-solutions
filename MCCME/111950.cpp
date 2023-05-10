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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] >= a[i]) {
            cout << a[i];
            return 0;
        }
    }

    cout << "YES";
}