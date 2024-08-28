#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPair(int a, int b) {
    return !a || !b || a == b;
}

bool isHand(vector<int> &a) {
    return isPair(a[0], a[1]) && isPair(a[2], a[3]) && max(a[0], a[1]) != max(a[2], a[3]);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(5);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    do {
        if (isHand(a)) {
            cout << "Yes";
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "No";
}