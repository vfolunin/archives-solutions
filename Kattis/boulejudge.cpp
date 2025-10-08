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

    int x, y;
    cin >> x >> y;

    vector<int> a(6);
    for (int &value : a) {
        int x1, y1;
        cin >> x1 >> y1;

        value = (x - x1) * (x - x1) + (y - y1) * (y - y1);
    }
    sort(a.begin(), a.end());

    vector<int> b(6);
    for (int &value : b) {
        int x1, y1;
        cin >> x1 >> y1;

        value = (x - x1) * (x - x1) + (y - y1) * (y - y1);
    }
    sort(b.begin(), b.end());

    if (a[0] == b[0])
        cout << "TIE";
    else if (a[0] < b[0])
        cout << "JONNA\n" << lower_bound(a.begin(), a.end(), b[0]) - a.begin();
    else
        cout << "OPPONENTS\n" << lower_bound(b.begin(), b.end(), a[0]) - b.begin();
}