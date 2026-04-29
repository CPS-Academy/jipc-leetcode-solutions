class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString = "";
        for(string& s: strs) {
            encodedString += to_string(s.size()) + '#' + s;
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedString;

        int i = 0;
        while(i < s.size()) {
            int j = i; // starting of length in number
            while(s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i)); // 5
            j++;

            string word = s.substr(j, length); // samin
            decodedString.push_back(word);

            i = j + length;
        }
        return decodedString;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));