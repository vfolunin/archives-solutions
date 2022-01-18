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

    string name;
    cin >> name;

    cout << name[0];
    for (int i = 1; i < name.size(); i++)
        if (name[i - 1] != name[i])
            cout << name[i];
}