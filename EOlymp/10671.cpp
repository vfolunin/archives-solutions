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

    if ((a + b) % 2)
        cout << "X";
    else
        cout << (a + b) / 2 << " " << (a - b) / 2;
}