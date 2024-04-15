#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string next(string &s) {
    if (s[0] != '9')
        for (char a = s[0] + 1; 1; a++)
            for (char b = '0'; b <= '9'; b++)
                if (s.find(a) == -1 && s.find(b) == -1)
                    return string(1, a) + string(s.size() - 1, b);

    for (char a = '1'; 1; a++)
        for (char b = '0'; b <= '9'; b++)
            if (s.find(a) == -1 && s.find(b) == -1)
                return string(1, a) + string(s.size(), b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string res = "0";
    for (int i = 1; i < n; i++)
        res = next(res);

    cout << res;
}