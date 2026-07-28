class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        int mid = left + (right-left)/2;
        if(n%2==1){
        sort(s.begin(),s.begin()+mid);
        sort(s.begin()+mid+1,s.end(),greater<char>());
        }
        else{
            sort(s.begin(),s.begin()+mid+1);
            sort(s.begin()+mid+1,s.end(),greater<char>());
        }
        // for(int i= 0 ; i<mid+1 ; i++){
        //     s[n-1-i] = s[i];
        // }
        return s;
    }
};