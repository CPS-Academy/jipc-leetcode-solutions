struct Trie{
    Trie* children[26];
    int ends;
    vector<int> pal_suffixes;


    Trie(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        ends = -1;
        pal_suffixes.clear();
    }
};


class Solution {


    int** p_man;


    bool ispalindrome(int id, int l, int r){
        if(l > r) return false;
        l <<= 1; r = (r << 1) + 2;
        int c = (l + r) >> 1;
        return c - p_man[id][c] <= l;
    }


    void insert(Trie* root, string& s, int id){
        Trie* cur = root;
        int n = s.size();
        if(ispalindrome(id, 0, n - 1)){
            cur -> pal_suffixes.push_back(id);
        }
        for(int i = 0; i < n; i++){
            int c = s[i] - 'a';


            if(cur -> children[c] == nullptr){
                cur -> children[c] = new Trie();
            }


            cur = cur -> children[c];
            if(ispalindrome(id, i + 1, n - 1)){
                cur -> pal_suffixes.push_back(id);
            }
        }
        cur -> ends = id;
    }


    void search(Trie* root, string& s, int id, vector<vector<int>>& ppi){
        Trie* cur = root;
        int n = s.size();
        if(cur -> ends >= 0 && ispalindrome(id, 0, n - 1)){
            ppi.push_back({cur -> ends, id});
        }
        int i;
        for(i = n - 1; i >= 0; i--){
            int c = s[i] - 'a';


            if(cur -> children[c] == nullptr){
                break;
            }


            cur = cur -> children[c];
            if(cur -> ends >= 0 && ispalindrome(id, 0, i - 1)){
                ppi.push_back({cur -> ends, id});
            }
        }
        if(i < 0){
            if(cur -> ends >= 0 && cur -> ends != id){
                ppi.push_back({cur -> ends, id});
            }
            for(int pid: cur -> pal_suffixes){
                if(pid != id)
                    ppi.push_back({pid, id});
            }
        }
    }


    void manacher(string& s_org, int id){
        string s = "#";
        for(char c: s_org){
            s += c; s += "#";
        }
        int n = s.size();
        int* p = new int[n];
        p[0] = 0;
        int c = 0, r = 0;
        for(int i = 1; i < n; i++){
            p[i] = 0;
            if(i < r)
                p[i] = min(r - i, p[c + c - i]);
           
            while(i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
                    s[i + p[i] + 1] == s[i - p[i] - 1]){
                        p[i]++;
                    }
            if(i + p[i] > r){
                c = i;
                r = i + p[i];
            }
        }
        p_man[id] = p;
    }


public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        p_man = new int*[n];


        Trie* root = new Trie();
        for(int i = 0; i < n; i++){
            manacher(words[i], i);
            insert(root, words[i], i);
        }


        vector<vector<int>> palindrome_pairs_indices;
        for(int i = 0; i < n; i++){
            search(root, words[i], i, palindrome_pairs_indices);
        }
        return palindrome_pairs_indices;
    }
};
