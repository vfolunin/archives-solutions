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

    char c;
    cin >> c;

    if (c == 'O')
        cout << "Na kogo greh?";
    else if (c == 'P')
        cout << "Mi s tobou za odno!";
    else if (c == 'D')
        cout << "Tri raza v zub!";
    else
        cout << "Viberay!";
}