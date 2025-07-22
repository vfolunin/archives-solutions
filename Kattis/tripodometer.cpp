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
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    sort(a.rbegin(), a.rend());
    a.erase(unique(a.begin(), a.end()), a.end());

    cout << a.size() << "\n";
    for (int value : a)
        cout << sum - value << " ";
}