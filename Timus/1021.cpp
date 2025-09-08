#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> read() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a = read();
    vector<int> b = read();

    for (int value : a) {
        if (binary_search(b.begin(), b.end(), 10000 - value)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}