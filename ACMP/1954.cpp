#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> getGrayCodes(int size) {
    if (!size)
        return { "" };

    vector<string> res0, res1;
    for (string code : getGrayCodes(size - 1)) {
        res0.push_back("0" + code);
        res1.push_back("1" + code);
    }
    reverse(res1.begin(), res1.end());

    res0.insert(res0.end(), res1.begin(), res1.end());
    return res0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (string &code : getGrayCodes(size)) {
        for (int i = 0; i < code.size(); i++)
            cout << (code[i] == '1' ? a[i] : 0) << " ";
        cout << "\n";
    }
}