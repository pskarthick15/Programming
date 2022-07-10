vector<int> NGE(vector<int>& arr)
{
    int n=arr.size();
    vector<int>ans(n,-1);
    int i=n-2;
    stack<pair<int,int>>st;
    st.push({arr[n-1],n-1});
    ans[n-1]=0;
    while(i>=0)
    {
        if(arr[i]<st.top().first)
        {
            ans[i]=st.top().second-i;
            st.push({arr[i],i});
        }
        else
        {
            while(!st.empty() && st.top().first<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=0;
                st.push({arr[i],i});
            }
            else
            {
                ans[i]=st.top().second-i;
                st.push({arr[i],i});
            }
        }
        i--;
    }
    return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int>arr;
  int k;
  cin>>k;
  for(int i=0;i<n;i++)
  {
     cin>>k;
     arr.push_back(k);
  }
  vector<int>ans=NGE(arr);
  for(int i=0;i<n;i++)
  {
     cout<<ans[i]<<" ";
  }
}



