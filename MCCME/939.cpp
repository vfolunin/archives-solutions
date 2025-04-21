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

    if (n == 0)
        cout << 1;
    else if (n == 1)
        cout << 0;
    else if (n % 2)
        cout << 4 << string(n / 2, '8');
    else
        cout << string(n / 2, '8');
}