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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    while (a.size() > 1) {
        vector<int> nextA;
        for (int i = 0; i + 1 < a.size(); i++)
            nextA.push_back(a[i] == a[i + 1] ? 1 : -1);
        a.swap(nextA);
    }

    cout << (a[0] == -1 ? "branca\n" : "preta\n");
}