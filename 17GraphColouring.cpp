#include<iostream>
#include<algorithm>


bool isSafe(int v, int n, bool a[][], int colour[], int c) 
{ 
   	for(int i = 0; i < n; i++) 
        if(a[v][i] && c == colour[i]) 
        	return false; 
    	return true; 
} 


void printSolution(int colour[], int n) 
{ 
	    std::cout << "\nThe assigned colours are:  ";
	    for (int i = 0; i < n; i++) 
      	    std::cout << colour[i] << " ";
    	    std::cout << "\n"; 
} 


bool graphColour(bool a[][], int n, int m, int colour[], int v) 
{     
	if(v == n) 
        	return true; 
	for (int c = 1; c <= m; c++) 
    	{ 
                if(isSafe(v, a, colour, c)) 
        	{ 
           		colour[v] = c; 
  			    if(graphColour(a,m,colour,v+1)==true) 
                 		return true; 
  			    colour[v] = 0; 
  		    }   
    	} 
  	return false; 
} 


int main()
{
    int n;
    bool a[30][30];
    int m,i,j;
	std::cout << "Enter the number of colours:   "; 
	std::cin >> m;
	std::cout << "Enter the number of vertices:   "; 
	std::cin >> n;
	int colour[n];
	std::cout << "Enter the adjacency matrix:\n";
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
	}
    for(i = 0; i < n; i++) 
    	colour[i] = 0; 
    if(graphColour(a, m, colour, 0) == false) 
    { 
    	std::cout << "\nSolution does not exist\n"; 
    } 
    else
    	printSolution(colour); 
    return 0;
} 
