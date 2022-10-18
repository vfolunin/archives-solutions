class TextEditor {
    string l, r;
    
public:    
    void addText(string text) {
        l += text;
    }
    
    int deleteText(int k) {
        int res = 0;
        for ( ; !l.empty() && res < k; res++)
            l.pop_back();
        return res;
    }
    
    string cursorLeft(int k) {
        for (int i = 0; !l.empty() && i < k; i++) {
            r.push_back(l.back());
            l.pop_back();
        }
        return l.substr(l.size() - min<int>(l.size(), 10));
    }
    
    string cursorRight(int k) {
        for (int i = 0; !r.empty() && i < k; i++) {
            l.push_back(r.back());
            r.pop_back();
        }
        return l.substr(l.size() - min<int>(l.size(), 10));
    }
};