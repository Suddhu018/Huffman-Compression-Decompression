#include<bits/stdc++.h>
using namespace std;
#include "writeToFile.cpp"
#include "huffmanClassdef.h"
//this class tell how do the data should be stored in priority queue
class Compare {
public:
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b)
    {
        return a->frequency > b->frequency;
    }
};
HuffmanTreeNode* FindEncodingRootNode(priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> HuffmanTree)
{
    while(HuffmanTree.size()!=1)
    {
        HuffmanTreeNode* leftChild=HuffmanTree.top();
        HuffmanTree.pop();
        HuffmanTreeNode* rightChild=HuffmanTree.top();
        HuffmanTree.pop();
        HuffmanTreeNode* newNode= new HuffmanTreeNode('~',leftChild->frequency+rightChild->frequency);
        newNode->left=leftChild;
        newNode->right=rightChild;
        HuffmanTree.push(newNode);
    }
    return HuffmanTree.top();
}
void MakeHuffmanTree(unordered_map<char,int> &file_info)
{   priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> HuffmanTree;
    unordered_map<char, int>::iterator it;
    for(it = file_info.begin(); it != file_info.end(); ++it)
    {
        HuffmanTreeNode* newNode = new HuffmanTreeNode(it->first,it->second);
        HuffmanTree.push(newNode);
    }

    HuffmanTreeNode* EncodingRootNode=FindEncodingRootNode(HuffmanTree);
    writeToFile(EncodingRootNode);
}