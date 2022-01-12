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

    string date;
    getline(cin, date);

    if (date == "OCT 31" || date == "DEC 25")
        cout << "yup";
    else
        cout << "nope";
}