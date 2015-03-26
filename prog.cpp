#include <iostream>
using namespace std;

#include "NgramTree.h"

int main()
{
    NgramTree ngt;

    /*ngt.addNgram("this");
    ngt.addNgram("samp");
    ngt.addNgram("ampl");
    ngt.addNgram("text");
    ngt.addNgram("mple");
    ngt.addNgram("hise");
    ngt.addNgram("hise");
    ngt.addNgram("samp");
    */

    ngt.generateTree( string("a"), 4);

    int id = 0;
    ngt.print(ngt.getRoot(), id);

    ngt.printNgramFrequencies();

    cout << "\n Total n-gram count: " << ngt.getTotalNgramCount() << endl;

    return 0;
}
