string readAndPrint(const char *filename, unordered_map<char,int> &m)
{
    string ans = "";
    ifstream file(filename);
    if(file.is_open()) 
    {
        string line;
        while(getline(file, line))
        {
            string s = line.c_str();
            string s1 = "";
            for(int i=0; i<s.length(); i++)
            {
                ans.push_back(s[i]);
                if(s[i]!=' ')
                    m[s[i]]++;
            }
        }
        file.close();
    }
    return ans;
}
