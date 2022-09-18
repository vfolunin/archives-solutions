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

    cout << n << " ";
    if (n % 100 / 10 == 1 || n % 10 == 0 || n % 10 >= 5)
        cout << "korov";
    else if (n % 10 == 1)
        cout << "korova";
    else
        cout << "korovy";
}