#include "MyDijkstra_c766d913.hpp"
// #include "MyDijkstra.h"

void addEdge(NodeType i, NodeType j, WeightType w, GraphType& graph)
{
    if (i >= graph.size()) graph.resize(i+1);
        graph[i].push_back({j,w});
}

void loadGraph(const char* fname, GraphType& g )
{
    std::ifstream fin(fname);
    if (!fin.is_open())	    // fail to open
    {
        std::cout << "Cannot open the test instance file " << fname << ". Abort." << std::endl;
        return;
    }
    else
    {
        while(true)
        {
            NodeType u, v; WeightType w;
            fin >> u; if(fin.eof()) break;
            fin >> v; if(fin.eof()) break;
            fin >> w; if(fin.eof()) break;
            addEdge(u,v,w,g);
        }
    }
    fin.close();
}

// print graph, you don't need to call this when implement the Dijkstra's algorithm
void printGraph(GraphType& g)
{
    for(int i=0; i < g.size(); i++) 
        for(auto edge: g[i]) 
            std::cout << "("<<i<<", "<<edge.first<<") = "<<edge.second << "\n";
}
/*----------------------------------------------------------------------------*/


// Helper functions to print out found shortest path and total length.
void PrintPathANDLength(WeightType & path_len, std::vector<NodeType> & path)
{
    for(auto x : path) std::cout << x << " ";
    std::cout << path_len << "\n";
}

int main(int argc, char* argv[]) {
    GraphType my_graph;
    loadGraph(argv[1], my_graph);
    for(NodeType i=0; i < my_graph.size(); i++)
    {
        for(NodeType j=0; j < my_graph.size(); j++)
        {
            WeightType total_length;
            std::vector<NodeType> path;
            ShortestPath_Dijkstra(my_graph, i, j, total_length, path);
            PrintPathANDLength(total_length, path);
        }
    }
    return 0;
}
