#include <iostream>
#include <cstdlib>

struct Node{
    int id;
    int weight;
};



class AdjacencyMatrix
{
    private:
        int n;
        int **adj;
        bool *visited;
    public:
        //
        AdjacencyMatrix(int n)
        {
            this->n = n;
            visited = new bool [n];
            std::cout<< *visited;
            adj = new int* [n];
            for (int i = 0; i < 8258175; i++)
            {
                std::cout<< i << std::endl;
                /*adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }*/
            }
        }
        /*
         * Adding Edge to Graph
         */ 
        void add_edge(Node origin, Node destin)
        {
            if( origin.weight > n || destin.weight > n || origin.weight < 0 || destin.weight < 0)
            {   
                std::cout<<"Invalid edge!\n";
            }
            else
            {   
                int w = origin.weight + destin.weight;
                adj[origin.weight][destin.weight] = w ;
                adj[destin.weight][origin.weight] = w;
            }
        }
        /*
         * Print the graph
         */ 
        int** display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                {
                    //std::cout<<adj[i][j]<<"  "; 
                }
                //std::cout<< std::endl;
            }
            return adj;
        }
};

float calculateDissimilarity()
{
    
}

int main()
{
    int nodes, max_edges, ids=1;
    Node origin, destin;
    std::cout<<"Enter number of nodes: ";
    std::cin>>nodes;
    AdjacencyMatrix am(nodes);
    max_edges = nodes;
    for (int i = 0; i < max_edges; i++)
    {
        origin.id = ids;
        origin.weight = i;
        //std::cout<< "i " << i << " ids " << ids <<std::endl;
        ids++;
        for (int j = 1; j < max_edges; j++)
        {
            destin.id = ids;
            destin.weight = j;
            //std::cout<< "j " << j << " ids " << ids <<std::endl;
            ids++;
            if(i != j && i<j)
            {
                am.add_edge(origin, destin);
                //std::cout<< i<<"->" <<j << "[Label=" << i+j << "];" <<std::endl;
                //std::cout<< j<<"->" << i << "[Label=" << i+j << "];" <<std::endl;
            }
            
            //std::cout<< std::endl;
        }
    }
    am.display();
    return 0;
}