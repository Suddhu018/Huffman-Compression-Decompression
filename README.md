# Huffman-Compression-Decompression
Huffman compression algorithm.This can be used to compress the text files and can also be implemented on images by making small changes in the code. Basic idea is the char with max frequency should be represented with lowest number of bits possible from Huffman tree.
Due to this overall size of the file decreases.

This compression algorithm 100% lossless compression.



.Language Used- C++

.Difficulty - Medium

.Data Structures Used - Binary Tree, Priority Queue(min heap), Vectors, Unordered map, Strings

.Algo/Concepts Used: Standard Huffman algorithm, Recursion(for tree traversal while compressing and decompressing), Basic reading and writing of file, DFS traversal of binary tree.



Refrences Used

1)https://home.cse.ust.hk/faculty/golin/COMP271Sp03/Notes/MyL17.pdf

2)https://youtu.be/uDS8AkTAcIU?si=eh1hp0Zt_5rZXP1q

3)https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/Huffman.html

                               

                                             Huffman Algorithm



1. In this step your goal is to build your tool to accept a filename as input. It should return an error if the file is not valid, otherwise your program should open it, read the text and determine the frequency of each character occurring within the text.
   
2. In this step your goal is to use the frequencies that you calculated in step 1 and use them to create the node of the binary tree and push them into the priority queue so that the min element by frequency should be at the top.

//This node can act as Huffman Tree Node

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

3. To build the binary tree take 2 nodes (say leftChild and Right Child )out from the priority queue then add their frequency and make another new node with data ='%'(some char which is sure to be not present in the input text) and frequency equal to the sum of the frequency of 2 element which were taken out. Now  newNode->left=leftChild and newNode->right=rightChild.

4. Again push this newly made node into the priority queue and repeat the step again and again until one node is left in the priority queue. This one node which is left is the root node of the Huffman tree.

5.Now travel the Huffman binary tree and prepare the code table using unordered map which contains min number of bits require to represent a particular char (standard is 8 bits but in Huffman compression its less than 8)and its unique representation in bits.

7. Now use this code table to encode the given text file. By encoding it the size of the text file in significantly reduced as number of bits require by each character is reduced.

8. Similarly we can use this code table to again decode (decompress)the file.

   Refrences:
   1)https://home.cse.ust.hk/faculty/golin/COMP271Sp03/Notes/MyL17.pdf
   2)https://youtu.be/uDS8AkTAcIU?si=eh1hp0Zt_5rZXP1q
   3)https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/Huffman.html
