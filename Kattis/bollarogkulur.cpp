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

    vector<int> cups = { 1, 0, 0 };

    for (int i = 0; i < 5; i++) {
        int a, b;
        cin >> a >> b;

        swap(cups[a - 1], cups[b - 1]);
    }

    cout << find(cups.begin(), cups.end(), 1) - cups.begin() + 1;
}