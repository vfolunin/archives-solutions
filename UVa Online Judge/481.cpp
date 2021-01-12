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

    vector<int> a;
    int x;
    while (cin >> x)
        a.push_back(x);

    vector<int> lisLast;
    vector<int> lisLastI;
    vector<int> lisPrevI(a.size());

    for (int i = 0; i < a.size(); i++) {
        int pos = lower_bound(lisLast.begin(), lisLast.end(), a[i]) - lisLast.begin();
        if (pos == lisLast.size()) {
            lisLast.emplace_back();
            lisLastI.emplace_back();
        }
        lisLast[pos] = a[i];
        lisLastI[pos] = i;
        lisPrevI[i] = pos ? lisLastI[pos - 1] : -1;
    }

    vector<int> lis;
    for (int i = lisLastI.back(); i != -1; i = lisPrevI[i])
        lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());

    cout << lis.size() << "\n-\n";
    for (int x : lis)
        cout << x << "\n";
}