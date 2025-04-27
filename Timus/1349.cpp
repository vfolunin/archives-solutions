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

    int n;
    cin >> n;

    if (n == 1)
        cout << "1 2 3";
    else if (n == 2)
        cout << "3 4 5";
    else
        cout << "-1";
}