#include<iostream>
#include<vector>
#include<queue>
#include <list>

using namespace std;

void edge(vector<int>adj[], int u, int v) {
	adj[u].push_back(v);
}

void bfs(int s, vector<int>adj[], bool visit[]) {
	queue<int>q;//queue in STL
	q.push(s);
	visit[s] = true;
	while (!q.empty()) {
		int u = q.front();
		cout << u << " ";
		q.pop();

		for (int i = 0; i < adj[u].size(); i++) {
			if (!visit[adj[u][i]]) {
				q.push(adj[u][i]);
				visit[adj[u][i]] = true;
			}
		}
	}
}

class Graph
{
	int V; 	
	vector<list<int>> adj;
public:
	Graph(int V); 
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V, false);

	list<int> queue; // Create a queue for BFS

	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjecent : adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
			
		}
	}
}





int main() {
	vector<int>adj[5];
	bool visit[5];
	for (int i = 0; i < 5; i++) {
		visit[i] = false;
	}

	edge(adj, 0, 1);
	edge(adj, 1, 0);
	edge(adj, 1, 2);
	edge(adj, 2, 1);
	edge(adj, 3, 4);
	edge(adj, 4, 3);

	cout << "BFS traversal Conneceted Nodes are: " << "  ";
	bfs(0, adj, visit);
	cout << endl;
	return 0;
}