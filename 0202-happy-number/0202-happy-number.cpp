class Solution {
public:

int getnext(int x)
{
    int sum=0;
    while(x!=0)
    {
        int k=x%10;
        sum+=(k*k);
        x/=10;
    }
    return sum;
}
    bool isHappy(int n) {

        int s=n;
        int f=getnext(n);
        while(f!=1 && s!=f)
        {
            s=getnext(s);
            f=getnext(getnext(f));
        }
        return f==1;
        
    }
};