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

    cout << n * 45 << " ml gin\n";
    cout << n * 30 << " ml fresh lemon juice\n";
    cout << n * 10 << " ml simple syrup\n";
    cout << n << (n == 1 ? " slice" : " slices") << " of lemon";    
}