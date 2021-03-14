#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int dayCount, windowSize;
    string peopleIds;
    cin >> dayCount >> windowSize >> peopleIds;
    windowSize++;

    multiset<char> window;
    int res = 0;
    for (int i = 0; i < dayCount; i++) {
        if (i >= windowSize)
            window.erase(window.find(peopleIds[i - windowSize]));
        res += window.find(peopleIds[i]) != window.end();
        window.insert(peopleIds[i]);
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}