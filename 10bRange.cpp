#include <bits/stdc++.h> 

using namespace std; 

int ptr[501]; 

void smallest_range(int arr[][100], int n, int k) 
{ 
    	int minval,maxval,minrange,minel,maxel,flag,minind; 
  	for(int i=0;i<=k;i++) 
        		ptr[i] = 0; 
  	minrange = INT_MAX; 
  	while(1) 
	{ 
	        	minind = -1; 
	        	minval = INT_MAX; 
	        	maxval = INT_MIN; 
	        	flag = 0;  
	        	for (int i=0;i<k;i++)
		{     
        			if(ptr[i]==n) 
			{ 
                				flag = 1; 
                				break; 
            			} 
        	        		if(ptr[i]<n && arr[i][ptr[i]]<minval) 
			{ 
		                		minind = i;  
		                		minval = arr[i][ptr[i]]; 
			}         
            			if(ptr[i]<n && arr[i][ptr[i]]>maxval)
			{ 
                				maxval = arr[i][ptr[i]]; 
            			} 
        		}       
        		if (flag) 
            			break;   
        		ptr[minind]++;      
        		if ((maxval-minval)<minrange) 
		{ 
			minel = minval; 
            			maxel = maxval; 
            			minrange = maxel - minel; 
        		} 
    	} 
	cout<<"\nThe smallest range is ["<<minel<<","<<maxel<<"]\n"; 
} 


int main() 
{ 
	int k,n,arr[100][100];
	cout<<"Enter number of arrays(k):\n";
	cin>>k;
	cout<<"Enter the size of each array\n";
	cin>>n;
	cout<<"Enter elements of "<<k<<" arrays\n";
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	smallest_range(arr,n,k); 
  	return 0; 
} 
