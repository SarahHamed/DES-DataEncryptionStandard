#include <iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

using namespace std;

int main()
{
    int in=0;
    cin>>in;
    vector<int> tableNum(in);
    vector<int> binaryOut(in);
    int flag=0;
    int chosen=0;
    int pos=0;

    for (int i=0;i<in;i++)
    {
        scanf("%d",&tableNum[i]);
    }

    for(int i=0;i<in;i++)
    {
        for(int j=0;j<in;j++)
        {
            if(tableNum[i]==tableNum[j]&&(i!=j))
                flag=1;
        }
    }
    if (flag==1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
        {
        for(int i=0;i<in;i++)
        {if(i>0)
            cout<<" ";
            chosen=in+1;
            pos=i;
                for(int j=0;j<in;j++)
                {
                 if(tableNum[j]<chosen&&(tableNum[j]!=0))
                 {
                     chosen=tableNum[j];
                     pos=j;
                 }
                }
                cout<<pos+1;
                tableNum[pos]=0;
            }
            cout<<endl;
        }
    return 0;
}
