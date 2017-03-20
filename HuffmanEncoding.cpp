
#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
     char data;
     unsigned freq;
     MinHeapNode *left, *right;
     
     MinHeapNode(char data, unsigned freq){
          left = right = NULL;
          this->data = data;
          this->freq = freq;
     }
};



struct compare{
     bool operator()(MinHeapNode *l, MinHeapNode *r){
          return (l->freq > r->freq);
          }
};

void printCodes(struct MinHeapNode *root, string str, map<char, string> &codeMap){
     if(!root)
         return;
         
     if(root->data != '$'){
          cout << root->data << " : " << str << endl;
          codeMap[root->data] = str;
     }
     printCodes(root->left, str + "0", codeMap);
     printCodes(root->right, str + "1", codeMap);
}

map<char, string> HuffmanCode(char data[], int freq[], int size){
     struct MinHeapNode *left, *right, *top;
     map<char, string> codeMap;
     priority_queue<MinHeapNode *, vector<MinHeapNode*>, compare> minHeap;
     
     for(int i=0;i<size; i++)
          minHeap.push(new MinHeapNode(data[i] , freq[i]));
     
     while(minHeap.size() != 1){
          left = minHeap.top();
          minHeap.pop();
          
          right = minHeap.top();
          minHeap.pop();
          
          top = new MinHeapNode('$', left->freq + right->freq);
          top->left = left;
          top->right = right;
          minHeap.push(top);
     }
     
     printCodes(minHeap.top(), "", codeMap);
     return codeMap;
}


int main(){
     string testStr("this is an example of a huffman tree");
     map<char, int>inputMap;
     char arr[100];
     int freq[100];
     
     for(int i=0;i<testStr.size(); i++)
          inputMap[testStr[i]] += 1;
     
     //arr = (char *) malloc(inputMap.size());
     //freq = (int *) malloc(inputMap.size() * sizeof(int));
     
     int i=0;
     for(map<char, int>::iterator iter = inputMap.begin(); iter != inputMap.end(); iter++){
          cout << iter->first << " is " << iter->second << endl;
          arr[i] = (*iter).first;
          freq[i] = (*iter).second;
          i++;
     }
     
     int size = i;
     map<char, string> codeMap;
     codeMap = HuffmanCode(arr, freq, size);
     string codeStr = "";
     for(int i=0; i<testStr.size(); i++){
          codeStr += codeMap[testStr[i]];
          codeStr += " ";
     }
     
     cout << "The Final Output is " << codeStr << endl;
   
     return 0;
}
