# include <bits/stdc++.h>

using namespace std;

//assuming max distance between any two = 1e9
int max_dist = 1e9 + 10;

void bellmanFord(int edge[][3] ,int num_v ,int num_e , int source )
{
	int distance [num_v];
	for(int i = 0;i<num_v;i++)
	{
		distance[i] = max_dist
;
	}
	distance[source] = 0;
	cout <<"sourec"<<distance[source]<<endl;
	for(int i = 0;i<num_v-1;i++)
	{
		for(int j=0;j<num_e;j++)
		{
			int u = edge[j][0];
			int v = edge[j][1];
			int weight = edge[j][2];
			if (distance[u] != max_dist && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
            cout <<distance[u]<<" "<<distance[v]<<" "<<weight<<endl;  
		}
	}

	for(int j = 0;j < num_e; j++)
	{
		int u = edge[j][0];
		int v = edge[j][1];
		int weight = edge[j][2];
		if (distance[u] != max_dist && distance[u] + weight < distance[v])
        {
            cout<<"Graph contains negtive weight cycle";
            return;
    	}	

	}
	for(int i= 0 ;i<num_v;i++)
	{
		cout<<"Distance "<<source<<"->"<<i<<": ";
		if(distance[i] == max_dist
)
			cout<<"Infinity"<<endl;
		else
			cout<<distance[i]<<endl;
	}

}

int main ()
{

	clock_t tStart = clock();
	int v , e;
	cout <<"Enter number of vertices and edges: ";
	cin>>v>>e;
	int edge[e][3];
	cout<<"Enter source , destination, weights of the "<<e<<" edges";
	for(int i=0;i<e;i++)
	{
		cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
	}
	int source = 0;
	bellmanFord(edge,v,e,source);
	printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}

