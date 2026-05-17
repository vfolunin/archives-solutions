#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getOps(string &s) {
    long long count1 = 0, res = 0;
    for (char c : s) {
        if (c == '0')
            res += count1;
        else
            count1++;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    if (s.find("10") == -1) {
        cout << getOps(s);
        return 0;
    }

    string a = s;
    int ai = s.find("10");
    swap(a[ai], a[ai + 1]);

    string b = s;
    int bi = s.rfind("10");
    swap(b[bi], b[bi + 1]);

    cout << min(getOps(a), getOps(b));
}