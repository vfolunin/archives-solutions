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

    int p = 30;
    while ((1 << (p - 1)) >= n)
        p--;

    cout << p;
}