#include <iostream>
using namespace std;

#include "NgramTree.h"

int main()
{
    NgramTree ngt;

    ngt.addNgram("this");
    ngt.addNgram("samp");
    ngt.addNgram("ampl");
    ngt.addNgram("text");
    ngt.addNgram("mple");
    ngt.addNgram("hise");
    ngt.addNgram("hise");
    ngt.addNgram("samp");

    int id = 0;
    ngt.print(ngt.getRoot(), id);

    ngt.printNgramFrequencies();

    return 0;
}
