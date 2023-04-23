#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26 // number of letters in english aplhabet
#define MaxWordSize 20 // max characters of a word in our data // around 17, obtained by hit and trial



//    #############  definitions  #################

typedef struct wordsLLNode * WordsLLNode;
struct wordsLLNode{
    char word[MaxWordSize];
    WordsLLNode next;
};

typedef struct wordsLLHeader * WordsLLHeader;
struct wordsLLHeader{
    WordsLLNode first;
};

typedef struct record * Record;
struct record{
    int count;
    WordsLLHeader head;
};


void insert_wordLLNode_at_i(Record record, WordsLLNode node, int i);
// inserts node at ith position of the linked list


void insert_wordLLNode_first(Record record, WordsLLNode node);
// inserts node at beginning of linked list


Record readData(char filename[]);
// reads data(one word in each line) from 'filename'
// adds these words to the records array(wordBucket) initialised
// as first member of linked list at corresponding record
// finally returns the new array of records (wordBucket)


int findmaxGap(Record wordBuckets);
// requirement: as specified in question
// implemetation: 
// in a record(linked list of word nodes), the gap between any 2 words is zero
// so the gap can exist only between words of 2 different records
// now, incase all buckets have atleast one word, the gap will be 1
// maximum can be found by checking the completely missing letters in the records array
// returns the max gap


void printData(Record wordBuckets);
// prints the words in our records array
// record by record and word by word, in the order they are


WordsLLNode newNodeFromNode(WordsLLNode old);
// return a new node created from an old node, by copying the word string


WordsLLNode newNodeFromString(char* str);
// returns a new node that has its word as the string argument


void partitionListFromHead(WordsLLHeader head);
// partitions a LL depending on words third character
// makes two new LL (right_part and left_part)
// individually free previous nodes
// then joins the new LLs together appropriately and with the previous head of LL as stored in the array of records


void partitionLists(Record wordBuckets);
// iteratively calls partitionListFromHead for each record in array;


void mergeAux(char * L1, int s1, int e1, char* L2, int s2, int e2, char* L3, int s3, int e3);
void merge(char* A, int s, int mid, int e);
void mergeSort(char* arr,int l, int r);
// used collectively to sort LL lexicographically within provided linear space complexity


void emptyLList(WordsLLHeader head);
// frees each node of LL of which head is provided


void makeLLfromArr(WordsLLHeader head, char* A, int size);
// makes a new LL that has the values of the array provided in that very order


void mergeSortBucketsFromHead(WordsLLHeader head, int size);
// makes a array of the linked list of which head is given
// sorts this array by merge sort (calls mergeSort)
// free the previous linked list present (calls emptyLList) 
// make a new one as per sorted array (makeLLfromArr)


void mergeSortBuckets(Record wordBuckets);
// used to iterativel call mergeSortBucketsFromHead for each record head in array;



//   #############  implementations #############

void insert_wordLLNode_at_i(Record record, WordsLLNode node, int i){
    if (record->count < i || i<0){ // should between be 0 to count
        printf("Invalid size\n");
        return;
    }
    
    if (record->count == 0){
        record->count++;
        record->head->first = node;
        node->next = NULL;
        return;
    }

    WordsLLNode i_th_node=record->head->first;
    for(int k=0;k<i;k++){
        i_th_node = i_th_node->next;
    }
    // insert at ith position and increase count
    node->next = i_th_node->next;
    i_th_node->next = node;
    record->count++;
    return;
}

void insert_wordLLNode_first(Record record, WordsLLNode node){
    // since zero indexed,
    return insert_wordLLNode_at_i(record, node, 0);
}

Record readData(char filename[]){
    // initailize array
    Record wordBuckets = (Record) malloc(N*sizeof(struct record));
    for (int i=0;i<N;i++){
        (wordBuckets+i)->count = 0;
        (wordBuckets+i)->head = (WordsLLHeader) malloc(sizeof(struct wordsLLHeader));
        (wordBuckets+i)->head->first = NULL;
    }
    
    //open file in 'read' mode and store the words in file as 'file_word'
    FILE * fptr = fopen(filename, "r");
    if (fptr==NULL){
        printf("file %s Not found\n\n", filename);
        return NULL;
    }
    char file_word[MaxWordSize];
    while(fscanf(fptr, "%s", file_word)==1){ //read until a word is found

        int index = (int)file_word[0] -97;  // ordinal of the first character of 'file_word' but 0 indexed. So a is 0, b is 1,...
        
        // create a new node and insert it into first postion of corresponding record in wordBuckets
        Record cor_rec = wordBuckets+index;
        WordsLLNode new_node = (WordsLLNode) malloc(sizeof(struct wordsLLNode));
        strcpy(new_node->word,file_word);
        new_node->next = NULL;
        insert_wordLLNode_first(cor_rec, new_node);
    }

    return wordBuckets;
}

int findmaxGap(Record wordBuckets){
    int maxgap=1; // incase all buckets have atleast one word, the gap will be 1
    int gap=1;
    for (int i=0;i<N;i++){
        Record rec = wordBuckets+i;
        WordsLLNode first_node = rec->head->first;
        if(first_node!=NULL){
            if(gap>maxgap){
                maxgap = gap;
            }
            gap = 1;
        }else{
            gap++;
        }
    }
    return maxgap;
}

void printData(Record wordBuckets){
    
    for (int i=0;i<N;i++){
        Record rec = wordBuckets+i;
        WordsLLNode node = rec->head->first;
        while(node){
            if (node->word){
                printf("%s\n", node->word);
            }
            node= node->next;
        }
    }
}

WordsLLNode newNodeFromNode(WordsLLNode old){
    WordsLLNode new = (WordsLLNode)malloc(sizeof(struct wordsLLNode));
    strcpy(new->word, old->word);
    new->next = NULL;
    return new;
}

