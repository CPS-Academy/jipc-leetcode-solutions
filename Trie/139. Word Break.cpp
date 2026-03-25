class TrieNode{
    public:
    int end;
    TrieNode** children;


    TrieNode(){
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        end = -1;
    }


    void insert(string& s, int id){
        TrieNode* p = this;
        for(int i = 0; i < s.size(); i++){
            int next = s[i] - 'a';
            if(p -> children[next] == nullptr){
                p -> children[next] = new TrieNode();
            }
            p = p -> children[next];
        }
        p -> end = id;
    }


};


class Solution {
    bool* isSegmentableFrom;
public:


    bool isSegmentable(TrieNode* root, string& s, int pos){
        if(isSegmentableFrom[pos] == false) return false;
       
        TrieNode* p = root;
        for(int i = pos; i < s.size(); i++){
            int next = s[i] - 'a';
            if(p -> children[next] == nullptr){
                // starting at position s[pos], no valid word were found
                isSegmentableFrom[pos] = false;
                return false;
            }
            p = p -> children[next];
            if(p -> end >= 0){
                // branch a new call from root at i + 1 position
                bool ret = isSegmentable(root, s, i + 1);
                if(ret == true) return true;
                else{
                    isSegmentableFrom[i + 1] = false;
                }
            }
        }


        if(p -> end >= 0) return true;
        else{
            isSegmentableFrom[pos] = false;
            return false;
        }
    }


    bool wordBreak(string& s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < wordDict.size(); i++){
            root -> insert(wordDict[i], i);
        }


        isSegmentableFrom = new bool[s.size() + 1];
        for(int i = 0; i <= s.size(); i++){
            isSegmentableFrom[i] = true;
        }


        return isSegmentable(root, s, 0);
    }
};
