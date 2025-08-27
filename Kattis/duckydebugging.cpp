#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (1) {
        string s;
        getline(cin, s);

        if (s == "I quacked the code!")
            break;

        cout << (s.back() == '.' ? "*Nod*" : "Quack!") << endl;
    }
}