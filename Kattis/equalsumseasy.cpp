#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<int> &v, int index, vector<int> &a, int sumA, vector<int> &b, int sumB) {
    if (index == v.size()) {
        if (a.empty() || b.empty() || sumA != sumB)
            return 0;
        for (int value : a)
            cout << value << " ";
        cout << "\n";
        for (int value : b)
            cout << value << " ";
        cout << "\n";
        return 1;
    }

    if (rec(v, index + 1, a, sumA, b, sumB))
        return 1;

    a.push_back(v[index]);
    if (rec(v, index + 1, a, sumA + v[index], b, sumB))
        return 1;
    a.pop_back();

    b.push_back(v[index]);
    if (rec(v, index + 1, a, sumA, b, sumB + v[index]))
        return 1;
    b.pop_back();

    return 0;
}

void solve(int test) {
    int size;
    cin >> size;

    vector<int> v(size), a, b;
    for (int &value : v)
        cin >> value;

    cout << "Case #" << test << ":\n";
    rec(v, 0, a, 0, b, 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}