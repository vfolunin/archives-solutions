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

    int soundCount;
    cin >> soundCount;

    vector<string> sounds = {
        "clank", "bong", "click", "tap", "poing",
        "clonk", "clack", "ping", "tip", "cloing",
        "tic", "cling", "bing", "pong", "clang",
        "pang", "clong", "tac", "boing", "boink",
        "cloink", "rattle", "clock", "toc", "clink", "tuc"
    };

    bool capsLock = 0, shift = 0;
    string text;

    for (int i = 0; i < soundCount; i++) {
        string sound;
        cin >> sound;

        if (sound == "whack") {
            text += " ";
        } else if (sound == "bump") {
            capsLock ^= 1;
        } else if (sound == "dink") {
            shift = 1;
        } else if (sound == "thumb") {
            shift = 0;
        } else if (sound == "pop") {
            if (!text.empty())
                text.pop_back();
        } else {
            int pos = find(sounds.begin(), sounds.end(), sound) - sounds.begin();
            text += (capsLock ^ shift ? 'A' : 'a') + pos;
        }
    }

    cout << text;
}