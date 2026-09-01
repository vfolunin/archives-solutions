#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

int getPeriod(string &s) {
    int period = s.size() - prefixFunction(s).back();
    return s.size() % period ? s.size() : period;
}

vector<int> readPeriods(int size) {
    vector<int> periods;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        periods.push_back(getPeriod(s));
    }

    sort(periods.begin(), periods.end());
    return periods;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a = readPeriods(size);
    vector<int> b = readPeriods(size);

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        int diff = a[i] - b[i];
        res += diff * diff;
    }

    cout << res;
}