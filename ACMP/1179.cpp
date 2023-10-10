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

    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    multiset<int> window(a.begin(), a.begin() + windowSize);
    cout << *window.begin() << " ";

    for (int i = windowSize; i < a.size(); i++) {
        window.erase(window.find(a[i - windowSize]));
        window.insert(a[i]);
        cout << *window.begin() << " ";
    }
}