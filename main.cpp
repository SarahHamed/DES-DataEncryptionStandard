#include <iostream>
#include<vector>
#include <sstream>
#include<string>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

vector<int>hexaNum(12);
  string input,s;
  long long number=0;
  int first=0,second=0,third=0,fourth=0;
  vector<int>BinaryKey(64);
  vector<int>OutPerm1(56);
  vector<int>OutPerm2(48);
  vector<int>outputKey(48);
  int PC1[]={ 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
  int PC2 []={ 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
int n=0;
   long long result=0;
  int k=0;
  void keyGen2()
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

   /* cout<<"PERM2= ";
for(int i=0;i<56;i++)
{
    cout<<OutPerm1[i];
}
cout<<endl;*/
     for(int i=0;i<48;i++)
    {
        for(int j=1;j<57;j++){
            if(PC2[i]==j){
        OutPerm2[i]= OutPerm1[j-1];
        }
    }
    }

   result=0;
   n=0;
       for(int i=47;i>=0;i--)
       {
           if(OutPerm2[i]==1){
          result=result+pow(2,n);
           }
           n++;
       }
    for(int i=11;i>=0;i--)
    {
        hexaNum[i]=(result)%16;
        result=result/16;
    }
    for(int i=0;i<12;i++){
        printf("%X",hexaNum[i]);
    }
}

void keyGen1()
{
   /* cout<<"PERM2= ";
for(int i=0;i<56;i++)
{
    cout<<OutPerm1[i];
}
cout<<endl;*/
    first=OutPerm1[0];
    for(int i=0;i<27;i++)
    {
        OutPerm1[i]=OutPerm1[i+1];
    }
    OutPerm1[27]=first;
  //  cout<<"OutPerm1[28]= "<<OutPerm1[28]<<endl;

    first=OutPerm1[28];
  //  cout<<"first= "<<first<<endl;
    for(int i=28;i<55;i++)
    {
        OutPerm1[i]=OutPerm1[i+1];
    }
OutPerm1[55]=first;
/*
cout<<"PERM1= ";
for(int i=0;i<56;i++)
{
    cout<<OutPerm1[i];
}
cout<<endl;*/

     for(int i=0;i<48;i++)
    {
        for(int j=1;j<57;j++){
            if(PC2[i]==j){
        OutPerm2[i]= OutPerm1[j-1];
       // cout<<OutPerm2[i];
        }
    }
    }

   //cout<<result<<endl;
   n=0;
   result=0;
       for(int i=47;i>=0;i--)
       {
           if(OutPerm2[i]==1){
          result=result+pow(2,n);
          //cout<<result<<endl;
           }
           n++;
       }
      // cout<<"result= "<<result<<endl;
    for(int i=11;i>=0;i--)
    {
        hexaNum[i]=(result)%16;
       // cout<<hexaNum[i]<<endl;
        result=result/16;
    }
    for(int i=0;i<12;i++){
        printf("%X",hexaNum[i]);
    }

}

int main()
{
    int z=0,y=0;;
  cin>>input;
  z=input.length();
  if(input.length()<16)
  {
      for(int i=0;i<16-z;i++)
      input.insert(0,"0");
  }
  //cout<<input<<endl;
   for(int i=0;i<input.length();i++){
  s=input[i];

  if((s=="A")||(s=="B")||(s=="C")||(s=="D")||(s=="E")||(s=="F"))
  {
      if(s=="A"){
     BinaryKey[i*4]=1;
     BinaryKey[i*4+1]=0;
     BinaryKey[i*4+2]=1;
     BinaryKey[i*4+3]=0; }
     else if(s=="B")
     {
    BinaryKey[i*4]=1;
     BinaryKey[i*4+1]=0;
     BinaryKey[i*4+2]=1;
     BinaryKey[i*4+3]=1;
     }
     else if(s=="C")
     {
     BinaryKey[i*4]=1;
     BinaryKey[i*4+1]=1;
     BinaryKey[i*4+2]=0;
     BinaryKey[i*4+3]=0;
     }
     else if(s=="D")
     {
    BinaryKey[i*4]=1;
     BinaryKey[i*4+1]=1;
     BinaryKey[i*4+2]=0;
     BinaryKey[i*4+3]=1;
     }
      else if(s=="E")
     {
    BinaryKey[i*4]=1;
     BinaryKey[i*4+1]=1;
     BinaryKey[i*4+2]=1;
     BinaryKey[i*4+3]=0;
     }
      else if(s=="F")
     {
    BinaryKey[i*4]=1;
     BinaryKey[i*4+1]=1;
     BinaryKey[i*4+2]=1;
     BinaryKey[i*4+3]=1;
     }
  }
  else
    {
        y=atoi(s.c_str());
        for(int x=3;x>=0;x--)
        {
        BinaryKey[i*4+x]=y%2;
        y=y/2;
        }
    }

  }
 for(int i=0;i<56;i++)
    {
        for(int j=1;j<65;j++){
            if(PC1[i]==j){
        OutPerm1[i]= BinaryKey[j-1];
       // cout<<OutPerm1[i];
        }
    }
    }
   keyGen1();
cout<<endl;
  keyGen1();
    cout<<endl;
     keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;

    keyGen1();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen2();
     cout<<endl;
    keyGen2();
    cout<<endl;
    keyGen1();
    return 0;
}

