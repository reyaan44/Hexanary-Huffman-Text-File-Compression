string dec_to_bin(int n)
{
    string ans = "";
    while(n>0)
    {
        if(n&1)
            ans.push_back('1');
        else
            ans.push_back('0');
        n>>=1;
    }
    while(ans.size()<(log2(tree)))
        ans.push_back('0');
    reverse(ans.begin(), ans.end());
    return ans;
}