#include "" //TODO: what is the header file to include for osm lib
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int ret;
    const void *osm_handle;
    if (argc != 2) {
        cerr << "Usage: [command] [file name]" << endl;
        return -1;
    }
    ret = readosm_open(argv[1], &osm_handle);
    if (ret != READOSM_OK) {
        cerr << "Open error: " << ret << endl;
        goto stop;
    }

    stop:

}