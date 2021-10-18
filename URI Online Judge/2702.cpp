#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> available(3);
    for (int &x : available)
        cin >> x;

    vector<int> requested(3);
    for (int &x : requested)
        cin >> x;

    int res = 0;
    for (int i = 0; i < 3; i++)
        res += max(0, requested[i] - available[i]);

    cout << res << "\n";
}