WordsLLNode newNodeFromString(char* str){
    WordsLLNode new = (WordsLLNode)malloc(sizeof(struct wordsLLNode));
    strncpy(new->word, str, MaxWordSize);
    new->next = NULL;
    return new;
}

void partitionListFromHead(WordsLLHeader head){
    if (head->first == NULL){ // trivial case, no element to partition
        return;
    }

    WordsLLHeader left_part = (WordsLLHeader) malloc(sizeof(struct wordsLLHeader)); //third char between a and n
    left_part->first = NULL;
    WordsLLHeader right_part = (WordsLLHeader) malloc(sizeof(struct wordsLLHeader)); // 3rd between m and z
    right_part->first = NULL;

    WordsLLNode node = head->first;
    WordsLLNode last_in_left;
    while(node){
        char third_char = (node->word)[2]; // zero indexed
        if ((int)third_char < 110){  // the ascii of m is 109 and we want to check for chars upto m
            // insert at last position of the left_part header
            WordsLLNode l_node = left_part->first;
            if (l_node==NULL){
                left_part->first = newNodeFromNode(node);
                last_in_left = left_part->first;
            }
            else{
                while(l_node->next){
                    l_node = l_node->next;
                }
                l_node->next = newNodeFromNode(node);
                last_in_left = l_node->next;
            }
        }else{
            //
            WordsLLNode r_node = right_part->first;
            if (r_node==NULL){
                right_part->first = newNodeFromNode(node);
            }
            else{
                while(r_node->next){
                    r_node = r_node->next;
                }
                r_node->next = newNodeFromNode(node);
            }
        }
        WordsLLNode cur_node = node;
        node = node->next;
        free(cur_node);
    }

    head->first = left_part->first;
    last_in_left->next = right_part->first;

    return;
}

void partitionLists(Record wordBuckets){
    for (int i=0;i<N;i++){
        Record rec = wordBuckets+i;
        WordsLLHeader head = rec->head;
        partitionListFromHead(head);
    }
    return;
}

void mergeAux(char * L1, int s1, int e1, char* L2, int s2, int e2, char* L3, int s3, int e3){
    int i,j,k;
    i=s1; j=s2; k=s3;
    while (i <= e1 && j <= e2) {
        if (strncmp((L1+MaxWordSize*i),(L2+MaxWordSize*j),MaxWordSize)<0){
            strncpy((L3+MaxWordSize*k), (L1+MaxWordSize*i), MaxWordSize);
            k++; i++;
        }
        else{
            strncpy((L3+MaxWordSize*k), (L2+MaxWordSize*j), MaxWordSize);
            k++; j++;
        }
    }
    while (i <= e1){
        strncpy((L3+MaxWordSize*k), (L1+MaxWordSize*i), MaxWordSize);
        k++; i++;
    }
    while (j <= e2){
        strncpy((L3+MaxWordSize*k), (L2+MaxWordSize*j), MaxWordSize);
        k++; j++;
    }
}

void merge(char* A, int s, int mid, int e){
    char *C = (char *)malloc(MaxWordSize*sizeof(char) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++){
        strncpy((A+MaxWordSize*s+MaxWordSize*i), (C+MaxWordSize*i), MaxWordSize);
    }
    free(C);
}

void mergeSort(char* arr,int l, int r){

    if (l<r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1,r);
        merge(arr, l,m,r);
    }
}

void emptyLList(WordsLLHeader head){
    if (head->first == NULL){ // trivial case
        return;
    }
    WordsLLNode node = head->first;
    while(node){
        WordsLLNode cur_node = node;
        node = node->next;
        free(cur_node);
    }
    head->first = NULL;
    return;
}

void makeLLfromArr(WordsLLHeader head, char* A, int size){
    if (head->first != NULL){
        printf("Not NUll header found.\n");
        return;
    }

    char* str = A; // for first 20
    WordsLLNode new_f_node = newNodeFromString(str);
    head->first = new_f_node;
    WordsLLNode node = new_f_node;
    for( int i =1;i<size;i++){
        char* str = A + i*MaxWordSize;
        WordsLLNode new_node = newNodeFromString(str);
        node->next = new_node;
        node = new_node;   
    }

}

void mergeSortBucketsFromHead(WordsLLHeader head, int size){
    if (head->first == NULL){ // trivial case, no element to sort
        return;
    }
    WordsLLNode node = head->first;
    char *A = (char *)malloc(MaxWordSize*sizeof(char) * size);
    for (int i=0;i<size; i++){
        strncpy((A+MaxWordSize*i), node->word, MaxWordSize);
        node = node->next;
    }

    mergeSort(A, 0, size-1);
    emptyLList(head);
    makeLLfromArr(head, A, size);

    return;
}

void mergeSortBuckets(Record wordBuckets){
    for (int i=0;i<N;i++){
        Record rec = wordBuckets+i;
        WordsLLHeader head = rec->head;
        mergeSortBucketsFromHead(head, rec->count);
    }
    return;
}



//    ################# driver #############

int main(){

    // filename input from user
    char filename[20];
    printf("enter file name: ");
    scanf("%s", filename);
    // filename hardcoded
    //char filename[20] = "file1.txt";
    Record wordBuckets = readData(filename);
    
    // max gap
    printf("Maximum gap is: %d\n", findmaxGap(wordBuckets));
    printf("\n");

    // partitioning
    partitionLists(wordBuckets);
    printf("Printing wordBuckets array after partitioning:\n");
    printData(wordBuckets);
    printf("\n");
    
    // lexicographical ordering by mergeSort
    printf("Printing wordBuckets array after lexicographical ordering:\n");
    mergeSortBuckets(wordBuckets);
    printData(wordBuckets);
    
    return 0;
}
