#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string current = "";
        for (char t : target) {
            current += 'a';
            result.push_back(current);
            while (current.back() != t) {
                current.back() =(current.back() == 'z') ? 'a' : current.back() + 1;
                result.push_back(current);
            }
        }
        return result;
    }
};
