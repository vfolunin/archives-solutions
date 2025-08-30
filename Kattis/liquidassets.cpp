#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVovel(char c) {
    static const string vowels = "aeiou";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        
        s.erase(unique(s.begin(), s.end()), s.end());

        for (int j = 0; j < s.size(); j++)
            if (j == 0 || j == s.size() - 1 || !isVovel(s[j]))
                cout << s[j];
        cout << " ";
    }
}