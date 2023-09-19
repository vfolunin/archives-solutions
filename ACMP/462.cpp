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

    cout << n - n / 2 - n / 3 - n / 5 + n / 6 + n / 10 + n / 15 - n / 30;
}