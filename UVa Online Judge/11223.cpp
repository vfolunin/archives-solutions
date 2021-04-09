#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    static map<string, char> decode = {
        { ".-", 'A' }, { "-...", 'B' }, { "-.-.", 'C' }, { "-..", 'D' }, { ".", 'E' },
        { "..-.", 'F' }, { "--.", 'G' }, { "....", 'H' }, { "..", 'I' }, { ".---", 'J' },
        { "-.-", 'K' }, { ".-..", 'L' }, { "--", 'M' }, { "-.", 'N' }, { "---", 'O' },
        { ".--.", 'P' }, { "--.-", 'Q' }, { ".-.", 'R' }, { "...", 'S' }, { "-", 'T' },
        { "..-", 'U' }, { "...-", 'V' }, { ".--", 'W' }, { "-..-", 'X' }, { "-.--", 'Y' },
        { "--..", 'Z' }, { "-----", '0' }, { ".----", '1' }, { "..---", '2' }, { "...--", '3' },
        { "....-", '4' }, { ".....", '5' }, { "-....", '6' }, { "--...", '7' }, { "---..", '8' },
        { "----.", '9' }, { ".-.-.-", '.' }, { "--..--", ',' }, { "..--..", '?' }, { ".----.", '\'' },
        { "-.-.--", '!' }, { "-..-.", '/' }, { "-.--.", '(' }, { "-.--.-", ')' }, { ".-...", '&' },
        { "---...", ':' }, { "-.-.-.", ';' }, { "-...-", '=' }, { ".-.-.", '+' }, { "-....-", '-' },
        { "..--.-", '_' }, { ".-..-.", '"' }, { ".--.-.", '@' }
    };

    if (test > 1)
        cout << "\n";
    cout << "Message #" << test << "\n";

    string line, code;
    int space = -1;
    getline(cin, line);

    for (char c : line) {
        if (!isspace(c)) {
            code += c;
            space = 0;
        } else {
            if (space == -1)
                continue;
            if (!code.empty()) {
                cout << decode[code];
                code.clear();
            }
            if (space == 1)
                cout << " ";
            space++;
        }
    }
    if (!code.empty()) {
        cout << decode[code];
        code.clear();
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}