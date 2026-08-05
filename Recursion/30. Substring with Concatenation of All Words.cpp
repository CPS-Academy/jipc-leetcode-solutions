class Solution {
private:
    int wordSize;
    int windowSize;
    unordered_map<string, int> runningWordFrequency;
    unordered_map<string, int> wordFrequency;

    int processInitialString(int index, string& s) {
        if(s.size() < index + windowSize) {
            return 0;
        }
        runningWordFrequency.clear();
        int wordCoverage = 0;
        for(int j = index; j < index + windowSize; j += wordSize) {
            string wordChunk = s.substr(j, wordSize);
            runningWordFrequency[wordChunk]++;
            if(runningWordFrequency[wordChunk] <= wordFrequency[wordChunk]) {
                wordCoverage++;
            }
        }
        return wordCoverage;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        for(auto& word: words) {
            wordFrequency[word]++;
        }

        vector<int> startingIndexes;
        wordSize = words[0].size();
        for(int i = 0; i < wordSize; i++) {
            windowSize = words.size()*wordSize;
            int wordCoverage = processInitialString(i, s);

            if(wordCoverage == words.size()) {
                startingIndexes.push_back(i);
            }

            for(int L = i, R = i + windowSize; R + wordSize - 1 < s.size(); L += wordSize, R += wordSize) {
                string firstWord = s.substr(L, wordSize);
                runningWordFrequency[firstWord]--;
                if(runningWordFrequency[firstWord] < wordFrequency[firstWord]) {
                    wordCoverage--;
                }
                string lastWord = s.substr(R, wordSize);
                runningWordFrequency[lastWord]++;
                if(runningWordFrequency[lastWord] <= wordFrequency[lastWord]) {
                    wordCoverage++;
                }

                if(wordCoverage == words.size()) {
                    startingIndexes.push_back(L + wordSize);
                }
            }
        }
        return startingIndexes;
    }
};