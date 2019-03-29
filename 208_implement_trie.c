
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA 97
#define ALPHABET 26
#define bool int
#define true 1
#define false 0

typedef struct trie_node {
    struct trie_node* next[ALPHABET];
    bool is_word;


} Trie;

/*
Trie* trieCreate() {
    Trie t;
    t.is_word=false;

    memset(t.next, 0, sizeof(struct trie_node*)*ALPHABET);

    for(int i=0; i<ALPHABET; i++) {

        if(t.next[i]==0) printf("trieCreate::root.next[%d]: %p is NULL\n", i, t.next[i]);
    }

    printf("trieCreate::root: %p\n", &t);
    printf("trieCreate::root: %p\n", t.next);
    return &t;
}
*/


Trie* trieCreate(void) {
    Trie *pNode=NULL;

    pNode=(struct TrieNode *)malloc(sizeof(Trie));

    if (pNode) {
        int i;
        pNode->is_word=false;

        memset(pNode->next, 0, sizeof(struct trie_node*)*ALPHABET);
    }

    return pNode;

}

void trieInsert(Trie* root, char* word) {
    int index;
    Trie* obj=root;

    while(*word!='\0') {
        index=*word-ALPHA;

        if(!obj->next[index]) {
            printf("--trieInsert--next[%d] is NULL: \n", index);
            obj->next[index]=trieCreate();
        }

        obj=obj->next[index];
        word++;
    }

    obj->is_word=true;
}


bool trieSearch(Trie* root, char* word) {
    int index;
    Trie* obj=root;

    while(*word!='\0') {
        index=*word-ALPHA;

        if(!obj->next[index]) return false;

        obj=obj->next[index];
        word++;
    }

    return obj->is_word;
}

bool trieStartsWith(Trie* root, char* prefix) {
    int index;
    Trie* cur=root;

    while(*prefix!='\0') {
        index=*prefix-ALPHA;

        if(cur->next[index]==NULL) return false;

        cur=cur->next[index];
        prefix++;
    }

    return true;
}

void trieFree(Trie **root) {

    if(!*root) return ;

    for(int i=0; i<ALPHABET; i++) {
        if((*root)->next[i]) {
            trieFree(&((*root)->next[i]));
            printf("deep into %d\n", i);
        }
    }

    free(*root);
    *root=NULL;
}

void trieShow(Trie* root) {

    if(!root) return ;

    for(int i=0; i<ALPHABET; i++) {

        if(root->next[i]) {
            printf("%d\n", i);
            fflush(stdout);
            trieShow(root->next[i]);
        }
    }

}

int main(int argc, char** argv) {
    Trie *root=trieCreate();

    printf("--trieInsert-- for hello: \n");
    trieInsert(root, "hello");
    printf("--trieInsert-- for world: \n");
    trieInsert(root, "world");
    printf("--trieInsert-- for happy: \n");
    trieInsert(root, "happy");

    printf("--trieSearch-- for hell: %d\n", trieSearch(root, "hell"));
    printf("--trieSearch-- for happy: %d\n", trieSearch(root, "happy"));

    printf("--trieStartsWith-- for hell: %d\n", trieStartsWith(root, "hell"));
    printf("--trieStartsWith-- for hell: %d\n", trieStartsWith(root, "wor"));

    trieShow(root);

    printf("----trieFree----%p\n", root);
    trieFree(&root);
    printf("----trieFree----%p\n", root);

    trieShow(root);

}
