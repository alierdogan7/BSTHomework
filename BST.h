struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

class BST
{
public:
    BST();
    ~BST();
    BstNode* getNewNode(int data);
    void print(BstNode* root, int indent);
    BstNode* getRoot();

    void insert(int data);
    BstNode* insertRecursion(BstNode* node, int data);

    BstNode* search(int data);
    BstNode* searchRecursion(BstNode* node, int data);

    void removeItem(int data);
    void removeRecursion(BstNode* node, int data);

    BstNode* findMax(BstNode* root);
    BstNode* findMin(BstNode* root);

private:
    BstNode* root;
};
