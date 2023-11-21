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

    long long num, den;
    cin >> num >> den;

    if (den)
        cout << num / den;
    else
        cout << "ERROR";
}