#include<bits/stdc++.h>
using namespace std;
bool isvalid(int board[20][20], int row, int col, int n) 
{
   	for(int i=0;i<col;i++) 
	{
      		if (board[row][i])
         		return false;
	}
   	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1) 
	       		return false;
	}
   	for(int i=row,j=col;i<n && j>=0;i++,j--)
	{
		if(board[i][j]==1)
       			return false;
	}
   	return true;
}
bool solvenqueen(int board[20][20], int col, int n) 
{
	int i,j;
   	if(col>=n)
      		return true;
   	for(i=0;i<n;i++) 
	{ 
      		if(isvalid(board,i,col,n))
		{
         		board[i][col] = 1; 
         		if(solvenqueen(board,col+1,n))
            			return true;
         		board[i][col] = 0;       
		}
   	}
   	return false; 
}
int main() 
{   
	int n;
	cout<<"Enter the value of n:\n";
	cin>>n;
   	int board[20][20];
   	for(int i=0;i<n;i++)
   	{
		for(int j=0;j<n;j++)
   			board[i][j] = 0; 
	}   	
	if(solvenqueen(board,0,n)==false) 
   		cout<<"\nSolution does not exist\n";
      	else
   	{
		cout<<"\nThe places of "<<n<<" queens on the board are\n";
		for(int i=0;i<n;i++) 
		{
	      		for(int j=0;j<n;j++)
	        		cout<<board[i][j]<<" ";
        		cout<<endl;
   		}	
	}	
   	return 0;
}
/*
Output:
1)
Enter the value of n:
4
The places of 4 queens on the board are
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
2)
Enter the value of n:
3
Solution does not exist
*/