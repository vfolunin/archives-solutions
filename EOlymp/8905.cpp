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

    n--;
    while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        n--;
    
    cout << n;
}