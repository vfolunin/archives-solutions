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

    string n;
    cin >> n;

    if (next_permutation(n.begin(), n.end()))
        cout << n;
    else
        cout << 0;
}