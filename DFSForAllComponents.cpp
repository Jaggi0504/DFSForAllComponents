#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited) {
	cout<<sv<<" ";
	visited[sv] = true;
	for(int i=0;i<n;i++) {
		if(edges[sv][i] == 1 && !visited[i]) {
			printDFS(edges, n, i, visited);
		}
	}
}

void DFS(int **edges, int n) {
	bool *visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			printDFS(edges, n, i, visited);
			cout<<endl;
		}
	}
	delete[] visited;
}

int main() {
	int n, e;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++) {
		edges[i] = new int[n];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s;
		cout<<"Enter the first and second vertex: ";
		cin>>f>>s;
		edges[s][f] = 1;
		edges[f][s] = 1;
	}
	DFS(edges, n);
	for(int i=0;i<n;i++) {
		delete[]edges[i];
	}
	delete[]edges;
	return 0;
}
