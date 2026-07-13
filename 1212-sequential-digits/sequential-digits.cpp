class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string digit1 = to_string(low);
        string digit2 = to_string(high);

        vector<int> ans;

        for(int i = digit1.size(); i <= digit2.size(); i++) {

            for(int j = 1; j <= 10 - i; j++) {

                string guess = "";
                int l = j;

                for(int k = 0; k < i; k++) {
                    guess += to_string(l);
                    l++;
                }

                int guessed = stoi(guess);

                if(guessed < low)
                    continue;

                else if(guessed > high)
                    break;

                ans.push_back(guessed);
            }
        }

        return ans;
    }
};