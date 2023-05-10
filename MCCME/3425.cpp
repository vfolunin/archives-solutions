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

    set<pair<int, int>> pairs;

    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;
        pairs.insert({ a, b });
    }

    cout << pairs.size();
}