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
    bool *isSegmentableFrom;
public:
    vector<string> getSegments(TrieNode* root, string& s, int pos){
        if(isSegmentableFrom[pos] == false) return {};
       
        TrieNode* p = root;
        string cur = "";
        vector<string> ret;
        int i;
        for(i = pos; i < s.size(); i++){
            int next = s[i] - 'a';
            if(p -> children[next] == nullptr){
                // starting at position s[pos], no valid direct word were found
                break;
            }
            p = p -> children[next];
            cur += s[i]; // cat
            if(p -> end >= 0){
                // branch a new call from root at i + 1 position
                vector<string> temp = getSegments(root, s, i + 1);
                if(temp.size() > 0) {
                    for(int j = 0; j < temp.size(); j++){
                        ret.push_back(cur + " " + temp[j]);
                        // cat sand
                        // cat sa nd
                        // cat s and
                    }
                }
            }
        }


        if(p -> end >= 0 && i == s.size()) {
            ret.push_back(cur);
        }


        if(ret.size() == 0) isSegmentableFrom[pos] = false;
        return ret;
    }


    vector<string> wordBreak(string& s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < wordDict.size(); i++){
            root -> insert(wordDict[i], i);
        }




        isSegmentableFrom = new bool[s.size() + 1];
        for(int i = 0; i <= s.size(); i++){
            isSegmentableFrom[i] = true;
        }


        vector<string> ret;
        ret = getSegments(root, s, 0);
       
        return ret;
    }
};
