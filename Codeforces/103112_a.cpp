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

    int size, targetValue;
    cin >> size >> targetValue;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << upper_bound(a.begin(), a.end(), targetValue) - a.begin();
}