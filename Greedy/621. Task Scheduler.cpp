class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        for(char &ch: tasks) {
            frequency[ch - 'A']++;
        }
        
        priority_queue<int> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(frequency[i] > 0) {
                maxHeap.push(frequency[i]);
            }
        }

        int minTimeToExecute = 0;
        while(!maxHeap.empty()) {
            vector<int> updatedFrequency;
            int taskCount = 0;
            while(taskCount < n + 1 && !maxHeap.empty()) {
                if(maxHeap.top() > 1) {
                    updatedFrequency.push_back(maxHeap.top());
                }
                maxHeap.pop();
                taskCount++;
            }
            for(int &updatedTask: updatedFrequency) {
                maxHeap.push(updatedTask - 1);
            }
            minTimeToExecute += maxHeap.empty() ? taskCount : n + 1;
        }
        return minTimeToExecute;
    }
};