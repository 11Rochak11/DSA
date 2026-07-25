class Solution {
public:
    int maxProduct(int n) {
     vector<int>s;
     while(n>0){
        s.push_back(n%10);
        n=n/10;
     }
      int largest=s[0];
      int second=-1;
      for(int i=1; i<s.size();i++){
        if(s[i]>largest){
            second=largest;
            largest=s[i] ;
            
        }
        else{
            if(s[i]>second){
            second=s[i];}
        }

      }
      return (largest*second);
    }
};