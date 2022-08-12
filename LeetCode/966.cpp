class Solution {
    string toLower(string s) {
        for (char &c : s)
            c = tolower(c);
        return s;
    }
    
    string unifyVowels(string s) {
        static const string VOWELS = "aeiou";
        for (char &c : s)
            if (VOWELS.find(c) != -1)
                c = 'a';
        return s;
    }
    
public:
    vector<string> spellchecker(vector<string> &words, vector<string> &queries) {
        unordered_map<string, string> identity;
        for (string &word : words)
            identity[word] = word;
        
        unordered_map<string, string> lowered;
        for (string &word : words) {
            string loweredWord = toLower(word);
            if (!lowered.count(loweredWord))
                lowered[loweredWord] = word;
        }
        
        unordered_map<string, string> unified;
        for (string &word : words) {
            string unifiedWord = unifyVowels(toLower(word));
            if (!unified.count(unifiedWord))
                unified[unifiedWord] = word;
        }
        
        vector<string> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            if (identity.count(queries[i])) {
                res[i] = identity[queries[i]];
                continue;
            }
            
            queries[i] = toLower(queries[i]);
            if (lowered.count(queries[i])) {
                res[i] = lowered[queries[i]];
                continue;
            }
            
            queries[i] = unifyVowels(queries[i]);
            if (unified.count(queries[i]))
                res[i] = unified[queries[i]];
        }
        return res;
    }
};