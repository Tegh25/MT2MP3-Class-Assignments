#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************The binary tree***********************
 *
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

/*
Author: Teghveer Ateliey
Date created: Dec 8, 2022
Last modified: Dec 8, 2022
Purpose: To be able to search through a binary tree with depth and dfs functions
*/

// data structure for binary tree
struct node {
    char *name;
    char *tea;
    struct node *left;
    struct node *right;
}; // end of data structure
//typedef for data structure to accept name of Node
typedef struct node Node;

//depth function to find depth of binary tree, takes root node of tree as input and outputs depth as int
int depth(struct node *bt) {
    // returns 0 if node is null
    if (bt == NULL) {
        return 0;
    } else {
        // iterates through the depth of the left and right half of the tree
        int leftDepth = depth(bt->left);
        int rightDepth = depth(bt->right);
        // returns the larger depth found after iterating through tree
        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
} //end of depth function

// dfs function to output number of nodes examined as int until found the desired name, takes root of BT and name as input
int dfs(struct node *root,char *name){
// variables to be used in search algorithm
int examinations = 0;
int searchFound = 0;
//calling a new function to use in search algorithm that will use new variables
dfsSearch(root, name, &examinations, &searchFound);
// returns -1 if the name was not found
if (searchFound != 1){
    return -1;
}
//returns the number of examinations as int
return examinations;
} //end of dfs function

// dfssearch function to output number of nodes examined as int until found the desired name
// takes root of BT and name as input, along with number of examinations and if the name search has been found
void dfsSearch(struct node *root, char *name, int *examinations, int *searchFound) {
if (root == NULL){
    return;
}
*examinations += 1;
// compares strings to see if name matches
if (strcmp(name,root->name) == 0){
    // sets 1 for searchFound and returns, meaning it found the desired name
    *searchFound = 1;
    return; 
}
// recursive call of function if the name does not match, moving to left branch
dfsSearch(root->left,name,examinations,searchFound);
    //returns if name was found
if(*searchFound == 1){
    return;
}
// recursive call of function if the name does not match, moving to right branch
dfsSearch(root->right,name,examinations,searchFound);
} // end of dfssearch function

int main() {
    // Testing code ^_^
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
}