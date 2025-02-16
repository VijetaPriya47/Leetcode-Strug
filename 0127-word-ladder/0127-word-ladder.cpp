class Solution {
public:
//THis could be done by vector since all the elements are unique in the wordlist,
//BUt Because find, erase these type of things becomes a little complicated in vector,
// hence set is used
//Set has easy to erase element method because set has all unique elements,
// but since vector is built for duplicate elements also, we have to earse elements by it's index position, bcs tht's wht is unique in a vector.
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