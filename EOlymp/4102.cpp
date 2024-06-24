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

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string name, surname;
        cin >> name >> surname;

        for (char c : surname)
            cout << (char)tolower(c);
        cout << ".";
        for (char c : name)
            cout << (char)tolower(c);
        cout << "@retratek.com\n";
    }
}