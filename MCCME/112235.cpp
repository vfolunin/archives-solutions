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
 
    int a, b;
    cin >> a >> b;

    if (a == b)
        cout << 0;
    else if (a > b)
        cout << 1;
    else
        cout << 2;
}