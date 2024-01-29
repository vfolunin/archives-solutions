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

    string s;
    cin >> s;

    long long res = 1;
    for (char c : s)
        if (c % 2 == 0)
            res *= c - '0';
    
    cout << (res != 1 ? res : -1);
}