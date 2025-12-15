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

    if (n < 10)
        cout << 10 - n;
    else if (n < 100)
        cout << 100 - n;
    else
        cout << 1000 - n;
}