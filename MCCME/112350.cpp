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

    string name, ext;
    cin >> name >> ext;

    if (int dotPos = name.rfind('.'); dotPos != -1)
        name.erase(name.begin() + dotPos, name.end());

    cout << name << "." << ext;
}