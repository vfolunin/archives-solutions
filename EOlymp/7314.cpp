#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

template<typename T>
auto get(T &a, int i) {
    return 0 <= i ? a[i] : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> lenTo(s.size());
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
        if (get(s, i) == '(')
            continue;

        if (get(s, i - 1) == '(')
            lenTo[i] = get(lenTo, i - 2) + 2;
        else if (get(s, i - get(lenTo, i - 1) - 1) == '(')
            lenTo[i] = get(lenTo, i - get(lenTo, i - 1) - 2) + get(lenTo, i - 1) + 2;

        maxLen = max(maxLen, lenTo[i]);
    }

    cout << maxLen;
}