
#include "table.h"

const long Prime=101;

const long MaxFile=160;
const long NilPtr=-1;

typedef struct{
    ItemType Info;
    long Next;
} NodeType;

void Error(char * msg);

class HashTableClass: public TableBaseClass {
    public:
        HashTableClass(char Mode, char *FileName);
        ~HashTableClass(void);
        bool Empty(void) const;
        bool Insert(const ItemType & Item);
        bool Retrieve(KeyFieldType SearchKey, 

    private:
        void HandleOpenRead(char * FileName);
        void HandleOpenWrite(char * FileName);
        long Hash(KeyFieldType Key) const;
        long OverflowIndex;
        int NodeSize;
}
