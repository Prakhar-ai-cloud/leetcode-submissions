class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        vector<int> half(26, 0);
        string mid = "";
        int m = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid += (char)(i + 'a');
            }
            half[i] = freq[i] / 2;
            m += half[i];
        }
        
        auto get_ways = [&](const vector<int>& f, long long target_k) {
            long long ways = 1;
            int curr_len = 0;
            for (int count : f) {
                if (count > 0) {
                    curr_len += count;
                    long long n = curr_len;
                    long long r = count;
                    
                    if (r > n - r) r = n - r;
                    long long cur_nCr = 1;
                    
                    for (int i = 1; i <= r; ++i) {
                        cur_nCr = cur_nCr * (n - i + 1) / i;
                        if (cur_nCr > target_k) {
                            cur_nCr = target_k + 1;
                            break;
                        }
                    }
                    ways *= cur_nCr;
                    if (ways > target_k) return target_k + 1;
                }
            }
            return ways;
        };
        
        if (get_ways(half, k) < k) {
            return "";
        }
        
        string first_half = "";
        for (int i = 0; i < m; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half[c] > 0) {
                    half[c]--;
                    long long ways = get_ways(half, k);
                    
                    if (ways >= k) {
                        first_half += (char)(c + 'a');
                        break; 
                    } else {
                        k -= ways;
                        half[c]++;
                    }
                }
            }
        }
        
        string res = first_half + mid;
        for (int i = m - 1; i >= 0; --i) {
            res += first_half[i];
        }
        return res;
    }
};
    // __int128 count_permutations(map<char,int>& mp, vector<__int128>& factorial){
    //   int remaining = 0;
    //   for(auto &it:mp){
    //     remaining+=it.second;
    //   }
    //   __int128 answer = factorial[remaining];
    //   for(auto &it:mp){
    //     answer/=factorial[it.second];
    //   }
    //   return answer;
    // }

    // void backtrack(int index , int k , string& halfstring, string& answer,map<char,int>& mp, vector<__int128>& factorial){
    //    if(index == halfstring.size()) return;
    //    for(auto &it : mp){
    //         if(it.second==0) continue;
    //         mp[it.first]--;
    //         __int128 check = count_permutations(mp,factorial);
    //         if(check >= k){
    //             answer+= it.first;
    //             backtrack(index+1,k,halfstring,answer,mp,factorial);
    //             mp[it.first]++;
    //             return;
    //         }
    //         else{
    //             k-=check;
    //             mp[it.first]++;
    //         }
    //    }
    // }
    // string smallestPalindrome(string s, int k) {
    //     int n = s.size();
    //     int halfcount = n/2;
    //     string halfstring = s.substr(0,halfcount);
    //     map<char,int> mp;
    //     sort(halfstring.begin(),halfstring.end());
    //     for(int i=0;i<n/2;i++){
    //         mp[halfstring[i]]++;
    //     }
    //     vector<__int128> factorial(halfcount+1,1);
    //     for(int i=1;i<factorial.size();i++){
    //         factorial[i] = i*factorial[i-1];
    //     }

    //     __int128 total = count_permutations(mp,factorial);
    //     if(k>total) return "";

    //     string answer;
    //     backtrack(0,k,halfstring,answer,mp,factorial);
    //     string copy = answer;
    //     reverse(copy.begin(),copy.end());
    //     char mid_element;
    //     if(n%2==1) mid_element = s[halfcount];
    //     if(n%2==1) answer = answer + mid_element + copy;
    //     else answer = answer + copy;
    //     return answer;
    // }



// class Solution {
// public:
//     void backtrack(int index , string& halfstring, vector<string>& answer ){
//         if(index==halfstring.size()){
//             answer.push_back(halfstring);
//             return;
//         }
//         unordered_set<char> used;
//         for(int i=index ; i<halfstring.size();i++){
//             if(used.count(halfstring[i])) continue;
//             used.insert(halfstring[i]);
//             swap(halfstring[i],halfstring[index]);
//             backtrack(index+1,halfstring,answer);
//             swap(halfstring[i],halfstring[index]);

//         }
//     }
//     string smallestPalindrome(string s, int k) {
//         int n = s.size();
//         int halfcount = n/2;
//         string halfstring = s.substr(0,halfcount);
//         sort(halfstring.begin(),halfstring.end());
//         vector<string> answer; 
//         backtrack(0,halfstring,answer);
//         if(k > answer.size()) return "";
//         char mid_element;
//         if(n%2 == 1) mid_element = s[halfcount];
//         sort(answer.begin(), answer.end());
//         string kthsmallestpalindrome = answer[k-1];
//         string copy = kthsmallestpalindrome;
//         reverse(copy.begin(),copy.end());
//         if(n%2==0){
//             kthsmallestpalindrome += copy;
//         }
//         else{
//             kthsmallestpalindrome += mid_element;
//             kthsmallestpalindrome += copy;
//         }
//         return kthsmallestpalindrome;
//     }
// };