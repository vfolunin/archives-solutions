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
    
    cout << (s[1] % 2 && s[3] % 2 && s[7] % 2 ? "Yes" : "No");
}