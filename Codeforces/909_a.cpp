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

    string name, surname;
    cin >> name >> surname;

    string login = name + surname;
    for (int nameSize = 0; nameSize < name.size(); nameSize++)
        for (int surnameSize = 0; surnameSize < surname.size(); surnameSize++)
            login = min(login, name.substr(0, nameSize + 1) + surname.substr(0, surnameSize + 1));

    cout << login;
}