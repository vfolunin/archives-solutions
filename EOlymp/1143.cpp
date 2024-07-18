#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long num, den;
    cin >> num >> den;

    if (den && num % den == 0 && INT_MIN <= num / den && num / den <= INT_MAX)
        cout << num / den;
    else
        cout << "ERROR";
}