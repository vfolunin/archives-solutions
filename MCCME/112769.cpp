#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> zFunction(const string &s) {
    vector<int> z(s.size());

    int blockL = 0, blockR = 0;
    for (int i = 1; i < s.size(); i++) {
        int blockLen = 0;

        if (i <= blockR)
            blockLen = min(z[i - blockL], blockR - i + 1);

        while (i + blockLen <= s.size() && s[i + blockLen] == s[blockLen])
            blockLen++;

        z[i] = blockLen;

        if (blockR < i + blockLen - 1) {
            blockL = i;
            blockR = i + blockLen - 1;
        }
    }

    return z;
}

bool check1(int maxLen, const string &s) {
    vector<int> z = zFunction(s);

    for (int len = 1; len <= maxLen; len++) {
        if (s.size() % len)
            continue;

        int i = len;
        while (i < s.size() && z[i] >= len)
            i += len;

        if (i == s.size()) {
            cout << 1 << "\n" << s.substr(0, len);
            return 1;
        }
    }

    return 0;
}

bool check2(int maxLen, const string &s) {
    vector<int> z1 = zFunction(s);

    for (int len1 = 1; len1 <= maxLen; len1++) {
        int from2 = len1;
        while (z1[from2] >= len1) {
            from2 += len1;
        }

        vector<int> z2 = zFunction(s.substr(from2));
        vector<int> visited(s.size());
        for (int len2 = 1; len2 <= maxLen; len2++) {

            int i = from2 + len2;
            while (i < s.size() && !visited[i]) {
                visited[i] = 1;
                if (z1[i] >= len1)
                    i += len1;
                else if (z2[i - from2] >= len2)
                    i += len2;
                else
                    break;
            }

            if (i == s.size()) {
                cout << 2 << "\n";
                cout << s.substr(0, len1) << "\n";
                cout << s.substr(from2, len2) << "\n";
                return 1;
            }

        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maxLen;
    string s;
    cin >> maxLen >> s;

    if (!check1(maxLen, s) && !check2(maxLen, s))
        cout << "3\na\nb\nc";
}