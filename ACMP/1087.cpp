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
    
    string a, b;
    cin >> a >> b;

    vector<string> names = { "rock", "scissors", "paper" };
    int ai = find(names.begin(), names.end(), a) - names.begin();
    int bi = find(names.begin(), names.end(), b) - names.begin();

    if (ai == bi)
        cout << "draw";
    else if ((ai + 1) % names.size() == bi)
        cout << "first";
    else
        cout << "second";
}