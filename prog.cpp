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

    //cout << "\n Is complete tree? " << ( (ngt.isComplete()) ? "Yes" : "No" ) << endl;

    NgramTree ngt2;
    ngt2.addNgram("f");
    ngt2.addNgram("c");
    ngt2.addNgram("j");
    ngt2.addNgram("a");
    ngt2.addNgram("d");
    ngt2.addNgram("g");
    ngt2.addNgram("k");

    int id2 = 0;
    ngt2.print(ngt2.getRoot(), id2);

    cout << "\n Is second tree complete? " << ( (ngt2.isComplete()) ? "Yes" : "No" ) << endl;


    return 0;
}
