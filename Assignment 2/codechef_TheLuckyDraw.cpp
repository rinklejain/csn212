#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int FindIndex(vector<int> &v, int l, int r, int key)
{
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}
 
int LIS_length(int v[] ,int s , int n) 
{
    if (n == 0)
        return 0;
 
    vector<int> tail(n, 0);

    int length = 1;
 
    tail[0] = v[s];
    for (int i = 1; i < n; i++) {
        //cout<<length<<endl;
        if (v[(i+s)%n] < tail[0])
            tail[0] = v[(i+s)%n];
        else if (v[(i+s)%n] > tail[length-1])
            tail[length++] = v[(i+s)%n];
        else
            tail[FindIndex(tail, -1, length-1, v[(i+s)%n])] = v[(i+s)%n];
    }
 
    return length;
}
 
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        
    int maximum = 0,n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
    {
    cin>>v[i];
    }
    for(int i=0;i<n;i++)

    {
        //cout <<i<<endl;
        maximum = max(maximum , LIS_length(v,i,n));
    }

    cout<<maximum<<endl;
    }
   return 0;
}