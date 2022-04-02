#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int opCount;
    string text;
    cin >> opCount >> text;

    deque<char> remainingText(text.begin(), text.end());

    for (int i = 0; i < opCount; i++) {
        int cutSize = remainingText.size() / 4;
        if (!cutSize)
            break;

        if (i % 2)
            remainingText.erase(remainingText.end() - cutSize, remainingText.end());
        else
            remainingText.erase(remainingText.begin(), remainingText.begin() + cutSize);
    }

    for (char c : remainingText)
        cout << c;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}