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

    string s;
    cin >> s;

    vector<string> fingers = {
        "1QAZ", "2WSX", "3EDC", "4RFV5TGB", "6YHN7UJM", "8IK,", "9OL.", "0P;/-['=]"
    };

    vector<int> res(fingers.size());
    for (char c : s)
        for (int i = 0; i < fingers.size(); i++)
            res[i] += fingers[i].find(c) != -1;
    
    for (int value : res)
        cout << value << "\n";
}