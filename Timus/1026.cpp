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

    sort(a.begin(), a.end());

    string s;
    int queryCount;
    cin >> s >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;

        cout << a[index - 1] << "\n";
    }
}