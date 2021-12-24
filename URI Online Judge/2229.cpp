#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long n;
    cin >> n;
    
    if (n < 0)
        return 0;

    long long root = (1LL << n) + 1;

    cout << "Teste " << test << "\n";
    cout << root * root << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (int test = 1; solve(test); test++);
}