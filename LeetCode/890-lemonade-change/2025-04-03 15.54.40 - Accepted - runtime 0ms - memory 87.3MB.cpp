class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        pair<int, int> bill = {0, 0};
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                bill.first++;
            else if (bills[i] == 10) {
                bill.second++;
                if (bill.first == 0)
                    return false;
                else
                    bill.first--;
            } else {
                if (bill.second == 0) {
                    if (bill.first < 3)
                        return false;
                    bill.first -= 3;
                } else {
                    bill.second--;
                    if (bill.first == 0)
                        return false;
                    bill.first--;
                }
            }
        }
        return true;
    }
};