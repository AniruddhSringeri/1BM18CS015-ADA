#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;

void merge(int a[],int l, int m, int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
		left[i]=a[l+i];
	for(int j=0;j<n2;j++)
		right[j]=a[m+1+j];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=right[j];
		j++;
		k++;
	}
	
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		a[i]=rand()%n;
	auto start=high_resolution_clock::now();
	mergesort(a,0,n-1);
	auto stop=high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
	cout<<"Sorted array is"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	cout<<"Time taken : "<<duration.count()<<" microseconds"<<endl;
	return 0;
}
