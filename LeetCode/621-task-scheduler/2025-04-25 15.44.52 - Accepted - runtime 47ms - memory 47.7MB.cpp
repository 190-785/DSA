class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0)
                maxHeap.push(f);
        }

        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycles = n + 1;

            while (cycles > 0 && !maxHeap.empty()) {
                int taskFreq = maxHeap.top();
                maxHeap.pop();
                if (--taskFreq > 0)
                    temp.push_back(taskFreq);
                time++;
                cycles--;
            }

            for (int t : temp)
                maxHeap.push(t);

            if (!maxHeap.empty())
                time += cycles;
        }

        return time;
    }
};
