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

    int wordCount;
    cin >> wordCount;

    map<string, int> count;
    int maxCount = 0;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        maxCount = max(maxCount, ++count[word]);
    }

    for (auto it = count.rbegin(); it != count.rend(); it++) {
        if (it->second == maxCount) {
            cout << it->first << " " << it->second;
            break;
        }
    }
}