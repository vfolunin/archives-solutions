class Solution {
public:
    string capitalizeTitle(string title) {
        string res, word;
        title += " ";
        
        for (char c : title) {
            if (c != ' ') {
                word += tolower(c);
            } else {
                if (word.size() > 2)
                    word[0] = toupper(word[0]);
                
                if (!res.empty())
                    res += " ";
                res += word;
                
                word.clear();
            }
        }
        
        return res;
    }
};