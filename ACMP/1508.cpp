#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long den;
    cin >> den;

    for (int i : { 2, 5 })
        while (den % i == 0)
            den /= i;

    cout << (den == 1 ? "Yes" : "No");
}