class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        unordered_map<int,int> rank;

        int currentRank = 1;

        for(int num : temp){

            if(rank.count(num) == 0){

                rank[num] = currentRank;
                currentRank++;
            }
        }

        for(int i=0;i<arr.size();i++){

            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};