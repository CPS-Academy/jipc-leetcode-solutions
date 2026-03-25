struct TrieNode{
    TrieNode* children[26];
    int count;


    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        count = 0;
    }


    void insert(string& s){
        TrieNode* cur = this;
        cur -> count++;
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(cur -> children[c] == nullptr){
                cur -> children[c] = new TrieNode();
            }
            cur = cur -> children[c];
            cur -> count++;
        }
    }


    int search(int target){
        TrieNode* cur = this;
        int i, len = 0;
        while(true){
            for(i = 0; i < 26; i++){
                if(cur -> children[i] != nullptr && cur -> children[i] -> count == target){
                    cur = cur -> children[i];
                    break;
                }
            }
            if(i == 26){
                // no more LCP
                break;
            }
            else{
                len++;
            }
        }
        return len;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // skje
        // skjd
        // skp
        // ??????
        // ??????
        // ?????


        TrieNode* root = new TrieNode();
        for(string s : strs){
            root -> insert(s);
        }


        int LCPlen = root -> search(strs.size());
        return strs[0].substr(0, LCPlen);
    }
};
