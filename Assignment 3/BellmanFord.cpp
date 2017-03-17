# include <bits/stdc++.h>

using namespace std;

int distance [10010];     //assuming max number of nodes  = 1e5
int INT_MAX = 1e9;

void bellmanFord(edge[] ,int num_v ,int num_e , int source )
{
	for(int i = 0;i<num_v;i++)
	{
		distance[num_v] = INT_MAX;
	}
	for(int i = 0;i<num_v-1;i++)
	{
		for(int j=0;j<num_e;j++)
		{
			int u = edge[j][0];
			int v = edge[j][1];
			int weight = edge[j][2];
			if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
		}
	}

	for(int j = 0;j < num_e; j++)
	{
		int u = edge[j][0];
		int v = edge[j][1];
		int weight = edge[j][2];
		if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
        {
            cout<<"Graph contains negtive weight cycle";
            return;
    	}	

	}
	for(int i= 0 ;i<num_v;i++)
	{
		cout<<"Distance "<<source<<"->"<<i<<": ";
		if(distance[i]==INT_MAX)
			cout<<"Infinity"<<endl;
		else
			cout<<distance[num_v]<<endl;
	}

}

int main ()
{

	int v , e;
	cout <<"Enter number of edges and vertices";
	cin>>v>>e;
	int edge[e][3];
	cout<<"Enter source , destination, weights of the "<<e<<" edges";
	for(int i=0;i<n;i++)
	{
		cin>>edge[i][0]>>edge[i][1]>>edge[1][0];
	}
	int source = 0;
	bellmanFord(edge,v,e,source);

}

