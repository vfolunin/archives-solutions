#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getT() {
    vector<long long> t(61);
    t[1] = t[2] = t[3] = 1;
    for (int i = 4; i < t.size(); i++)
        t[i] = t[i - 1] + t[i - 2] + t[i - 3];
    return t;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> t = getT();

    cout << "Case " << test << ": " << t[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}