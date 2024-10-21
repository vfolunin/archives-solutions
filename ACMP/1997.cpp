#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string replace(const string &s, const string &a, const string &b) {
    int pos = s.find(a);
    if (pos == -1)
        return s;
    return s.substr(0, pos) + b + s.substr(pos + a.size());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s = "5" + string(n, '4');
    while (s.find("5454") != -1 || s.find("554") != -1 || s.find("444") != -1) {
        if (s.find("5454") != -1)
            s = replace(s, "5454", "2");
        else
            s = replace(s, "554", "45");
        s = replace(s, "444", "54");
    }

    cout << s;
}