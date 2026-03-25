class Solution {
        vector<int> ancestor = vector<int>(26);
        vector<int> size = vector<int>(26);


    int findAncestor(int a){
        if(ancestor[a] != a)
            ancestor[a] = findAncestor(ancestor[a]); // path compression
        return ancestor[a];
        // without nothing, O(n)
        // with path compression, O(logn)
        // with size compression, O(logn)
        // with both, O(a(n)) ~= constant
    }
public:
    bool equationsPossible(vector<string>& equations) {
        // a == b
        // a == c
        // b != c


        for(int i = 0; i < 26; i++){
            size[i] = 1;
            ancestor[i] = i;
        }


        for(string eq : equations){
            if(eq[1] == '!') continue;


            int a = eq[0] - 'a', b = eq[3] - 'a';


            int ap = findAncestor(a), bp = findAncestor(b);
            // ancestor[ap] = bp;
            // ancestor[bp] = ap;


            if(ap == bp) continue;
            if(size[ap] > size[bp]){
                ancestor[bp] = ap;
                size[ap] += size[bp];
            }
            else{
                ancestor[ap] = bp;
                size[bp] += size[ap];
            }
        }
       
        for(string eq : equations){
            if(eq[1] == '=') continue;


            int a = eq[0] - 'a', b = eq[3] - 'a';


            int ap = findAncestor(a), bp = findAncestor(b);
            // ancestor[ap] = bp;
            // ancestor[bp] = ap;


            if(ap == bp) return false;
        }


        return true;
    }
};
