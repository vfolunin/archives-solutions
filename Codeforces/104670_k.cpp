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

    int knotCount;
    cin >> knotCount;

    int sum = 0;

    for (int i = 0; i < knotCount; i++) {
        int knot;
        cin >> knot;
        sum += knot;
    }

    for (int i = 0; i < knotCount - 1; i++) {
        int knot;
        cin >> knot;
        sum -= knot;
    }

    cout << sum;
}