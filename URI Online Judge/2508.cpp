#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitRoot(int n) {
    if (n < 10)
        return n;

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return digitRoot(sum);
}

bool solve() {
    string name;
    if (!getline(cin, name))
        return 0;

    int sum = 0;
    for (char c : name)
        if (isalpha(c))
            sum += (tolower(c) - 'a') % 9 + 1;

    cout << digitRoot(sum) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}