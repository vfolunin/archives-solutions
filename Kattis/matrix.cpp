#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int a, b, c, d; 
    if (!(cin >> a >> b >> c >> d))
        return 0;
    
    int den = a * d - b * c;

    cout << "Case " << test << ":\n";
    cout << d / den << " " << -b / den << "\n";
    cout << -c / den << " " << a / den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}