#include <iostream>
#include<vector>
#include <sstream>
#include<string>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int N=0;
vector<int>E(64);
vector<int>hexaNum(16);
  string key,s,PlainText;
  int x=0,y=0,out=0,level=1;
  long long number=0;
  int first=0,second=0,third=0,fourth=0;
  vector<int>BinaryKey(64);
  vector<int>BinaryPlain(64);
  vector<int>BinaryPlain2(64);
  vector<int>Encrypted(64);
  vector<int>OutPerm1(56);
  vector<int>OutPerm2(48);
  vector<int>outputKey(48);
  vector<int>Right(32);
  vector<int>Left(32);
  vector<int>outSBOX(8);
    vector<int>RightExp(48);
    vector<int>XorOut(48);
    vector<int>BiSBOX(32);
    vector<int>outStraight(32);
  int PC1[]={ 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
  int PC2 []={ 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
  int InitialPerm[] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
  int InverseIP[] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
  int Expansion[] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
  int StraightBox[]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};


int Sbox1[4][16]={{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};
int Sbox2[4][16]={{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};
int Sbox3[4][16]={{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};
int Sbox4[4][16]={{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};
int Sbox5[4][16]={{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};
int Sbox6[4][16]={{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}};
int Sbox7[4][16]={{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}};
int Sbox8[4][16]={{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

  int n=0;
  long long result=0;
  int k=0;
  int RoundKeys[16][48]={0};

void KeyOrPlainInBinary(vector<int>&vect ,string input)
{
     int z=0,y=0;
  z=input.length();
  if(input.length()<16)
  {
      for(int i=0;i<16-z;i++)
      input.insert(0,"0");
  }
   for(int i=0;i<input.length();i++){
  s=input[i];

  if((s=="A")||(s=="B")||(s=="C")||(s=="D")||(s=="E")||(s=="F"))
  {
      if(s=="A"){
     vect[i*4]=1;
     vect[i*4+1]=0;
     vect[i*4+2]=1;
     vect[i*4+3]=0; }
     else if(s=="B")
     {
     vect[i*4]=1;
     vect[i*4+1]=0;
     vect[i*4+2]=1;
     vect[i*4+3]=1;
     }
     else if(s=="C")
     {
     vect[i*4]=1;
     vect[i*4+1]=1;
     vect[i*4+2]=0;
     vect[i*4+3]=0;
     }
     else if(s=="D")
     {
    vect[i*4]=1;
     vect[i*4+1]=1;
     vect[i*4+2]=0;
     vect[i*4+3]=1;
     }
      else if(s=="E")
     {
    vect[i*4]=1;
     vect[i*4+1]=1;
     vect[i*4+2]=1;
     vect[i*4+3]=0;
     }
      else if(s=="F")
     {
    vect[i*4]=1;
     vect[i*4+1]=1;
     vect[i*4+2]=1;
     vect[i*4+3]=1;
     }
  }
  else
    {
        y=atoi(s.c_str());
        for(int x=3;x>=0;x--)
        {
        vect[i*4+x]=y%2;
        y=y/2;
        }
    }

  }
}

  void keyGen1(int indexOfRoundKeys)
    {
    first=OutPerm1[0];
    for(int i=0;i<27;i++)
    {
        OutPerm1[i]=OutPerm1[i+1];
    }
    OutPerm1[27]=first;

    first=OutPerm1[28];
    for(int i=28;i<55;i++)
    {
        OutPerm1[i]=OutPerm1[i+1];
    }
OutPerm1[55]=first;

     for(int i=0;i<48;i++)
    {
        for(int j=1;j<57;j++){
            if(PC2[i]==j){
        OutPerm2[i]= OutPerm1[j-1];
         RoundKeys[indexOfRoundKeys][i]=OutPerm2[i];
        }
    }
    }
}
 void keyGen2(int indexOfRoundKeys)
{
     first=OutPerm1[0];
    second=OutPerm1[1];
    for(int i=0;i<26;i++)
    {
        OutPerm1[i]=OutPerm1[i+2];
    }
    OutPerm1[26]=first;
    OutPerm1[27]=second;

    first=OutPerm1[28];
    second=OutPerm1[29];
    for(int i=28;i<54;i++)
    {
        OutPerm1[i]=OutPerm1[i+2];
    }
    OutPerm1[54]=first;
    OutPerm1[55]=second;

     for(int i=0;i<48;i++)
    {
        for(int j=1;j<57;j++){
            if(PC2[i]==j){
        OutPerm2[i]= OutPerm1[j-1];
        RoundKeys[indexOfRoundKeys][i]=OutPerm2[i];

        }
    }
    }
}
void PermutedChoice()
{
    for(int i=0;i<56;i++)
    {
        for(int j=1;j<65;j++){
            if(PC1[i]==j){
        OutPerm1[i]= BinaryKey[j-1];
        }
    }
    }
}
void InitialPermutation()
{
    for(int i=0;i<64;i++)
    {
        for(int j=1;j<65;j++){
            if(InitialPerm[i]==j){
        BinaryPlain2[i]= BinaryPlain[j-1];
      //  cout<<BinaryPlain2[i];
        }
    }
    }
   //cout<<endl;
}
void InversePermutation()
{
    for(int i=0;i<64;i++)
    {
        for(int j=1;j<65;j++){
            if(InverseIP[i]==j){
        Encrypted[i]= Encrypted[j-1];
        }
    }
    }
}
void KeyGeneration()
{
    keyGen1(0);
    keyGen1(1);
    keyGen2(2);
    keyGen2(3);
    keyGen2(4);
    keyGen2(5);
    keyGen2(6);
    keyGen2(7);
    keyGen1(8);
    keyGen2(9);
    keyGen2(10);
    keyGen2(11);
    keyGen2(12);
    keyGen2(13);
    keyGen2(14);
    keyGen1(15);
}
void SBOX()
{
    for(int i=0;i<48;i=i+6)
{
   x=XorOut[i]*2+XorOut[i+5];
   y=XorOut[i+1]*8+XorOut[i+2]*4+XorOut[i+3]*2+XorOut[i+4];
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
}
void SboxOutputBinary()
{
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
}
int main()
{
    cin>>key;
    cin>>PlainText;
    cin>>N;
    KeyOrPlainInBinary(BinaryKey,key);
/*for(int i=0;i<64;i++)
{
    cout<<BinaryKey[i];
}
cout<<endl;*/
    KeyOrPlainInBinary(BinaryPlain,PlainText);
    if(N==0)
    {
    n=0;
   result=0;
   for(int i=0;i<64;i=i+4)
   {
     hexaNum[n]= 8*BinaryPlain[i]+4*BinaryPlain[i+1]+2*BinaryPlain[i+2]+BinaryPlain[i+3];
    printf("%X",hexaNum[n]);

     n++;
   }
    }
    else{
    for(int b=0;b<N;b++){
        if(b>0)
        {
            for(int i=0;i<64;i++)
            {
            BinaryPlain[i]=E[i];
            }
        }
    PermutedChoice();
    KeyGeneration();
    InitialPermutation();
    for(int k=15;k>=0;k--)
    {
    for(int i=0;i<32;i++)
    {
        Left[i]=BinaryPlain2[i];
        Right[i]=BinaryPlain2[32+i];
    }

    for(int i=0;i<48;i++)
    {
        for(int j=1;j<33;j++){
            if(Expansion[i]==j){
        RightExp[i]= Right[j-1];
        }
    }
    }

    for(int i=0;i<48;i++)
    {
        XorOut[i]=RightExp[i]^RoundKeys[k][i];////////////////////////**/////////////////////
    }
       level=1;
    SBOX();
    SboxOutputBinary();

    for(int i=0;i<32;i++)
    {
        for(int j=1;j<33;j++){
            if(StraightBox[i]==j){
        outStraight[i]= BiSBOX[j-1];

            }
        }
    }

    for(int i=0;i<32;i++)
    {
        BinaryPlain2[32+i]=(outStraight[i])^(Left[i]);
         BinaryPlain2[i]=Right[i];
    }

    }

    for(int i=0;i<32;i++)
    {
        Encrypted[i]=BinaryPlain2[32+i];
        Encrypted[i+32]=BinaryPlain2[i];
    }


     for(int i=0;i<64;i++)
    {
        for(int j=1;j<65;j++){
            if(InverseIP[i]==j){
        E[i]= Encrypted[j-1];
        }
    }
    }
/*for(int i=0;i<64;i++)
    {
        cout<<E[i];
    }
    cout<<endl;*/

   }
    n=0;
   result=0;
   for(int i=0;i<64;i=i+4)
   {
     hexaNum[n]= 8*E[i]+4*E[i+1]+2*E[i+2]+E[i+3];
    printf("%X",hexaNum[n]);

     n++;
    }
    }
      /* for(int i=0;i<64;i++)
       {
           if(E[i]==1)
          result=result+pow(2,n);
           n--;
           cout<<result<<endl;
       }
    for(int i=15;i>=0;i--)
    {
        hexaNum[i]=(result)%16;
        cout<<hexaNum[i]<<endl;
        result=result/16;
    }
    for(int i=0;i<16;i++){
        printf("%X",hexaNum[i]);
    }
    cout<<endl;*/
    return 0;
}
