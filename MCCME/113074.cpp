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

    int time, size;
    cin >> time >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < a.size() && time >= a[i]; i++) {
        time -= a[i];
        res++;
    }

    cout << res;
}