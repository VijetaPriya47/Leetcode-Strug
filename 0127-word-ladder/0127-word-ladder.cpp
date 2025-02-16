class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string& word: wordList) {
            st.insert(word);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto [word, len] = q.front();
            q.pop();
            if(word == endWord) return len;

            for(int i = 0; i < word.size(); i++) {
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word, len+1});
                        st.erase(word);
                    }
                }
                word = temp;
            }
        }
        return 0;
    }
};