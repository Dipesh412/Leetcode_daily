class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.push({beginWord,1});

        while(!q.empty()){
            string x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == endWord){
                return y;
            }
            for(int i=0; i<x.size(); i++){
                char original =x[i];
                for(char ch='a'; ch <= 'z'; ch++){
                    x[i] = ch;
                    if(st.find(x) != st.end()){
                        st.erase(x);
                        q.push({x,y+1});
                    }
                }
                x[i] = original;
            }
        }

        return 0;
    }
};