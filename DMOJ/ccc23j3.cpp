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

    vector<int> count(5);
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
            if (s[j] == 'Y')
                maxCount = max(maxCount, ++count[j]);
    }

    bool first = 1;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] == maxCount) {
            if (first)
                first = 0;
            else
                cout << ",";
            cout << i + 1;
        }
    }
}