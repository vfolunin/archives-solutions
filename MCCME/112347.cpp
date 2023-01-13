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

    string surname, name, parentName;
    cin >> surname >> name >> parentName;

    cout << name[0] << "." << parentName[0] << ". " << surname;
}