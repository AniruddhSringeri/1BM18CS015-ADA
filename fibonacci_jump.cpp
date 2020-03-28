#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	int first = 0, second = 1, third = 1;
    	if (n == 1) 
		return first;
    	else if (n == 2) 
		return second;
    	else if (n == 3) 
		return third;
    	else 
	{
        	for (int i = 4; i <= n; ++i) 
		{
            		first = second;
            		second = third;
            		third = first + second;
        	}
        return third;
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	cout<<"Enter the array elements"<<endl;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a[n]=1;
	vector<int> fibser;
    	for (int i = 1; i <= n; ++i) 
		fibser.push_back(fib(i));
	vector<int> jumps(n + 1, n);
	for(int i=0;i<=n;i++)
	{
		if(a[i]==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(i-fibser[j]==-1)
					jumps[i]=1;
				else if (i - fibser[j] > -1)
					jumps[i] = min(jumps[i], jumps[i - fibser[j]] + 1);
			}
		}
	}
	cout<<"Mininum jumps : "<<jumps[n]<<endl;
	return 0;
}
