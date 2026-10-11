#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> ask(int bit) {
    string s;
    for (int letter = 0; letter < 26; letter++)
        if (bit == -1 || (letter >> bit) % 2)
            s += 'a' + letter;

    cout << "? " << s << endl;

    int posCount;
    cin >> posCount;

    vector<int> pos(posCount);
    for (int &pos : pos) {
        cin >> pos;
        pos--;
    }
    return pos;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int size = ask(-1).size();

    vector<vector<int>> pos(5);
    for (int bit = 0; bit < pos.size(); bit++)
        pos[bit] = ask(bit);

    string res(size, 'a');
    for (int letter = 0; letter < 26; letter++) {
        for (int i = 0; i < res.size(); i++) {
            bool ok = 1;
            for (int bit = 0; bit < pos.size() && ok; bit++)
                ok &= (binary_search(pos[bit].begin(), pos[bit].end(), i) == (letter >> bit) % 2);
            if (ok)
                res[i] += letter;
        }
    }

    cout << "! " << res << endl;
}