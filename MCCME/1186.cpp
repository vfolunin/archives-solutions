#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int change(string &s, int l, int r, int &opIndex) {
    int shift = 0;

    while (1) {
        int bestI = -1;
        for (int i = l; i <= r; i++)
            if (s[i] == '+' || s[i] == '*')
                if (bestI == -1 || s[bestI] == '+' && s[i] == '*')
                    bestI = i;

        if (bestI == -1)
            break;

        string op = to_string(opIndex++);
        s = s.substr(0, bestI) + op + s.substr(bestI + 1);
        shift += op.size() - 1;
        r += op.size() - 1;
    }

    return shift;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> stack;
    int opIndex = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stack.push_back(i);
        } else if (s[i] == ')') {
            i += change(s, stack.back(), i, opIndex);
            stack.pop_back();
        }
    }

    change(s, 0, s.size() - 1, opIndex);

    cout << s;
}