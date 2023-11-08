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

    if ((n % 2 == 0) ^ (n % 3 == 0 && n < 0))
        cout << "YES";
    else
        cout << "NO";
}