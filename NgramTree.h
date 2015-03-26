#include <string.h>

struct NgramNode
{
    string data;
    int count;
    NgramNode *left;
    NgramNode *right;

    NgramNode()
    {
        count = 0;
    }
};

class NgramTree
{
public:
    NgramTree();
    ~NgramTree();

    void addNgram(string ngram);

    int getTotalNgramCount();
    void traverseNgramCounts(NgramNode *node, int& count);

    void printNgramFrequencies();
    void traverseFrequencies(NgramNode *node);

    bool isComplete();

    void generateTree(string fileName, int n);
    static int compareStr(string str1, string str2);

    NgramNode* getNewNode(string data);
    void print(NgramNode* root, int indent);
    NgramNode* getRoot();

    void insert(string data);
    NgramNode* insertRecursion(NgramNode* node, string data);

    NgramNode* search(string data);
    NgramNode* searchRecursion(NgramNode* node, string data);

    void removeIterative(string data);
    NgramNode* removeRecursion(NgramNode* node, string data);

    NgramNode* findMax(NgramNode* root);
    NgramNode* findMin(NgramNode* root);

private:
    NgramNode *root;
};
