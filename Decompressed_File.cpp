string decrypt(string &s, unordered_map<string,char> &m)
{
    string ans = "", temp = "";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
        {
            ans.push_back(' ');
            continue;
        }
        temp.push_back(s[i]);
        if(m.find(temp)!=m.end())
        {
            ans.push_back(m[temp]);
            temp = "";
        }
    }
    return ans;
}