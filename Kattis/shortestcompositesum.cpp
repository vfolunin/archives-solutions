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

    long long n;
    cin >> n;

    if (n % 2)
        cout << "2\n9 " << n - 9;
    else
        cout << "2\n4 " << n - 4;
}