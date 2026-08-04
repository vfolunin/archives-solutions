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

    string surname, name;
    cin >> surname >> name;

    surname.pop_back();
    surname[0] = toupper(surname[0]);
    name[0] = toupper(name[0]);

    cout << name[0] << ". " << surname;
}