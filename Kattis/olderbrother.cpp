#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> factorize(int n) {
    vector<int> factorization;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factorization.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
        factorization.push_back(n);

    return factorization;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> factorization = factorize(n);

    if (!factorization.empty() && factorization.front() == factorization.back())
        cout << "yes";
    else
        cout << "no";
}