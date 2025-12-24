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

    string a, b;
    cin >> a >> b;

    if (a == "416" && b.size() == 7)
        cout << "valuable";
    else if ((a == "437" || a == "647") && b.size() == 7)
        cout << "valueless";
    else
        cout << "invalid";
}