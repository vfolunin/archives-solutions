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

    long long a, b;
    cin >> a >> b;

    long long girls = (a + 1) / (a - b);
    long long boys = girls * b + 1;

    cout << boys << "\n" << girls;
}