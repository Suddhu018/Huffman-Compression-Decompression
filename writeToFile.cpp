#include<bits/stdc++.h>
using namespace std;
#include "huffmanClassdef.h"
void travelHuffmanTreeForMapping(HuffmanTreeNode* EncodingRootNode,unordered_map<char,string> &mp,string str)
{   if (EncodingRootNode == NULL)return;

    if (EncodingRootNode->left == NULL && EncodingRootNode->right == NULL)
    {
        mp[EncodingRootNode->data] = str;
    }
    travelHuffmanTreeForMapping(EncodingRootNode->left,mp,str+"0");
    travelHuffmanTreeForMapping(EncodingRootNode->right,mp,str+"1");
}
void decodingTheHuffmanCode(HuffmanTreeNode* EncodingRootNode,string &str,int &index)
{
    if(EncodingRootNode==NULL)return;
    if(EncodingRootNode->left==NULL&&EncodingRootNode->right==NULL)
    {
        cout<<EncodingRootNode->data;
        index--;
        return;
        
    }
    if(str[index]=='0')
    {
        index++;
        decodingTheHuffmanCode(EncodingRootNode->left,str,index);
    }
    else if(str[index]=='1')
    {   index++;
        decodingTheHuffmanCode(EncodingRootNode->right,str,index);
    }
}
void writeToFile(HuffmanTreeNode* EncodingRootNode)
{   
    unordered_map<char,string> mp;
    string str="";
    HuffmanTreeNode* temp=EncodingRootNode;
    travelHuffmanTreeForMapping(temp,mp,str);
    unordered_map<char, string>::iterator it;
    cout<<"Printing the huffman encoding"<<endl;
    for(it= mp.begin(); it!= mp.end(); ++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
    string huffmanCodedStringForText="";
     ifstream inputFile("test2.txt");
        if (!inputFile.is_open()) {
            cerr << "Error opening the file." << endl;
            return ;
        }

        string line;
        while (getline(inputFile, line)) {
            for(int i=0;i<line.length();i++)
            {
                huffmanCodedStringForText+=mp[line[i]];
            }
        }
        inputFile.close();
        cout<<"Printing the Coded Compressed File"<<endl;
        for(int i=0;i<huffmanCodedStringForText.length();i++)
        {
            cout<<huffmanCodedStringForText[i];
        }
        cout<<endl;
        cout<<"Printing the Decoded Decompressed File"<<endl;
        int index=0;
        for(;index< huffmanCodedStringForText.length();index++)
        { 
             HuffmanTreeNode* root=EncodingRootNode;
            decodingTheHuffmanCode(root,huffmanCodedStringForText,index);
        }
        return ;
}
