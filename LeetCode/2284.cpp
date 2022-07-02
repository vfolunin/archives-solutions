class Solution {
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders) {
        unordered_map<string, int> wordCount;
        for (int i = 0; i < messages.size(); i++)
            wordCount[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
        
        int resCount = 0;
        string res;
        
        for (auto &[sender, count] : wordCount) {
            if (resCount < count || resCount == count && res < sender) {
                resCount = count;
                res = sender;
            }
        }
        
        return res;
    }
};
