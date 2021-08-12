// A C++ program to order of characters in an alien language 
#include<bits/stdc++.h> 
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
	int V; // No. of vertices' 

	// Pointer to an array containing adjacency listsList 
	list<int> *adj; 

	// A function used by topologicalSort 
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints a Topological Sort of the complete graph 
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

// Topological Sort. 
void Graph::topologicalSort() 
{ 
	// Create a vector to store 
	// indegrees of all 
	// vertices. Initialize all 
	// indegrees as 0. 
	vector<int> in_degree(V, 0); 

	// Traverse adjacency lists 
	// to fill indegrees of 
	// vertices. This step 
	// takes O(V+E) time 
	for (int u = 0; u < V; u++) { 
		list<int>::iterator itr; 
		for (itr = adj[u].begin(); 
			itr != adj[u].end(); itr++) 
			in_degree[*itr]++; 
	} 

	// Create an queue and enqueue 
	// all vertices with indegree 0 
	queue<int> q; 
	for (int i = 0; i < V; i++) 
		if (in_degree[i] == 0) 
			q.push(i); 

	// Initialize count of visited vertices 
	int cnt = 0; 

	// Create a vector to store 
	// result (A topological 
	// ordering of the vertices) 
	vector<int> top_order; 

	// One by one dequeue vertices 
	// from queue and enqueue 
	// adjacents if indegree of 
	// adjacent becomes 0 
	while (!q.empty()) { 
		// Extract front of queue 
		// (or perform dequeue) 
		// and add it to topological order 
		int u = q.front(); 
		q.pop(); 
		top_order.push_back(u); 

		// Iterate through all its 
		// neighbouring nodes 
		// of dequeued node u and 
		// decrease their in-degree 
		// by 1 
		list<int>::iterator itr; 
		for (itr = adj[u].begin(); 
			itr != adj[u].end(); itr++) 

			// If in-degree becomes zero, 
			// add it to queue 
			if (--in_degree[*itr] == 0) 
				q.push(*itr); 

		cnt++; 
	} 

	// Check if there was a cycle 
	if (cnt != V) { 
		cout << "There exists a cycle in the graph\n"; 
		return; 
	} 

	// Print topological order 
	for (int i = 0; i < top_order.size(); i++) 
		cout << top_order[i] << " "; 
	cout << endl; 
} 

 

int min(int x, int y) 
{ 
	return (x < y)? x : y; 
} 

// This function fidns and prints order of characer from a sorted 
// array of words. n is size of words[]. alpha is set of possible 
// alphabets. 
// For simplicity, this function is written in a way that only 
// first 'alpha' characters can be there in words array. For 
// example if alpha is 7, then words[] should have only 'a', 'b', 
// 'c' 'd', 'e', 'f', 'g' 
void printOrder(string words[], int n, int alpha) 
{ 
	// Create a graph with 'aplha' edges 
	Graph g(alpha); 

	// Process all adjacent pairs of words and create a graph 
	for (int i = 0; i < n-1; i++) 
	{ 
		// Take the current two words and find the first mismatching 
		// character 
		string word1 = words[i], word2 = words[i+1]; 
		for (int j = 0; j < min(word1.length(), word2.length()); j++) 
		{ 
			// If we find a mismatching character, then add an edge 
			// from character of word1 to that of word2 
			if (word1[j] != word2[j]) 
			{ 
				g.addEdge(word1[j]-'a', word2[j]-'a'); 
				break; 
			} 
		} 
	} 

	// Print topological sort of the above created graph 
	g.topologicalSort(); 
} 

// Driver program to test above functions 
int main() 
{ 
	string words[] = {"caa", "aaa", "aab"}; 
	printOrder(words, 3, 3); 
	return 0; 
} 
