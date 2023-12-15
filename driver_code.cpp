#include<bits/stdc++.h>
using namespace std;
#include "compression.cpp"
int main()
{       cout<<endl;
        cout<<endl;
        cout<<"Welcome to Huffman compression algorithms implementation"<<endl;
        cout<<endl;
        cout<<"Press 1 to continue"<<endl;
        cout<<endl;
        int n;
        cin>>n;
        if(n!=1)
        {
            cout<<"Terminating the program"<<endl;
            return 0;
        }
        unordered_map<char,int> file_info;
        ifstream inputFile("test2.txt");
        if (!inputFile.is_open()) {
            cerr << "Error opening the file." << endl;
            return 1;
        }

        string line;
        while (getline(inputFile, line)) {
            for(int i=0;i<line.length();i++)
            {
                file_info[line[i]]++;
            }
        }
        inputFile.close(); // Close the file when done1

        MakeHuffmanTree(file_info);
  return 0;
}