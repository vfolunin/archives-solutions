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
    for (int &value : a) {
        cin >> value;
        value--;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[a[a[i]]] == i) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}