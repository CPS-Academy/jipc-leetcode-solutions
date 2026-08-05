class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h_index = 0;
        for(int i = 0; i < citations.size(); i++) {
            if(citations[i] >= i + 1) {
                h_index = i + 1;
            }
        }
        return h_index;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxCitation = 0;
        for(int& citation: citations) {
            maxCitation = max(maxCitation, citation);
        }

        int lo = 0, hi = maxCitation;
        int h_index = 0;
        while(lo <= hi) {
            int minCitationCandidates = lo + (hi - lo)/2;
            int minCitationCandidateCount = 0;
            for(int& citation: citations) {
                if(citation >= minCitationCandidates) {
                    minCitationCandidateCount++;
                }
            }
            if(minCitationCandidates <= minCitationCandidateCount) {
                h_index = minCitationCandidates;
                lo = minCitationCandidates + 1;
            }
            else {
                hi = minCitationCandidates - 1;
            }
        }
        return h_index;
    }
};