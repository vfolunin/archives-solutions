#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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

    unordered_map<int, int> count;
    for (int i = 0; i < windowSize; i++)
        count[a[i]]++;
    cout << count.size() << " ";

    for (int i = windowSize; i < size; i++) {
        if (!--count[a[i - windowSize]])
            count.erase(a[i - windowSize]);
        count[a[i]]++;
        cout << count.size() << " ";
    }
}