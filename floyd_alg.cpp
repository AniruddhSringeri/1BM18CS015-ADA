#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
void floyd(int a[][20])
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
		}
	}
}

int main()
{
	
	cout<<"Enter the no. of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter the weighted matrix ( enter 99999 for infinity)"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			
		}
	}
	floyd(a);
	cout<<"All Pair Shortest paths :"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
			
		}
		cout<<"\n";
	}
	return 0;
}