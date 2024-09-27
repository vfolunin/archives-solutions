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

    int size;
    long long jump;
    cin >> size >> jump;
    jump %= size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long res = 0;
    for (int i = 0; a[i]; i = (i + jump) % a.size()) {
        res += a[i];
        a[i] = 0;
    }

    cout << res;
}