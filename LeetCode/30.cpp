struct Counter {
    vector<int> count;
    int nonZeroCount = 0;

    Counter(int size) : count(size) {}

    void add(int i, int delta) {
        nonZeroCount -= count[i] > 0;
        count[i] += delta;
        nonZeroCount += count[i] > 0;
    }
};

class Solution {
    unordered_map<string, pair<int, int>> dict;
    
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        for (string &word : words) {
            if (dict.count(word))
                dict[word].second++;
            else
                dict[word] = { dict.size() + 1, 1 };
        }
        
        Counter referenceCounter(words.size() + 1);
        for (auto &[word, data] : dict)
            referenceCounter.add(data.first, data.second);
        
        int wordCount = words.size(), wordSize = words[0].size(), patternSize = wordCount * wordSize;
        vector<int> res;
        
        for (int start = 0; start < wordSize && start + patternSize <= s.size(); start++) {
            Counter counter = referenceCounter;
            
            for (int from = start; from + wordSize <= s.size(); from += wordSize) {
                if (from >= patternSize)
                    counter.add(dict[s.substr(from - patternSize, wordSize)].first, 1);
                counter.add(dict[s.substr(from, wordSize)].first, -1);
                
                if (!counter.nonZeroCount)
                    res.push_back(from - patternSize + wordSize);
            }
        }
        
        return res;
    }
};