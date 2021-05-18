#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int songCount, diskLength, diskCount;
    cin >> songCount >> diskLength >> diskCount;

    vector<vector<vector<int>>> songs(2, vector<vector<int>>(diskCount + 1, vector<int>(diskLength + 1)));
    for (int i = 0; i < songCount; i++) {
        int song;
        cin >> song;
        cin.ignore();

        for (int count = 1; count <= diskCount; count++) {
            for (int length = 0; length <= diskLength; length++) {
                if (length + song <= diskLength)
                    songs[1][count][length + song] = max(songs[1][count][length + song], songs[0][count][length] + 1);
                else if (count < diskCount)
                    songs[1][count + 1][song] = max(songs[1][count + 1][song], songs[0][count][length] + 1);
            }
        }

        songs[0] = songs[1];
    }

    int res = 0;
    for (int count = 1; count <= diskCount; count++)
        for (int length = 0; length <= diskLength; length++)
            res = max(res, songs[0][count][length]);

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}