#include<bits/stdc++.h>
using namespace std;
int minimum(vector<int> visited,vector<int> dist, int n)
{
	int min = 10000,min_index,i;
	for(i=0;i<n;i++)
	{
		if(!visited[i] && dist[i]<min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}
void dijkstra(int n,int src,vector<vector<int> > a)
{
	vector<int> dist(n);
	vector<int> visited(n);
	int i,j,v,u;
	for(i=0;i<n;i++)
	{
		dist[i]=10000;
		visited[i]=0;
	}
	dist[src] = 0;
	for(i=0;i<n-1;i++)
	{
		u = minimum(visited,dist,n);
		visited[u] = 1;
		for(v=0;v<n;v++)
		{
			if(!visited[v] && a[u][v]!=10000 && dist[u]!=10000 && (dist[u]+a[u][v])<dist[v])
				dist[v]=dist[u]+a[u][v];
		}
	}
	cout<<"\nThe shortest paths to all other vertices from "<<src<<" are\n";
	cout<<"Vertices\tDistance from source\n";
	i=0;
	while(i<n)
	{
		if(i==src)
		{
			i++;
			continue;
		}
		cout<<i<<"\t\t"<<dist[i]<<endl;
		i++;
	}
}
int main()
{
	int n,source;
	cout<<"Enter the number of nodes in the graph"<<endl;
	cin>>n;
	vector<vector<int> > a(n);
	cout<<"Enter the adjacency matrix(10000 for infinity)\n";
	for(int i=0;i<n;i++)
	{	a[i].resize(n);
		for(int j=0;j<n;j++) 
		{	cin>>a[i][j];
		}
	}
	cout<<"Enter source vertex\n";
	cin>>source;
	dijkstra(n,source,a);
	return 0;
}
