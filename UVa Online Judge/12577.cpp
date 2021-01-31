#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    cin >> s;

    if (s == "*")
        return 0;

    cout << "Case " << test << ": Hajj-e-" << (s == "Hajj" ? "Akbar\n" : "Asghar\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}