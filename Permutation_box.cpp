#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

using namespace std;

int main()
{
    int in=0;
    int out=0;
    int input=0;
    int pos=0;
    int result=0;
    string line;
    string numbers,num;
    cin>>in;
    vector<int> tableNum(in);

    for (int i=0;i<in;i++)
    {
        scanf("%d",&tableNum[i]);
        //cout<<tableNum[i]<<endl;
    }
    cin>>out;
   // cout<<"out= "<<out<<"*"<<endl;
     vector<int> binaryOut(out);
         vector<int> binaryNum(out);

    scanf("%X",&input);
   // cin>>input;
  // cout<<"input= "<<input<<endl;

   /* for(int j=0;j<in;j++)
        {
         cout<<tableNum[j]<<endl;
        }*/
        int j=0;
    for(int i=out-1;i>=0;i--)
        {
         binaryNum[i]=(1<<j)&input;
         j++;
        }

 for(int i=0;i<out;i++)
        {
        if(binaryNum[i]>0)
         binaryNum[i]=1;
         else
            binaryNum[i]=0;
        }
    /*for(int i=0;i<out;i++)
        cout<<"i= "<<i<<"   "<<binaryNum[i]<<endl;*/

    for(int i=0;i<tableNum.size();i++)
    {
        for(int j=0;j<out+1;j++){
            if(tableNum[i]==j)
        binaryOut[i]= binaryNum[j-1];
        }
    }
 /*   for(int i=0;i<in;i++)
    {
        cout<<binaryOut[i]<<" ";
    }
       cout<<endl;*/
       int y=0;
       for(int i=in-1;i>=0;i--)
       {
           if(binaryOut[i]==1){
          result=result+pow(2,y);
           }
           y++;
       }
      // cout<<result<<endl;
       printf("%X \n",result);
         cout<<endl;

  /*     int y=0;
    for(int i=0;i<in;i++)
    {
        y=binaryOut[in-1-i]<<i;
        printf("%02x \n",y);
      result=result+(binaryOut[i]<<i);
      cout<<"result= "<<result<<endl;
    }*/
   // printf("%X",result);


    return 0;
}
