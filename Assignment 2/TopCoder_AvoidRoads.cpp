#include <iostream>

using namespace std;

long long dp[101][101]={0};
int width, height;
int N,x1,y1,x2,y2;

int main(){
	cin>>width>>height;	
	cin>>N;   
	
	for(int i=0;i<N;i++){
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			if(y1>y2) dp[x1][y1]=-1;
			else dp[x2][y2]=-1;
		}
		else{
			if(x1>x2) dp[x1][y1]=-2;
			else dp[x2][y2]=-2;
		}
	}

	  for(int i=0;i<=width;i++){
		for(int j=0;j<=height;j++){
			if(i==0 && j==0) dp[i][j]=1;
			else{

				if(dp[i][j]==0){
					if(j!=0) dp[i][j]+=dp[i][j-1];
					if(i!=0) dp[i][j]+=dp[i-1][j];
				
				}
				else if(dp[i][j]==-1){

					if(i==0) dp[i][j]=0;
					else dp[i][j]=dp[i-1][j];
				}
				else if(dp[i][j]==-2){

					if(j==0) dp[i][j]=0;
					else dp[i][j]=dp[i][j-1];
				}
			}
		}
	}

	cout<<dp[width][height]<<endl;

	return 0;
}
