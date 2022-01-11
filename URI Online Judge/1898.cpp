#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string readId() {
    string id;

    while (id.size() < 11) {
        char c;
        cin >> c;

        if (isdigit(c))
            id += c;
    }

    return id;
}

double readValue() {
    string value;
    int dot = -1;

    char c;
    while (cin >> c) {
        if (c == '\n')
            break;
        
        if (isdigit(c)) {
            value += c;
            if (dot != -1) {
                dot--;
                if (!dot) {
                    while (cin >> c && c != '\n');
                    break;
                }
            }
        }

        if (c == '.' && dot == -1) {
            value += c;
            dot = 2;
        }
    }

    return stod(value);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> noskipws;

    cout << "cpf " << readId() << "\n";
    cout.precision(2);
    cout << fixed << readValue() + readValue() << "\n";
}