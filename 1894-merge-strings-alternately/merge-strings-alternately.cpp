class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string str="";
        while(i<word1.size() && j<word2.size()){
            str+=word1[i];
            str+=word2[j];
            i++;
            j++;
        }
        if(i<word1.size()){
            while(i<word1.size()){
                str+=word1[i];
                i++;
            }
        }
      
      if(j<word2.size()){
            while(j<word2.size()){
                str+=word2[j];
                j++;
            }
        }

        return str;
    }
};