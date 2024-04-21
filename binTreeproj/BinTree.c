#include "BinTree.h"

struct BinTree {
    int id;
    int age;
    Levi family;
    GenericFunc task;
    void* part;
    BinTree* left;
    BinTree* right;
};


void generic_function(BinTree* root, GenericFunc task) {
    task(root);
}

/***********************************************************************************
* Function name: gershonTask
* Input: void*
* Output: none
* Function Operation:
**********************************************************************************/

static void gershonTask(void *part) {
    printf("Gershon family take %s\n", (char*) part);
}


static void kehatTask(void *part) {
    printf("Kehat family take %s\n", (char*) part);
}


static void merariTask(void *part) {
    printf("Merari family take %s\n", (char*) part);
}

/*******************************************************************************************************************
* Function name: findKey
* Input: (BinTree* root, int key
* Output: BinTree*
* Function Operation: this function will search for the node with the matching id,
  if it will find matching node it will return pointer to him,else it will return null,means there is no such id
*******************************************************************************************************************/


static BinTree* findKey(BinTree* root, int key){
    //if the root is null or root id equals to given id we end the loop
    if (root == NULL || key == root->id) {
        return root;
    }
    //if key is < than root id,the correct root can be only to the left of the corrent root
    if (key < root->id) {
        return findKey(root->left, key);
    } else {//it can be only to its right
        return findKey(root->right, key);
    }
}

/***********************************************************************************
* Function name: getFamilyName
* Input: Levi family
* Output: string
* Function Operation: for the given levi family it will return its correct string
**********************************************************************************/

static char* getFamilyName(Levi family) {
    switch(family) {
        case Gershon:
            return GERSHON;
        case Kehat:
            return KEHAT;
        case Merari:
            return MERARI;
        default:
            return NULL;
    }
}

/***********************************************************************************
* Function name: createNewLevi
* Input: int id, Levi family
* Output: BinTree*
* Function Operation: the function will create an empty root,will fill his field with,
  the given inputs and will return the correct root
**********************************************************************************/

static BinTree* createNewLevi(int id, Levi family){
    BinTree* newLevi = (BinTree*) malloc(sizeof(BinTree));
    //if allocation has failed
    if(newLevi == NULL){
        return NULL;
    }
    newLevi->id = id;
    newLevi->age = START_AGE;
    newLevi->family = family;
    //matching the part and task to the given family
    switch(family) {
        case Gershon:
            newLevi->task = gershonTask;
            newLevi->part = GERSHON_PART;
            break;
        case Kehat:
            newLevi->task = kehatTask;
            newLevi->part = KEHAT_PART;
            break;
        case Merari:
            newLevi->task = merariTask;
            newLevi->part = MERARI_PART;
            break;
        default:
            newLevi->task = NULL;
            newLevi->part = NULL;
    }
    newLevi->left = NULL;
    newLevi->right = NULL;
    return newLevi;
}

/***********************************************************************************
* Function name: addToBinTree
* Input: BinTree* root, BinTree* newLevi
* Output: BinTree*
* Function Operation: the function will search for correct place for the new node,
 and will return pointer to the new root,after the new node has added
**********************************************************************************/

static BinTree* addToBinTree(BinTree* root, BinTree* newLevi) {
    // Base case the function reached the right place for the new node
    if (root == NULL) {
        return newLevi;
    }
    //if the new node id is bigger the the current node, the new root should be on the curr root's left
    if (root->id > newLevi->id) {
        root->left = addToBinTree(root->left, newLevi);
    } else {//its on its right
        root->right = addToBinTree(root->right, newLevi);
    }

    return root;
}

/***********************************************************************************
* Function name: newLeviIsBorn
* Input: BinTree** root
* Output: none
* Function Operation: this function will call all the right functions in order,
 to create the new lavi,and place it in the tree,also this function will ask for
 the new levi parameters
**********************************************************************************/

void newLeviIsBorn(BinTree** root) {
    int id;
    printf("please enter Levi id:\n");
    scanf("%d", &id);
    Levi family;
    printf("please insert Levi family (0 - Gershon, 1 - Kehat, 2- Merari):\n");
    scanf("%d", &family);
    //check if the id is'nt already exist
    if(findKey(*root, id) != NULL){
        return;
    }
    //creating the new levi with the given parameters
    BinTree *newTree = createNewLevi(id, family);
    // Check for dynamic allocation failure
    if (newTree == NULL) {
        exit(1);
    }
    //add's the new root to the tree
    *root = addToBinTree(*root, newTree);
}

