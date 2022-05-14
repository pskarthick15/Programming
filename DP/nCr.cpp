#include <bits/stdc++.h>
using namespace std;

double nCr(double n, double r,vector<double>&m){
        // code here
        if(r==0 || r>n)
            return 0;
        else if(r==1)
        {
            return (double)n;
        }
        else
        {
            if(m[r]!=-1)
                return m[r];
            else
            {
                return m[r]=(double)((double)(n/r)*(double)(nCr(n-1,r-1,m)));
            }
        }
    }
int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    double n,r;
    cin>>n>>r;
    //Now have a chance to optimize this as in process of generation of ncr, many overlapping subproblems are there. So we can do memoization.
    vector<double>m(n+1,-1);
    cout<<nCr(n,r,m);
    return 0;
}
