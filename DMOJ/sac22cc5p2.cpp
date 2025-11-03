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
    string s;
    cin >> n >> s;

    if ((n % 2) ^ (s == "right"))
        cout << "left";
    else
        cout << "right";
}