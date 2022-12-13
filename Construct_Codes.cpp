void dfs(node* &root, string s, unordered_map<char,string> &m1, unordered_map<string,char> &m2)
{
    if(root->leaf)
    {
        m1[root->ch] = s;
        m2[s] = root->ch;
    }
    else
    {
        for(int i=0; i<tree; i++)
        {
            if(root->next[i]==NULL)
                continue;
            string temp = s;
            temp+=dec_to_bin(i);
            dfs(root->next[i], temp, m1, m2);
        }
    }
}