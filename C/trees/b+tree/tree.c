typedef struct
{
    int *val; // array of values 
    TreeNode *next; //array of pointed nodes
    int size[2]; // pos 0 is val size and pos 1 is next size
} TreeNode;

TreeNode *treenode(int val, TreeNode *next)
{
    TreeNode *node = malloc(sizeof(TreeNode));

    node->val = malloc(sizeof(int));
    node->next = malloc(sizeof(TreeNode));

    node->val = val;
    node->next = (void *)0; //propia definicion de NULL

    node->size[0] = 1;
    node->size[1] = 1;

    return node;
}

void insertVal(int val, TreeNode *node)
{
    node->val = (int *) realloc(node->val, sizeof(int) * (node->size[0] + 1));
    node->size[0]++;
}

void insertNext(TreeNode *next, TreeNode *node)
{
    node->next = (TreeNode *) realloc(node->next, sizeof(TreeNode) * (node->size[1] + 1));
    node->size[1]++;
}

void removeVal(int val, TreeNode *node)
{

    node->val = (int *) realloc(node->val, sizeof(int) * ());
    node->size[0]--;
}

void removeNext(TreeNode *next, TreeNode *node)
{
    node->next = (TreeNode *) realloc(node->next, sizeof(TreeNode) * (node->size[1] + 1));
    node->size[1]--;
}

void freeNode(TreeNode *node)
{
    free(node);
}