class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0,maxF=0,res=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            maxF=max(maxF,mp[s[r]]);
            while((r-l+1)-maxF>k){
                mp[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
