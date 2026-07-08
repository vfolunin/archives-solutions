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

    int rCount, bCount;
    cin >> rCount >> bCount;

    cout << ((bCount + 1) * 2 >= rCount + bCount + 1 ? "BLUE" : "RED");
}