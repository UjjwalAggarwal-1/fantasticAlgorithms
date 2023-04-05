#include <stdio.h>
#include <stdlib.h>


typedef struct node * NODE;
struct node {
    int value;
    NODE left;
    NODE right;
};

typedef struct bst * BST;
struct bst {
    NODE root;
};

BST new_bst() 
{
    BST bst = malloc(sizeof(struct bst));
    bst->root = NULL;
    return bst;
}

NODE new_node(int value) 
{
    NODE node = malloc(sizeof(struct node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(NODE node)
{
    if (node == NULL)
    {
        // printf("NULL ");
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void insert(BST bst, int value)
{
    NODE node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    NODE current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int search(BST bst, int key)
{
    NODE current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST bst)
{
    NODE current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST bst)
{
    NODE current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

NODE predecessor(NODE node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    NODE current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

NODE successor(NODE node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    NODE current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST bst, NODE node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // node is a leaf
        NODE current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // node only has right child
        NODE current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // node only has left child
        NODE current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // node has both children
    NODE temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

///////////////////////////////////

void traverse_pre_order(NODE root){

    NODE curr = root;
    if (curr==NULL){
        // printf("NULL ");
        return;
    }

    printf("%d ", curr->value);
    traverse_pre_order(curr->left);
    traverse_pre_order(curr->right);

    return;
}

void traverse_post_order(NODE root){

    NODE curr = root;
    if (curr==NULL){
        // printf("NULL ");
        return;
    }

    traverse_post_order(curr->left);
    traverse_post_order(curr->right);
    printf("%d ", curr->value);

    return;
}

void level_order_traversal_call(NODE curr, NODE* q, int size, int cnt){
    
    printf("%d ", curr->value);
    if (curr->left){
        q = (NODE*) realloc(q, (size+1)*sizeof(NODE));
        *(q+size++) = curr->left;
    }
    if (curr->right){
        q = (NODE*) realloc(q, (size+1)*sizeof(NODE));
        q[size++] = curr->right;
    }
            // NODE* q2 = (NODE*) malloc((size-1)*sizeof(NODE));
            // for (int i=1;i<size;i++){
            //     *(q2+i-1) = *(q+i);
            // }
            // free(q);
    cnt++;
    if (cnt>=size){
        return;
    }
    return level_order_traversal_call((q[cnt]), q, size, cnt);
}

void level_order_traversal(NODE root){
    if (root==NULL){
        return;
    }
    NODE* q = (NODE*) malloc(1*sizeof(NODE));
    *q = root;
    level_order_traversal_call(root, q, 1, 0);
    free(q);
    return;
}

BST constructBST(int arr[], int n){
    BST bst = new_bst();
    for (int i=0;i<n;i++){
        insert(bst, arr[i]);
    }
    return bst;
}

int height_bst_inner(NODE root, int h){
    if (root==NULL){
        return h-1;
    }
    int l = height_bst_inner(root->left, h+1);
    int r = height_bst_inner(root->right, h+1);
    return l>r?l:r;
}

int height_bst(NODE root){
    if (root==NULL){
        return 0;
    } 
    return height_bst_inner(root, 0);
}

void remove_half_nodes_inner(BST bst, NODE node){
    if (node == NULL)
        return;
    
    // node only has right child
    if (node->left == NULL && node->right!=NULL)
    {
        NODE current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        remove_half_nodes_inner(bst, node->right);
        free(node);
        return;
    }

    // node only has left child
    if (node->right == NULL && node->left != NULL)
    {
        NODE current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        remove_half_nodes_inner(bst, node->left);
        free(node);
        return;
    }
    remove_half_nodes_inner(bst, node->left);
    remove_half_nodes_inner(bst, node->right);
    return;
}

void remove_half_nodes(BST bst){
    return remove_half_nodes_inner(bst, bst->root);
}

NODE flatten_bst_inner(NODE root){

    if (root==NULL){
        return NULL;
    }
    NODE node = new_node(root->value);
    node->left = NULL;
    node->right = flatten_bst_inner(root->left);
    NODE temp = node;
    while(node->right!=NULL){
        node = node->right;
    }
    node->right = flatten_bst_inner(root->right);
    free(root);
    return temp;
}

void flatten_bst(BST bst){
    bst->root = flatten_bst_inner(bst->root);
    return;
}

int verify_bst_property(NODE root){
    if(root==NULL) return 1;

    if (root->left){
        if (root->left->value > root->value){
            return 0;
        }
        int l=verify_bst_property(root->left);
        if (!l){
            return l;
        }
    }
    if (root->right){
        if (root->right->value < root->value){
            return 0;
        }

        int r=verify_bst_property(root->right);
        if (!r){
            return r;
        }
    }

    return 1;
}

int reverse_level_order_traversal_call(NODE curr, NODE* q, int size, int cnt){
    if (curr->right){
        q = (NODE*) realloc(q, (size+1)*sizeof(NODE));
        q[size++] = curr->right;
    }
    if (curr->left){
        q = (NODE*) realloc(q, (size+1)*sizeof(NODE));
        *(q+size++) = curr->left;
    }
    cnt++;
    if (cnt>=size){
        return size;
    }
    return reverse_level_order_traversal_call((q[cnt]), q, size, cnt);
}

void reverse_level_order_traversal(NODE root){
    if (root==NULL){
        return;
    }
    NODE* q = (NODE*) malloc(1*sizeof(NODE));
    *(q) = root;
    int s = reverse_level_order_traversal_call(root, q, 1, 0);
    for (int i=s-1;i>=0;i--){
        printf("%d ", (*(q+i))->value);
    }
    free(q);
    return;
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{   
    int arr[9] = {3,2,4,5,1,7,8,6,9};
    BST bst = constructBST(arr, 9);
    
    // BST bst = new_bst();
    // insert(bst, 2);
    // insert(bst, 1);
    // insert(bst, 3);
    // insert(bst, 4);
    // insert(bst, 5);
    // insert(bst, 7);
    // insert(bst, 6);
    // insert(bst, 8);
    
    traverse_in_order(bst->root);
    printf("\n");
    // traverse_pre_order(bst->root);
    // printf("\n");
    // traverse_post_order(bst->root);
    // printf("\n");
    // level_order_traversal(bst->root);
    // printf("\n");
    // reverse_level_order_traversal(bst->root);
    // printf("\n");
    
    // printf("Height = %d\n",height_bst(bst->root));
    // printf("Max = %d\n", find_max(bst));
    // printf("Min = %d\n", find_min(bst));
    // printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    // printf("Successor of root = %d\n", successor(bst->root)->value);
    // printf("Satisfies bst property: %d\n", verify_bst_property(bst->root));
    
    // delete(bst, bst->root->left);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root->right);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root);
    // traverse_in_order(bst->root);
    // printf("\n");
    // printf("Height = %d\n",height_bst(bst->root));

    // remove_half_nodes(bst); //chh
    // traverse_in_order(bst->root);
    // printf("\n");
    
    // flatten_bst(bst);
    // traverse_in_order(bst->root);
    // printf("\n");
    // traverse_pre_order(bst->root);
    // printf("\n");
    // traverse_post_order(bst->root);
    // printf("\n");
    
    return 0;
}