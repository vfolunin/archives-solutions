#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, size;
    cin >> h >> w >> size;

    unordered_set<int> diags;
    for (int i = 0; i < size; i++) {
        int y, x;
        cin >> y >> x;

        diags.insert(y - x);
    }

    cout << diags.size();
}