string encrypt(string &s, unordered_map<char,string> &m)
{
    string ans = "";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==' ')
            ans.push_back(' ');
        else
            ans+=m[s[i]];
    }
    return ans;
}