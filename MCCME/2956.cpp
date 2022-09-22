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

    int a = n / 1000;
    int b = n / 100 % 10;
    int c = n / 10 % 10;
    int d = n % 10;

    cout << (a == d && b == c);
}