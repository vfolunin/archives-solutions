class Solution {
    bool areAnagrams(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    
public:
    vector<string> removeAnagrams(vector<string> &words) {
        vector<string> res = { words[0] };
        for (int i = 1; i < words.size(); i++)
            if (!areAnagrams(res.back(), words[i]))
                res.push_back(words[i]);
        return res;
    }
};