#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);

    int t1, t2;
    string mode;
    cin >> t1 >> t2 >> mode;

    if (mode == "auto" || mode == "freeze" && t1 > t2 || mode == "heat" && t1 < t2)
        cout << t2;
    else
        cout << t1;
}