#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    string letters;
    for (char c = 'A'; c <= 'Z'; c++)
        letters += c;

    cout << "Instancia " << test << "\n";
    for (int i = 0; i < size; i++) {
        int index;
        cin >> index;
        index--;

        cout << letters[index];
        rotate(letters.begin(), letters.begin() + index, letters.begin() + index + 1);
    }

    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}