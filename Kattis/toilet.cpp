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

    string mode;
    cin >> mode;

    vector<int> score(3);
    for (int i = 1; i < mode.size(); i++) {
        score[0] += mode[i] != (i == 1 ? mode[0] : 'U');
        score[0] += mode[i] != 'U';

        score[1] += mode[i] != (i == 1 ? mode[0] : 'D');
        score[1] += mode[i] != 'D';

        score[2] += mode[i - 1] != mode[i];
    }

    for (int s : score)
        cout << s << "\n";
}