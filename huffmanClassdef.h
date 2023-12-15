//Defination of each of the node in Huffman Tree
#ifndef HUFFMAN_CLASSDEF_H
#define HUFFMAN_CLASSDEF_H
class HuffmanTreeNode{
    public:
    char data;
    int frequency;
    HuffmanTreeNode* left;
    HuffmanTreeNode* right; 
    HuffmanTreeNode(char charData,int occurence)
    {
        this->data=charData;
        this->frequency=occurence;
        this->left=NULL;
        this->right=NULL;
    }
};
#endif // HUFFMAN_CLASSDEF_H