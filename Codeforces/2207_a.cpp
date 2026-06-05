#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string maxS;
    cin >> maxS >> maxS;

    for (int i = 1; i + 1 < maxS.size(); i++)
        if (maxS[i - 1] == '1' && maxS[i + 1] == '1')
            maxS[i] = '1';

    string minS = maxS;

    for (int i = 1; i + 1 < minS.size(); i++)
        if (minS[i - 1] == '1' && minS[i + 1] == '1')
            minS[i] = '0';

    cout << count(minS.begin(), minS.end(), '1') << " ";
    cout << count(maxS.begin(), maxS.end(), '1') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}