/***********************************************************************************
* Function name: printLevi
* Input: BinTree *root
* Output: none
* Function Operation: this function will print the given levi
**********************************************************************************/

static void printLevi(BinTree *root) {
    printf("id: %d, Family: %s age: %d\n", root->id, getFamilyName(root->family), root->age);
}

/***********************************************************************************
* Function name: printTreePreorder
* Input: void *root
* Output: none
* Function Operation: this function will print the tree in pre order style,print
 root than its left side,and than its right
**********************************************************************************/

static void printTreePreorder(void *root) {
    if (root == NULL) {
        return;
    }
    BinTree *curr = (BinTree*)root;
    printLevi(curr);
    printTreePreorder(curr->left);
    printTreePreorder(curr->right);
}

/***********************************************************************************
* Function name: printTreeInorder
* Input: void *root
* Output: none
* Function Operation: this function will print the tree in-order style,print
  its left root sons,than the root ,and than its right son,making the root appear
  somewhat in the middle
**********************************************************************************/


static void printTreeInorder(void *root) {
    if (root == NULL) {
        return;
    }
    BinTree *curr = (BinTree*)root;
    printTreeInorder(curr->left);
    printLevi(curr);
    printTreeInorder(curr->right);
}

/***********************************************************************************
* Function name: printTreePostorder
* Input: void *root
* Output: none
* Function Operation: this function will print the tree in post order style,print
 first it will print all the root sons,and than the root himself
**********************************************************************************/

static void printTreePostorder(void *root) {
    if (root == NULL) {
        return;
    }
    BinTree *curr = (BinTree*)root;
    printTreePostorder(curr->left);
    printTreePostorder(curr->right);
    printLevi(curr);
}

/***********************************************************************************
* Function name: printBothTrees
* Input: BinTree *workingTree, BinTree *youngsTree
* Output: none
* Function Operation: this function will ask for the order the trees need to be printed,
 and than will print the tree
**********************************************************************************/

void printBothTrees(BinTree *workingTree, BinTree *youngsTree){

    int order;
    printf("please enter order of print (0 - preorder, 1- inoreder, 2 - postorder):\n");
    scanf("%d", &order);

    GenericFunc printFuncs[] = {printTreePreorder, printTreeInorder, printTreePostorder,};

    printf("Levi 30+:\n");
    generic_function(workingTree,printFuncs[order]);
    printf("Levi 30-:\n");
    generic_function(youngsTree,printFuncs[order]);

}

/***********************************************************************************
* Function name: workPreorder
* Input: void *root
* Output: none
* Function Operation: this function will print the working tree nodes parts in-order style,print
  its left root sons,than the root ,and than its right son,making the root appear
  somewhat in the middle
**********************************************************************************/

static void workPreorder(void *root) {
    if (root == NULL) {
        return;
    }
    BinTree *curr = (BinTree*)root;
    curr->task(curr->part);
    workPreorder(curr->left);
    workPreorder(curr->right);
}

/***********************************************************************************
* Function name: workInorder
* Input: void *root
* Output: none
* Function Operation: this function will print the working tree nodes parts in-order style,print
  its left root sons,than the root ,and than its right son,making the root appear
  somewhat in the middle
**********************************************************************************/


static void workInorder(void *root) {
    if (root == NULL) {
        return;
    }
    BinTree *curr = (BinTree*)root;
    workInorder(curr->left);
    curr->task(curr->part);
    workInorder(curr->right);
}

/***********************************************************************************
* Function name: workPostorder
* Input: void *root
* Output: none
* Function Operation: this function will print the working tree nodes parts Postorder style,print
  its left root sons,than the root ,and than its right son,making the root appear
  somewhat in the middle
**********************************************************************************/

static void workPostorder(void *root) {
    if (root == NULL) {
        return;
    }
    BinTree *curr = (BinTree*)root;
    workPostorder(curr->left);
    workPostorder(curr->right);
    curr->task(curr->part);
}

