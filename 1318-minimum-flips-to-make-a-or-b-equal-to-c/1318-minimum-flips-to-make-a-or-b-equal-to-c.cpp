class Solution {
public:
    void decToBinary(int n,int binaryNum[])
    {
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
}
    int minFlips(int a, int b, int c)
     {
        int x[32]={0};
        int y[32]={0};
        int z[32]={0};
        decToBinary(a,x);
        decToBinary(b,y);
        decToBinary(c,z);
        int i,j,k,s=0,m=0;
        for(i=0;i<32;i++)
        {
            int a_or_b=x[i]|y[i];
            if(a_or_b !=z[i])
            {
                if(a_or_b==1 and z[i]==0)
                {
                    if(x[i]==1 and y[i]==1)
                    s+=2;
                    else
                    s++;
                }
                else
                {
                    s++;
                }
            }
        }
        return s;
    }
};