#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dividesBy(string &number, int divisor) {
    int residual = 0;
    for (char digit : number)
        residual = (residual * 2 + digit - '0') % divisor;
    return !residual;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string number;
    int divisorCount;
    cin >> number >> divisorCount;

    vector<int> divisors;
    for (int i = 0; i < divisorCount; i++) {
        int divisor;
        cin >> divisor;
        if (dividesBy(number, divisor))
            divisors.push_back(divisor);
    }

    sort(divisors.begin(), divisors.end());

    if (divisors.empty()) {
        cout << "Nenhum\n";
    } else {
        for (int i = 0; i < divisors.size(); i++)
            cout << divisors[i] << (i + 1 < divisors.size() ? " " : "\n");
    }
}