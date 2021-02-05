#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int groupCount;
    cin >> groupCount;

    if (!groupCount)
        return 0;

    string text;
    cin >> text;

    int groupSize = text.size() / groupCount;
    for (int i = 0; i < text.size(); i += groupSize)
        reverse(text.begin() + i, text.begin() + i + groupSize);

    cout << text << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}