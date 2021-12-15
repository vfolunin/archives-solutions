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

    string state;
    cin >> state;

    set<string> states = { "roraima", "acre", "amapa", "amazonas", "para", "rondonia", "tocantins" };

    if (states.count(state))
        cout << "Regiao Norte\n";
    else
        cout << "Outra regiao\n";
}