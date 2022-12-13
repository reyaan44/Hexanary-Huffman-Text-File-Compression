// Code by Reyaan Jagnani (reyaan44)

#include<bits/stdc++.h>

#define endl "\n"
#define quick ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timetaken cout<<fixed<<setprecision(10); cout << "TOTAL TIME TAKEN : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl

using namespace std;

#include "Tree_Type.cpp"
#include "Class_Node.cpp"
#include "Input_Frequency.cpp"
#include "Decimal_To_Binary.cpp"
#include "Construct_Codes.cpp"
#include "Compressed_File.cpp"
#include "Decompressed_File.cpp"

int main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input_data.txt", "r", stdin);
    freopen("compressed_data.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    // Data Variables
    unordered_map<char,int> frequency;
    priority_queue<pair<int,node*>, vector<pair<int,node*>>, greater<pair<int,node*>>> min_heap;
    string input_data;
    unordered_map<char,string> code_to_string_mapping;
    unordered_map<string,char> string_to_code_mapping;
    string compressed_data;
    string decompressed_data;
    int input_data_size;
    int compressed_data_size;
    double percentage_compression;
    node* root;

    // Storing Frequencies with characters
    input_data = readAndPrint("input_data.txt", frequency);

    // Preparing Min_Heap Based on Frequency
    for(auto itr: frequency)
    {
        node* temp = new node(itr.first, itr.second);
        min_heap.push({itr.second,temp});
    }
    while(min_heap.size()>0)
    {
        if(min_heap.size()==1)
        {
            root = min_heap.top().second;
            min_heap.pop();
            break;
        }
        vector<node*> node_pack;
        int total_frequecies = 0;
        while(min_heap.size()>0 && node_pack.size()<tree)
        {
            node* n1 = min_heap.top().second;
            int freq1 = min_heap.top().first;
            total_frequecies+=freq1;
            node_pack.push_back(n1);
            min_heap.pop();
        }
        node* temp = new node(total_frequecies, node_pack);
        min_heap.push({total_frequecies,temp});
    }

    // Forming code_to_string_mapping and string_to_code_mapping
    dfs(root, "", code_to_string_mapping, string_to_code_mapping);
    for(auto itr: code_to_string_mapping)
        cout<<itr.first<<" "<<itr.second<<endl;
    cout<<endl;

    // 1 character takes 8 bits
    input_data_size = input_data.size()*8;  
    cout<<"INITIAL SIZE = "<<input_data_size<<" BITS"<<endl<<endl;

    // 1 bit size for each binary bit (0 and 1)
    compressed_data = encrypt(input_data, code_to_string_mapping);
    compressed_data_size = compressed_data.size();
    
    cout<<"FINAL SIZE = "<<compressed_data_size<<" BITS"<<endl<<endl;
    decompressed_data = decrypt(compressed_data, string_to_code_mapping);

    percentage_compression = ((double(input_data_size - compressed_data_size))/input_data_size)*100;
    cout<<"TOTAL COMPRESSION = "<<percentage_compression<<" %"<<endl;

    timetaken;
    return 0;
}