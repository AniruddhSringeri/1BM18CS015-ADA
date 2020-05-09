#include<bits/stdc++.h>
int partition(int low, int high, int a[]);
void quicksort(int low, int high, int a[]);
using namespace std;
int main()
{
	int n,i,low,high;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	{
		a[i] = rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	low = 0;
	high = n-1;
	time = clock();
	quicksort(low,high,a);
	time = clock()-time;
	cout<<"\nThe time required for quick sort is "<<fixed<<setprecision(7)<<(float)time/CLOCKS_PER_SEC<<"\n";
	cout<<"\nThe sorted array is\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
void quicksort(int low, int high, int a[])
{
	int j;
	if(low<high)
	{
		j = partition(low,high,a);
		quicksort(low,j-1,a);
		quicksort(j+1,high,a);
	}
}
int partition(int low, int high, int a[])
{
	int i,j,pivot;
	i = low;
	j = high+1;
	pivot = a[low];
	while(i<j)
	{
		do
		{	
			i+=1;
		}
		while(a[i]<=pivot);
		do
		{
			j-=1;
		}	
		while(a[j]>pivot);
		if(i<j)
			swap(a[i],a[j]);
	}
	swap(a[low],a[j]);
	return j;
}
