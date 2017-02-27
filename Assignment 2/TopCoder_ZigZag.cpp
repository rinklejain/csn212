# include <iostream>
# include <math.h>

using namespace std;

int main()
{
    int n;
    cin>>n;                    //input no of elements in given sequence
    int a[n];
    int po[n],ne[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    po[0] = 1;
    ne[0] = 1;
    int res = 1;
    for(int i = 1;i<n;i++)
    {
        po[i] = 1;
        ne[i] = 1;
        for(int j = 0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                po[i] = max(po[i],ne[j]+1);
            }
            if(a[i]<a[j])
            {
                ne[i] = max(ne[i],po[j]+1);
            }
        }
        if(po[i]>ne[i])
        res = max(res ,po [i]);
        else
        res = max(res , ne[i]);

    }
    cout<<res<<endl;
}