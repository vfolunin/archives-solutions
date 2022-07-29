struct Trie {
    struct Node {
        map<char, Node> next;
        bool isTerminal = 0;
    } root;

    void insert(string &s) {
        Node *n = &root;
        for (char c : s)
            n = &n->next[c];
        n->isTerminal = 1;
    }
    
    string find(string &s) {
        string res;
            
        Node *n = &root;
        for (char c : s) {
            if (!n->next.count(c))
                return s;
            
            res += c;
            n = &n->next[c];
            if (n->isTerminal)
                return res;
        }
        
        return s;
    }
};

class Solution {
    vector<string> split(string &line) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
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

    string join(vector<string> &words) {
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? " " : "");
        return line;
    }
    
public:
    string replaceWords(vector<string> &dict, string &line) {
        Trie trie;
        for (string &word : dict)
            trie.insert(word);
        
        vector<string> words = split(line);
        for (string &word : words)
            word = trie.find(word);
        return join(words);
    }
};