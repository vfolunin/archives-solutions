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

    int happyCount = 0, sadCount = 0;
    for (int i = 0; i + 2 < s.size(); i++) {
        happyCount += s.substr(i, 3) == ":-)";
        sadCount += s.substr(i, 3) == ":-(";
    }

    if (!happyCount && !sadCount)
        cout << "none";
    else if (happyCount > sadCount)
        cout << "happy";
    else if (happyCount == sadCount)
        cout << "unsure";
    else
        cout << "sad";
}