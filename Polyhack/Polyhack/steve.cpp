/*
 * Filename: steve.cpp
 * 
 * 
 * This will be the motherboard
 * 
 * 
 *
 */

#include "readosm.h" //TODO: what is the header file to include for osm lib
#include <iostream>
#include "Graph.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    Graph</*Nodes*/> g();
        
    int ret;
    const void *osm_handle;
    
    //ensure only one command line arg
    if (argc != 2) {
        cerr << "Usage: [command] [file name]" << endl;
        return -1;
    }

    //open up the actual 
    ret = readosm_open(argv[1], &osm_handle);
    if (ret != READOSM_OK) {
        cerr << "Open error: " << ret << endl;
        goto stop;
    }
    ret = readosm_parse(osm_handle, (const void *) 0, 
      /*node mapping function*/, /*way mapping function*/, 
      /*relation mapping function*/);
    if (ret != READOSM_OK) {
        cerr << "Parse error: " << ret << endl;
        goto stop;
    }
    cerr << "OSM input file successfully parsed" << endl;
    
    stop:
    readosm_close(osm_handle);
    return 0;
}

void * addNodeToGraph(const void ∗user_data, const readosm_node ∗node, void *cl)
{
    Graph * graph = cl;
    graph->add_vertex(node->node_ref);    
}

void * addWayToGraph(const void ∗user_data, const readosm_way ∗way, void *cl)
{
    Graph * graph = cl;
    
    for (int i = 0; i < way->node_ref_count; i++)
        for (int j = 0; j < way->node_ref_count; j++)
            if ((node_refs[i] != NULL) && (node_refs[j] != NULL))
            //node refs are not nodes
                graph->add_edge(node_refs[i], node_refs[j]);
        }
    }
}

//We don't really care about relations, but syntacticly need this function
// can we theoretically pass in a nullptr in the parse function where
// it asks for the relation
void * addRelationToGraph(const void ∗user_data, const readosm_relation ∗relation)
{
    (void)user_data;
    (void)relation;
    return NULL;    
}


// reverse dijkstra
void reverseDijkstra(vector< pair<int,int> > graph[], int src, 
         int prev_len, int *max_len, 
         vector <bool> &visited)
{
    
}
