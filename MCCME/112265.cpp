#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int sum, int from, vector<int> &a) {
    if (!sum) {
        for (int value : a)
            cout << value * value * value << " ";
        exit(0);
    }

    if (a.size() == 7)
        return;

    for (int i = from; i * i * i <= sum; i++) {
        a.push_back(i);
        rec(sum - i * i * i, i, a);
        a.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a;
    rec(n, 1, a);

    cout << 0;
}