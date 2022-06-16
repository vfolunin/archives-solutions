class Solution {
    vector<string> split(string &line, const string &separators) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (separators.find(c) == -1) {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }
    
public:
    vector<string> subdomainVisits(vector<string> &domains) {
        unordered_map<string, int> visitCount;
        
        for (string &domain : domains) {
            vector<string> parts = split(domain, " .");
            int visits = stoi(parts[0]);
            
            string subdomain;
            for (int i = parts.size() - 1; i; i--) {
                subdomain = parts[i] + (subdomain.empty() ? "" : ".") + subdomain;
                visitCount[subdomain] += visits;
            }
        }
        
        vector<string> res;
        for (const auto &[subdomain, visits] : visitCount)
            res.push_back(to_string(visits) + " " + subdomain);
        return res;
    }
};