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
    
    int res = 0;
    for (char c; cin >> noskipws >> c; )
        res += (unsigned char)c;

    cout << res;
}