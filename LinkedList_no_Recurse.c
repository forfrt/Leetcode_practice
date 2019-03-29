#define SIZE 100

typedef struct seqstack{
    bintree data[SIZE];
    int tag[SIZE];
    int top;
}seqstack;

void push(seqstack *s, bintree t){
    if(s->top==SIZE){
        printf("the stack is full\n");
    }else{
        s->top++;
        s->data[s->top]=t;
    }
}

bintree pop(seqstack *s){
    if(s->top==-1){
        return NULL;
    }else{
        s->top--;
        return s->data[s->top+1]
    }
}
