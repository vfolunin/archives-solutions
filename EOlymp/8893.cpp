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

    if (n % 6 == 0 && 10 <= abs(n) && abs(n) <= 99)
        cout << "YES";
    else
        cout << "NO";
}