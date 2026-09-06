class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for(string s : wordList)wordSet.insert(s);

        if(!wordSet.count(endWord)) return 0;

        deque<string> dq;
        wordSet.erase(beginWord);
        dq.push_back(beginWord);
        int lvl = 1;

        while(!dq.empty()){
            int size = dq.size();
            while(size--){
                string currentWord = dq.front();
                dq.pop_front();

                if (currentWord == endWord) return lvl; 
                
                
                for(int i = 0; i < currentWord.size(); i++){
                    for(char r = 'a'; r <= 'z'; r++){
                        string newWord = currentWord;
                        if(r != currentWord[i]){
                            newWord[i] = r;
                        }
                        if(wordSet.count(newWord)){
                            wordSet.erase(newWord);
                            dq.push_back(newWord);
                        }
                    } 
                }
            }
            lvl++;
        }

        return 0;
    }
};
