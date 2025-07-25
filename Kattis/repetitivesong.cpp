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

    unordered_map<string, int> last;
    int minGap = 1e9;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        if (last.count(s))
            minGap = min(minGap, i - last[s]);
        last[s] = i;
    }

    cout << (minGap != 1e9 ? size - minGap : 0);
}