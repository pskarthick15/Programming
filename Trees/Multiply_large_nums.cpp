// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//For doing repetitive integer addition
void add(string &s1,string &s2)
{
    if(s1.size()==0)
    {
        s1=s2;
        return;
    }
    else
    {
        int n=s1.size(),m=s2.size();
        int i=n-1,j=m-1;
        int sum=0,carry=0;
        while(i>=0 && j>=0)
        {
            int a=s1[i]-'0';
            int b=s2[j]-'0';
            sum=a+b+carry;
            if(sum>9)
            {
                carry=sum/10;
                sum=sum%10;
            }
            else
                carry=0;
            s1[i]=sum+48;
            i--;
            j--;
        }
        sum=0;
        while(j>=0)
        {
            int b=s2[j]-'0';
            if(carry>0)
            {
                sum=b+carry;
                if(sum>9)
                {
                    carry=sum/10;
                    sum=sum%10;
                }
                else
                    carry=0;
            }
            else
                sum=b;
            s1.insert(0,to_string(sum));
            j--;
        }
        if(carry>0)
            s1.insert(0,to_string(carry));
    }
}

string multiply(string nums1,string nums2)
{
    int z=0;//For no of trailing zeros to be added while multiplying
    string ans="";
    int n=nums1.size(),m=nums2.size();
    for(int i=n-1;i>=0;i--)
    {
        int k=z;
        string str="";
        int sum=0,carry=0;
        for(int j=m-1;j>=0;j--)
        {
            while(k>0)
            {
                str+='0';
                k--;
            }
            int a=nums1[i]-'0';
            int b=nums2[j]-'0';
            sum=(a*b)+carry;
            if(sum>9)
            {
                carry=sum/10;
                sum=sum%10;
            }
            else
                carry=0;
            str.insert(0,to_string(sum));
        }
        if(carry>0)
            str.insert(0,to_string(carry));
        //cout<<str<<" ";
        add(ans,str);
        //cout<<ans<<endl;
        str="";
        z++;
    }
    return ans;
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
   string s1="65539";
   string s2="83314";
   string t;
   if(s1.size()>=s2.size())
   {
       t=s1;
       s1=s2;
       s2=t;
   }
   string ans=multiply(s1,s2);
   cout<<ans;
    return 0;
}
