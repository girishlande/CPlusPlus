// ConsoleApplication19.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Edge {
    int src;
    int dest;
};

class Graph
{
    int V;    // No. of vertices
    list<Edge> edges;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool* rs, vector<int>& seq);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
    void RemoveSequenceEdges(vector<int>& seq);
    void FilterSequence(vector<int>& seq, int start);
};

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(int v, int w)
{
    edges.push_back(Edge{ v,w });
}

bool Graph::isCyclicUtil(int v, bool visited[], bool* recStack, vector<int>& seq)
{
    if (visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        seq.push_back(v);

        // Recur for all the vertices adjacent to this vertex
        for(auto e: edges)
        {
            if (e.src != v) continue;
            if (!visited[e.dest] && isCyclicUtil(e.dest, visited, recStack, seq)) {
                //cout << "found visited:" << e.dest <<endl;
                return true;
            }
            else if (recStack[e.dest]) {
                FilterSequence(seq, e.dest);
                //cout << "found in stack:" << e.dest <<endl;
                return true;
            }
        }
        seq.pop_back();

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    
    return false;
}

bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool* visited = new bool[V];
    bool* recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    bool flag = false;
    vector<int> seq;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i, visited, recStack,seq)) {
            for (auto a : seq) {
                cout << a << "->";
            }
            cout << seq.front();
            RemoveSequenceEdges(seq);

            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
                recStack[i] = false;
            }
            
            seq.clear();
            cout << "\n";
            flag = true;
        }
    }

    return flag;
}

void Graph::RemoveSequenceEdges(vector<int>& seq) {
    seq.push_back(seq.front());
    for (int i = 0; i < seq.size() - 1; i++) {
        int s = seq[i];
        int d = seq[i + 1];
        // find edge (s,d) and remove it from graph list
        std::list<Edge>::iterator it = edges.begin();
        while (it != edges.end())
        {
            bool isActive = (*it).src == s && (*it).dest == d;
            if (isActive)
            {
                cout << "\nremoving edge:" << (*it).src << "->" << (*it).dest;
                it = edges.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

void Graph::FilterSequence(vector<int>& seq, int start) {
    vector<int> newseq;
    bool startCopying = false;
    for (int i = 0; i < seq.size(); i++) {
        int s = seq[i];
        if (s == start) {
            startCopying = true;
        }
        if (startCopying) {
            newseq.push_back(s);
        }
    }
    seq = newseq;
}

int main()
{
    // Create a graph given in the above diagram
    /*Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/

    /*Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 5);*/

    /*Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.addEdge(3, 0);*/

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 1);
    g.addEdge(5, 6);
    g.addEdge(6, 2);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
}
