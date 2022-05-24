	int fill_weight(int arr[],int n,int i,int w,int sum,vector<vector<int>>&mem)
{
    if((w>0 && i==n) | w<0) //Means not able to take exactly w weight but little more(w<0) or little less (w>0 && i==n)
    {
        return -1;
    }
    else if(w==0)
    {
        return sum;
    }
    else if(arr[i]==-1)
    {
        if(mem[i][w]!=-1)
            return mem[i][w];
        else
            return mem[i][w]=fill_weight(arr,n,i+1,w,sum,mem); // if array val is -1 then we cant take the element 
    }
    else
    {
        if(mem[i][w]!=-1)
            return mem[i][w];
        else
        {
            int take=fill_weight(arr,n,i,w-i,sum+arr[i],mem);
            int nottake=fill_weight(arr,n,i+1,w,sum,mem);
            if(take==-1 && nottake>0)
                return nottake;
            else if(take>0 && nottake==-1)
                return take;
            else
            {
                return mem[i][w]=min(take,nottake);
            }
        }
    }
}