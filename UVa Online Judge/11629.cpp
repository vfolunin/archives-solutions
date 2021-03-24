#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int partyCount, guessCount;
    cin >> partyCount >> guessCount;

    map<string, double> partyResult;
    for (int i = 0; i < partyCount; i++) {
        string name;
        cin >> name >> partyResult[name];
    }

    for (int i = 0; i < guessCount; i++) {
        double result = 0;

        string name, op;
        do {
            cin >> name >> op;
            result += partyResult[name];
        } while (op == "+");

        double guess;
        cin >> guess;

        bool correct = 0;
        correct |= op == "<" && result < guess - EPS;
        correct |= op == "<=" && result <= guess + EPS;
        correct |= op == "=" && abs(result - guess) < EPS;
        correct |= op == ">=" && result >= guess - EPS;
        correct |= op == ">" && result > guess + EPS; 

        cout << "Guess #" << i + 1 << " was " << (correct ? "" : "in") << "correct.\n";
    }
}