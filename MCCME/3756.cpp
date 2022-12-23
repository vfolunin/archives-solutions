#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

using Set = bitset<100001>;

Set readSet() {
    string line;
    getline(cin, line);

    if (line == "HELP")
        return {};

    Set res;
    stringstream ss(line);
    int value;
    while (ss >> value)
        res.set(value);
    return res;
}

void process(Set &a, Set &b) {
    Set inter = a & b;
    Set diff = a ^ inter;
    if (inter.count() > diff.count()) {
        cout << "YES\n";
        a = inter;
    } else {
        cout << "NO\n";
        a = diff;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.get();

    Set values;
    for (int value = 1; value <= n; value++)
        values.set(value);

    while (1) {
        Set guess = readSet();
        if (!guess.any())
            break;
        process(values, guess);
    }

    for (int value = 1; value <= n; value++)
        if (values[value])
            cout << value << " ";
}