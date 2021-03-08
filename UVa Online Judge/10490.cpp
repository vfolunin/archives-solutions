#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n) || !n)
        return 0;

    static vector<int> perfect = { 2, 3, 5, 7, 13, 17, 19, 31 };
    static vector<int> prime = { 11, 23, 29 };

    if (binary_search(perfect.begin(), perfect.end(), n))
        cout << "Perfect: " << (1LL << (n - 1)) * ((1LL << n) - 1) << "!\n";
    else if (binary_search(prime.begin(), prime.end(), n))
        cout << "Given number is prime. But, NO perfect number is available.\n";
    else
        cout << "Given number is NOT prime! NO perfect number is available.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}