#include "readosm.h" //TODO: what is the header file to include for osm lib
#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[]) {
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