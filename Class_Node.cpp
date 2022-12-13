class node
{
public:
    node* next[tree];
    int freq;
    char ch;
    bool leaf;
    node()
    {
        for(int i=0; i<tree; i++)
            next[i] = NULL;
        freq = 0;
        leaf = 1;
    }
    node(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        for(int i=0; i<tree; i++)
            next[i] = NULL;
        leaf = 1;
    }
    node(int freq, vector<node*> &vect)
    {
        this->freq = freq;
        for(int i=0; i<vect.size(); i++)
            next[i] = vect[i];
        leaf = 0;
    }
};
