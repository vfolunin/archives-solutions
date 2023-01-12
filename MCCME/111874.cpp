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
 
    string name, parentName, surname;
    cin >> name >> parentName >> surname;

    cout << surname << " " << name[0] << "." << parentName[0] << ".";
}