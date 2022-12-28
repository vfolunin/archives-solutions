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
    
    long long factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;

    cout << factorial;
}