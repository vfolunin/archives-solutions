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

    string s;
    getline(cin, s);

    vector<int> count(26);
    int maxCount = 0;
    for (char c : s)
        if (isalpha(c))
            maxCount = max(maxCount, ++count[tolower(c) - 'a']);

    for (int i = 0; i < count.size(); i++)
        if (count[i] == maxCount)
            cout << (char)(i + 'A');

    cout << "\n" << maxCount;
}