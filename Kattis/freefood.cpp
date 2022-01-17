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

    int segmentCount;
    cin >> segmentCount;

    vector<int> marked(400);
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        fill(marked.begin() + l, marked.begin() + r + 1, 1);
    }

    cout << count(marked.begin(), marked.end(), 1);
}