class Solution {
private:
    const int MAX_LETTER_LIMIT = 26;
public:
    vector<int> partitionLabels(string s) {
        vector<int> letter_frequency(MAX_LETTER_LIMIT, 0);
        for(auto& ch: s) {
            letter_frequency[ch - 'a']++;
        }
        vector<int> partitions;
        vector<int> currnet_partition_letter_frequency(MAX_LETTER_LIMIT, 0);
        int current_parition_length = 0;
        for(auto& ch: s) {
            current_parition_length++;
            currnet_partition_letter_frequency[ch - 'a']++;
            bool isCurrentParitionValid = true;
            for(char current_letter = 'a'; current_letter <= 'z';  current_letter++) {
                int current_frequency = currnet_partition_letter_frequency[current_letter - 'a'];
                if(current_frequency > 0 && current_frequency < letter_frequency[current_letter - 'a']) { // is invalid parition
                    isCurrentParitionValid = false;
                    break;
                }
            }
            if(isCurrentParitionValid) {
                partitions.push_back(current_parition_length);
                current_parition_length = 0;
            }
        }
        return partitions;
    }
};