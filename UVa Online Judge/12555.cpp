#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string line;
    getline(cin, line);

    int i = 0;
    while (!isdigit(line[i]))
        i++;

    int a = 0;
    for (; i < line.size() && isdigit(line[i]); i++)
        a = a * 10 + line[i];

    while (i < line.size() && !isdigit(line[i]))
        i++;

    int b = 0;
    for (; i < line.size() && isdigit(line[i]); i++)
        b = b * 10 + line[i];

    cout << "Case " << test << ": " << a * 0.5 + b * 0.05 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}