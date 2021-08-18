#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string letters;
    cin >> letters;

    if (letters == "finish")
        return 0;

    for (char &c : letters)
        c = tolower(c);

    int printableCount = 0;
    vector<int> used(26);

    cin.ignore();
    while (1) {
        string line;
        getline(cin, line);

        bool printable = 1;
        for (char c : line)
            if (isalpha(c))
                printable &= letters.find(tolower(c)) == -1;
        printableCount += printable;

        if (printable)
            for (char c : line)
                if (isalpha(c))
                    used[tolower(c) - 'a']++;

        if (line == "END")
            break;
    }

    string additional;
    for (char c = 'a'; c <= 'z'; c++)
        if (!used[c - 'a'] && letters.find(c) == -1)
            additional += c;

    cout << "|   " << setw(3) << right << test << "    ";
    cout << "|      " << setw(3) << right << printableCount << "       ";
    cout << "| " << setw(28) << left << additional << "|\n";
    cout << "+----------+----------------+-----------------------------+\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << "+----------+----------------+-----------------------------+\n";
    cout << "| Keyboard | # of printable | Additionally, the following |\n";
    cout << "|          |      lines     |  letter keys can be broken  |\n";
    cout << "+----------+----------------+-----------------------------+\n";

    for (int test = 1; solve(test); test++);
}