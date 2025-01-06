#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string problem;
    cin >> problem;

    if (problem == "P=NP") {
        cout << "skipped\n";
    } else {
        stringstream ss(problem);
        int a, b;
        char plus;
        ss >> a >> plus >> b;
        cout << a + b << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}