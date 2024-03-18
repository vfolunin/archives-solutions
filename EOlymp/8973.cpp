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

    int size;
    cin >> size;

    vector<int> a(size);
    unordered_map<int, int> maxIndex;

    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        maxIndex[a[i]] = i;
    }

    for (int i = 0; i < a.size(); i++)
        if (maxIndex[a[i]] == i)
            cout << a[i] << " ";
}