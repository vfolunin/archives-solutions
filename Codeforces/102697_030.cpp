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

    int wins, losses, ties;
    char dash;
    cin >> wins >> dash >> losses >> dash >> ties;

    cout << wins * 3 + ties;
}