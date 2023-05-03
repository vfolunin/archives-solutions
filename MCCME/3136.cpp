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

    cout << "Input: \"" << n << "\"\n";
    cout << "Output: \"" << n << "\" + \"1\" = \"" << n + 1 << "\"\n";
    cout << "Output: \"" << n << "\" - \"1\" = \"" << n - 1 << "\"";
}