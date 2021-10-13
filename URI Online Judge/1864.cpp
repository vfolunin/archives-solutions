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

    string s = "LIFE IS NOT A PROBLEM TO BE SOLVED";

    cout << s.substr(0, n) << "\n";
}