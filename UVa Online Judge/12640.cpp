#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    vector<int> v;
    while (cin.peek() != EOF && cin.peek() != '\n') {
        v.emplace_back();
        cin >> v.back();
    }
    cin.ignore();
    return v;
}

bool solve() {
    vector<int> v = readInts();
    if (v.empty())
        return 0;

    for (int i = 1; i < v.size(); i++)
        v[i] = max(v[i], v[i] + v[i - 1]);

    cout << max(0, *max_element(v.begin(), v.end())) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}