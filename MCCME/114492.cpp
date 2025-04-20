#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;
    
    cout << (unordered_set<char>(s.begin(), s.end()).size() == s.size() ? "YES" : "NO");
}