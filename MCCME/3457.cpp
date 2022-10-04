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

    cout << "The next number for the number " << n << " is " << n + 1 << ".\n";
    cout << "The previous number for the number " << n << " is " << n - 1 << ".\n";
}