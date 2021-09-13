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
    for (int &val : a)
        cin >> val;

    int windowSize;
    cin >> windowSize;

    multiset<int> window;
    for (int i = 0; i < windowSize; i++)
        window.insert(a[i]);
    cout << *--window.end();

    for (int i = windowSize; i < size; i++) {
        window.erase(window.find(a[i - windowSize]));
        window.insert(a[i]);
        cout << " " << *--window.end();
    }
}