/***********************************************************************************
* Function name: sendToWork
* Input: BinTree* workingTree
* Output: none
* Function Operation: this function will ask for the wanted order of print,
 * and than will "send" all the working levi to their jobs (will print it on screen)
**********************************************************************************/

void sendToWork(BinTree* workingTree) {
    int order;
    printf("please enter order of task (0 - preorder, 1- inoreder, 2 - postorder):\n");
    scanf("%d", &order);
    // if checks if the order entered is valid
    if (order < 0 || order > 2) {
        printf("wrong order!\n");
        return;
    }
    //arr of the correct functions
    GenericFunc work[] = {workPreorder, workInorder, workPostorder};
    //generic function which call the cast all the info for the printing function
    generic_function(workingTree, work[order]);
}

/***********************************************************************************
* Function name: addFiveYearsToAge
* Input: void* root
* Output:
* Function Operation: this function will add five years to the root age,
 than to its right sons, than to its left sons
**********************************************************************************/

static void addFiveYearsToAge(void* root){
   //base case
    if(root == NULL){
        return;
    }
    BinTree *curr = (BinTree*)root;
    curr->age += 5;
    generic_function(curr->right, addFiveYearsToAge);
    generic_function(curr->left, addFiveYearsToAge);
}

/***********************************************************************************
* Function name: minValueNode
* Input: BinTree* node
* Output: BinTree*
* Function Operation: this function will find the smallest among
 the the roots with larger id of the given node
**********************************************************************************/

static BinTree* minValueNode(BinTree* node){
    BinTree* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**********************************************************************************************
* Function name: copyTree
* Input: BinTree* target, BinTree* source
* Output:none
* Function Operation: this function will copy the values of the given node to a diffrent node
********************************************************************************************/

static void copyTree(BinTree* target, BinTree* source){
    target->id = source->id;
    target->age = source->age;
    target->family = source->family;
    target->part = source->part;
    target->task = source->part;
}

/***********************************************************************************
* Function name: removeLeviFromTree
* Input: BinTree *levi, BinTree *root
* Output: BinTree*
* Function Operation: this function will search for a node with the same id of a given node,
 if it will find one,it than will search for it replacement,which will be a leaf ,or
 node with only 1 son,than it will copy the replamcent node to the node need to be
 deleted,and than will call recursivly to itself and will delete the replacment node,
 in that way only replacment node will truly be deleted and the orgin node,will hold
 the values of the replacment node
**********************************************************************************/


static BinTree* removeLeviFromTree(BinTree *levi, BinTree *root) {
    // Base case
    if (root == NULL)
        return NULL;

    if (levi->id < root->id) {
        root->left = removeLeviFromTree(levi, root->left);
    } else if (levi->id > root->id) {
        root->right = removeLeviFromTree(levi, root->right);
    } else {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        } else if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }

        // 1. Find the left-most node on the root->right tree
        BinTree *tmp = minValueNode(root->right);
        // 2. Copy values from tmp to root
        copyTree(root, tmp);
        // 3. Remove duplicates
        root->right = removeLeviFromTree(tmp, root->right);
    }

    // Return the new root of the tree
    return root;
}

/***********************************************************************************
* Function name: removeLevi
* Input: BinTree *youngsTree, BinTree **workingTree
* Output: none
* Function Operation: this function will ask for the id on the levi that need to be
 deleted will check if the levi is exist and than will call the function which removes
 levi, than it will add the removed levi to the working tree
**********************************************************************************/

void removeLevi(BinTree *youngsTree, BinTree **workingTree) {
    int id;
    printf("please enter Levi id:\n");
    scanf("%d", &id);

    BinTree *levi = findKey(*workingTree, id);

    if (levi == NULL && !findKey(youngsTree, id)) {
        printf("wrong id!\n");
        return;
    }

    *workingTree = removeLeviFromTree(levi, *workingTree);
    free(levi);
}

/***********************************************************************************
* Function name: countMembers
* Input: BinTree *root, int family
* Output:int number of members
* Function Operation: this function will count the amout of memebers of the same family
    if the root if in the given family it will add 1 to the total sum
**********************************************************************************/



static int countMembers(BinTree *root, int family) {

    if (root == NULL) {
        return 0;
    }//this if loop check if the root is in the same family and on the right age it will return the fun with root sons + 1
    if (root->family == family && root->age > 0) {
        return 1 + countMembers(root->right, family) +
               countMembers(root->left, family);
    } else {
        return countMembers(root->right, family) +
               countMembers(root->left, family);
    }


}

