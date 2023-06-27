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

    int messageCount;
    cin >> messageCount;

    map<int, int> messageTopicId;
    map<int, string> topicName;
    map<string, int> topicId, topicSize;

    for (int id = 1; id <= messageCount; id++) {
        int prevId;
        cin >> prevId;

        if (prevId) {
            string message;
            getline(cin, message);
            getline(cin, message);

            messageTopicId[id] = messageTopicId[prevId];
            topicSize[topicName[messageTopicId[id]]]++;
        } else {
            string topic, message;
            getline(cin, topic);
            getline(cin, topic);
            getline(cin, message);

            messageTopicId[id] = topicId[topic] = id;
            topicName[id] = topic;
            topicSize[topic] = 1;
        }
    }

    string res = topicId.begin()->first;
    for (auto &[topic, size] : topicSize)
        if (topicSize[res] < size || topicSize[res] == size && topicId[res] > topicId[topic])
            res = topic;

    cout << res;
}