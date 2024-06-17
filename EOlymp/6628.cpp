#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string a, b;
    cin >> a >> b;

    if (a == "END")
        return 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << "Case " << test << ": " << (a == b ? "same\n" : "different\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}