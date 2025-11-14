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

    char letters[21], type;
    int value;
    while (scanf("%[^+-]%c%d", letters, &type, &value) == 3)
        cout << letters << (type == '+' ? " tighten " : " loosen ") << value << "\n";
}