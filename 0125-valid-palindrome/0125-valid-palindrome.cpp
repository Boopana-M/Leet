class Solution {
public:
    bool isPali(string s)
    {
        int len = s.size();
        int start = 0;
        int end = len-1;
        while(start<end)
        {
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string raw = "";
        for(char c:s)
        {
            if(c>='a' && c<='z')
            {
                raw+=c;
            }
            else if(c>='A' && c<='Z'){
                raw+= tolower(c);
            }
            else if(c>='0' && c<='9')
            {
                raw+=c;
            }
        }
        return isPali(raw);
    }
};