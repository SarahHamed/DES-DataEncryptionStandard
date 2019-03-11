#include <iostream>
#include<vector>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include<string>
using namespace std;

int main()
{
    int ExpBox[]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
    int StraightBox[]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
    vector<int>IN(32);
    vector<int>outExp(48);
    vector<int>outXOR(48);
    vector<int>outSBOX(8);
    vector<int>BiSBOX(32);
    vector<int>outStraight(32);
    vector<int>BinaryKey(48);
    vector<int>BinaryNum(32);
    string n1,n2;
    long long num=0;
    long long key=0;
    int out=0,level=1,result=0,x=0,y=0;
    int Sbox1[4][16]={{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};
    int Sbox2[4][16]={{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};
    int Sbox3[4][16]={{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};
    int Sbox4[4][16]={{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};
    int Sbox5[4][16]={{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};
    int Sbox6[4][16]={{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}};
    int Sbox7[4][16]={{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}};

    int Sbox8[4][16]={{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};
    int m=0;
    string s;
    cin>>n1;
    cin>>n2;
    int h1=0,h2=0;
    for(int i=0;i<n1.length();i++){
            s=n1[m];
    if(s=="0"){
        BinaryNum[i]=0;
        BinaryNum[i+1]=0;
        BinaryNum[i+2]=0;
        BinaryNum[i+3]=0;
        h1=h1+4;
        n1.erase(m,1);
        s=n1[m+1];
        if(s=="0")
        m++;
        }
            }
        m=0;
    for(int i=0;i<n2.length();i++){
        s=n2[m];
    if(s=="0"){
         BinaryKey[i]=0;
         BinaryKey[i+1]=0;
         BinaryKey[i+2]=0;
         BinaryKey[i+3]=0;
         h2=h2+4;
        n2.erase(m,1);
         s=n2[m+2];
        if(s=="0")
        m++;
        }
        }
    std:: stringstream str1;
    std:: stringstream str2;
    str1<<n1;
    str1>>std::hex>>num;

    str2<<n2;
    str2>>std::hex>>key;
    for(int i=47;i>=h2;i--)
        {
            BinaryKey[i]=key%2;
            key=key/2;
        }

    for(int i=31;i>=h1;i--)
        {
            BinaryNum[i]=num%2;
            num=num/2;
        }
    
    for(int i=0;i<48;i++)
    {
        for(int j=1;j<33;j++){
            if(ExpBox[i]==j){
        outExp[i]= BinaryNum[j-1];
        }
    }
}
    
    for(int i=0;i<48;i++)
    {
        outXOR[i]=outExp[i]^BinaryKey[i];
    }
  
    for(int i=0;i<48;i=i+6)
    {
   x=outXOR[i]*2+outXOR[i+5];
   y=outXOR[i+1]*8+outXOR[i+2]*4+outXOR[i+3]*2+outXOR[i+4];
   switch(level){
    case 1:
        out=Sbox1[x][y];
        level++;
        break;
    case 2:
        out=Sbox2[x][y];
        level++;
        break;
    case 3:
        out=Sbox3[x][y];
        level++;
        break;
    case 4:
        out=Sbox4[x][y];
        level++;
        break;
    case 5:
        out=Sbox5[x][y];
        level++;
        break;
    case 6:
        out=Sbox6[x][y];
        level++;
        break;
    case 7:
        out=Sbox7[x][y];
        level++;
        break;
    case 8:
        out=Sbox8[x][y];
        level++;
        break;
   }
   outSBOX[level-2]=out;
    }

int r=7;
    for(int i=0;i<8;i++)
       {
          result=result+outSBOX[i]*pow(16,r);
          r--;
       }

     for(int i=31;i>=0;i--)
        {
    BiSBOX[i]=result%2;
    result=result/2;
        }
       
    for(int i=0;i<32;i++)
    {
        for(int j=1;j<33;j++){
            if(StraightBox[i]==j)
        outStraight[i]= BiSBOX[j-1];
        }
    }
  
   int n=0;
   result=0;
long long   result2=0;
       for(int i=31;i>=0;i--)
       {
           if(outStraight[i]==1){
          result2=result2+pow(2,n);
           }
           n++;
       }
       printf("%X",result2);
    
    return 0;
}
