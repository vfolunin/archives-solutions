#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getLog() {
    vector<int> log(20000);
    for (int i = 1; i < log.size(); i++)
        log[i] = 1 + log[(i - 1) / 2];
    return log;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> log = getLog();

    cout << log[n - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}