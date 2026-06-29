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

    int windowCount, opCount, windowSize;
    cin >> windowCount >> opCount >> windowSize;

    vector<string> windows(windowCount);
    int windowIndex = 0;
    string buffer;

    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        if (op == "Backspace") {
            if (!windows[windowIndex].empty())
                windows[windowIndex].pop_back();
        } else if (op == "Copy") {
            buffer = windows[windowIndex].substr(max<int>(0, windows[windowIndex].size() - windowSize));
        } else if (op == "Paste") {
            windows[windowIndex] += buffer;
        } else if (op == "Next") {
            windowIndex = (windowIndex + 1) % windows.size();
        } else {
            windows[windowIndex] += op;
        }
    }
    
    string res = windows[windowIndex].substr(max<int>(0, windows[windowIndex].size() - windowSize));

    cout << (res.empty() ? "Empty" : res);
}