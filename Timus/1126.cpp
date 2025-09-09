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

    int windowSize;
    cin >> windowSize;

    vector<int> a;
    for (int value; cin >> value && value != -1; )
        a.push_back(value);

    multiset<int> window(a.begin(), a.begin() + windowSize);
    cout << *prev(window.end()) << "\n";

    for (int i = windowSize; i < a.size(); i++) {
        window.erase(window.find(a[i - windowSize]));
        window.insert(a[i]);
        cout << *prev(window.end()) << "\n";
    }
}