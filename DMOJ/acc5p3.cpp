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

    int size, limit;
    cin >> size >> limit;

    long long res = 0;
    vector<int> delta(size);
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        res += a;
        delta.push_back(b - a);
    }

    sort(delta.begin(), delta.end());

    for (int i = 0; i < limit; i++)
        res += delta[i];

    cout << res << "\n";
}