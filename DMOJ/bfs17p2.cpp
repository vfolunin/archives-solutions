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

    unordered_map<string, int> count;
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        maxCount = max(maxCount, ++count[s]);
    }

    if (maxCount <= size - maxCount + 1)
        cout << size;
    else
        cout << (size - maxCount) * 2 + 1;
}