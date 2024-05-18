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

    int m;
    cin >> m;

    cout << m / (24 * 60) + 1 << " " << m % (24 * 60) / 60 << " " << m % 60;
}