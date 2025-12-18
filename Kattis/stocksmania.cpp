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

    vector<int> res(a.size() + 1, 0);
    for (int size = 1; size <= a.size(); size++)
        for (int prevSize = 0; prevSize < size; prevSize++)
            res[size] = max(res[size], res[prevSize] + a[size - 1] - a[prevSize]);
    
    cout << *max_element(res.begin(), res.end());
}