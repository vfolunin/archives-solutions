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

    int junctionCount, switchCount;
    cin >> junctionCount >> switchCount;

    cout << (switchCount % 2 ? "impossible" : "possible");
}