/***********************************************************************************
* Function name: countAllLevis
* Input: BinTree *root
* Output: int which is the amount of all the levis
* Function Operation:this function will count every levi if he's on the right age
**********************************************************************************/
static int countAllLevis(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->age > 0) {//checks the age of the levi if its good it will add this root to the sum
        return 1 + countAllLevis(root->left) + countAllLevis(root->right);
    }
    return countAllLevis(root->left) + countAllLevis(root->right);//if the levi is under aged it wont be calculated
}

/***************************************************************************************************
* Function name: countLevis
* Input: BinTree* youngsTree, BinTree* workingTree
* Output: none
* Function Operation: this function will ask the user for the family wanted,
 will call the right function and will print the size of the given family and the total family size
***************************************************************************************************/
void countLevis(BinTree* youngsTree, BinTree* workingTree) {
    int num = 0, totalNum = 0, family = 0;
    printf("please insert Levi family (0 - Gershon, 1 - Kehat, 2- Merari):\n");
    scanf("%d", &family);

    num = countMembers(youngsTree, family) + countMembers(workingTree, family);
    totalNum = countAllLevis(youngsTree) + countAllLevis(workingTree);
    printf("size of %s family: %d, size of all Levi: %d\n", getFamilyName(family), num, totalNum);
}
/***********************************************************************************
* Function name: clearTree
* Input: BinTree *root
* Output:  none
* Function Operation: this function will go down the tree and will free the memory
 allocated for each root and his parents
**********************************************************************************/

void clearTree(BinTree *root) {
if (root == NULL){//if the tree is empty
    return;
}
    clearTree(root->right);
    clearTree(root->left);
    free(root);
    root =NULL;
}
/***********************************************************************************
* Function name: findLeviOlderThan
* Input:BinTree* root, int age
* Output:BinTree*
* Function Operation: this functiom will find root in the age given,and will return
 pointer to them for othe function usage
**********************************************************************************/

static BinTree* findLeviOlderThan(BinTree* root, int age) {
    if (root == NULL)//base case
        return NULL;
    if (root->age >= age)// if the root is on te right age
        return root;

    BinTree *tmp = NULL;
    //this recurtion will search for other levis on the left of the tree
    tmp = findLeviOlderThan(root->left, age);
    if (tmp != NULL)
        return tmp;
    //this recurtion will search for other levis on the right of the tree
    tmp = findLeviOlderThan(root->right, age);
    if (tmp != NULL)
        return tmp;

    return NULL;
}

/***********************************************************************************
* Function name: transferLeviToWorking
* Input:BinTree* levi, BinTree** youngsTree, BinTree** workingTree
* Output:none
* Function Operation:this fuction will remove the given levi from the youngs tree,
 * and will add it to the working tree
**********************************************************************************/

static void transferLeviToWorking(BinTree* levi, BinTree** youngsTree, BinTree** workingTree) {
    *youngsTree = removeLeviFromTree(levi, *youngsTree);
    *workingTree = addToBinTree(*workingTree, levi);
    levi->right = NULL;
    levi->left = NULL;
}
/***********************************************************************************
* Function name: addAndTransfer
* Input:BinTree** youngsTree, BinTree** workingTree
* Output:none
* Function Operation: this functuin will add 5 years
 to all the memebers of both tree than it will search first for levis that are able to
 * work on the youngs tree,will use the remove func to transfer them to the working tree
 than it will serch for levis that are too old to work,remove them from the working tree
 and send them to retirement
**********************************************************************************/

void addAndTransfer(BinTree** youngsTree, BinTree** workingTree) {
    generic_function(*youngsTree, addFiveYearsToAge);
    generic_function(*workingTree, addFiveYearsToAge);

    BinTree *levi = NULL;

    while ((levi = findLeviOlderThan(*youngsTree, 30)) != NULL) {
        transferLeviToWorking(levi, youngsTree, workingTree);
    }

    while ((levi = findLeviOlderThan(*workingTree, 50)) != NULL) {
        *workingTree = removeLeviFromTree(levi, *workingTree);
        free(levi);
    }
}
