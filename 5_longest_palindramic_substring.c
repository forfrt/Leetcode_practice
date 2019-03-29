#include <string.h>
#include <stdio.h>

char* longestPalindrome1(char* prime, char* s) {
    int len=strlen(s);
    int priLen=strlen(prime);

    if(len==0) {
        printf("len==0 %s\n", "");
        return "";
    } else if(len==1) {
        printf("len==1 %s\n", s);
        return s;
    }

    int startP=0;

    for(int i=len; i<priLen-1; i++) {
        startP+=(prilen-len+1);
    }

    int pos=strstr(prime, s)-prime+startP;

    if(recur_flags[pos]==1) {
        return recur_rooms[pos];
    } else if(recur_flags[pos]==-1) {
        return NULL;
    } else {

        if(s[0]==s[len-1]) {
            char *tru=malloc((len-2)*sizeof(char));

            if(longestPalindrome(strncpy(tru, s+1, len-2))) {
                recur_flags[pos]=1;
                recur_rooms[pos]=s;
                return s;
            }

            recur_flags[pos]=-1;
            return NULL;
        } else {
            char *rStr, *lStr;
            char *rRet, *lRet;
            int rLen, lLen=0;
            rStr=malloc((len-1)*sizeof(char));
            lStr=malloc((len-1)*sizeof(char));

            strncpy(rStr, s+1, len-1);
            strncpy(lStr, s, len-1);

            rRet=longestPalindrome(rStr);
            lRet=longestPalindrome(lStr);

            if(rRet) {
                rLen=strlen(rRet);
                recur_flags[pos+priLen-len+1]=1;
                recur_rooms[pos+priLen-len+1]=rStr;
            }

            if(rRet) {
                rLen=strlen(rRet);
                recur_flags[pos+priLen-len+1]=1;
                recur_rooms[pos+priLen-len+1]=rStr;
            }

            rightLen=right?strlen(right):0;
            leftLen=left?strlen(left):0;

            printf("rStr: %s, lStr: %s, rLen is %d, lLen: %d, s: %s\n",
                   rStr, lStr, rightLen, leftLen, s);

            if(right && rightLen>=leftLen) {
                printf("right is %s, rStr: %s\n", right, rStr);
                return right;
            } else if(left && leftLen>rightLen) {
                printf("left is %s, lStr: %s\n", left, lStr);
                return left;
            }

            return NULL;

        }
    }
}

static char **recur_rooms;
static char **recur_flags;

char* longestPalindrome(char* s) {
    int room_size=0;
    int len=strlen(s);

    for(int i=len-1; i>1; i--) {
        room_size+=i;
    }

    recur_rooms=malloc(sizeof(char)*room_size);
    recur_flags=malloc(sizeof(char)*room_size);

    if(len==0) {
        printf("len==0 %s\n", "");
        return "";
    } else if(len==1) {
        printf("len==1 %s\n", s);
        return s;
    } else {
        char *tru=malloc((len-2)*sizeof(char));

        if(s[0]==s[len-1]) {
            if(longestPalindrome1(s, strncpy(tru, s+1, len-2))) {
                recur_flags[0]=1;
                recur_rooms[0]=s;

                /*
                recur_flags[3]=1;
                recur_rooms[3]=tru;
                */
                return s;
            }

            recur_flags[3]=-1;
            return NULL;
        } else {
            char *rStr, *lStr;
            char *rRet, *lRet;
            int rLen, lLen=0;
            rStr=malloc((len-1)*sizeof(char));
            lStr=malloc((len-1)*sizeof(char));

            strncpy(rStr, s+1, len-1);
            strncpy(lStr, s, len-1);

            rRet=longestPalindrome1(s, rStr);
            lRet=longestPalindrome1(s, lStr);

            rLen=strLen(rRet);
            lLen=strLen(lRet);

            printf("rStr: %s, lStr: %s, rLen is %d, lLen: %d, s: %s\n",
                   rStr, lStr, rightLen, leftLen, s);

            if(rRet && rLen>=lLen) {
                printf("rRet is %s, rStr: %s\n", rRet, rStr);
                return rRet;
            } else if(lRet && lLen>rLen) {
                printf("left is %s, lStr: %s\n", left, lStr);
                return lRet;
            }

            return NULL;

        }
    }
}


char *search4Palindrome(char *s, char **rooms, char *flags, int pos, int cap) {

    int len=strlen(s);

    if(rooms[pos]==1) {
        return rooms[pos];
    }


    if(s[0]==s[len-1]) {
        char *tru=malloc((len-2)*sizeof(char));
        strcpy(tru, s+1, len2);

        if(search4Palindrome(tru, rooms, flags, pos+2*cap+2, cap+2)) {

            rooms[pos]=s;
            flags[pos]=1;
            return s;
        }

        char *rStr, *lStr;
        char *rRet, *lRet;
        int rLen, lLen=0;

        lStr=malloc((len-1)*sizeof(char));
        rStr=malloc((len-1)*sizeof(char));

        strncpy(lStr, s, len-1);
        strncpy(rStr, s+1, len-1);

        lRet=longestPalindrome(lStr, rooms, flags, pos+cap, cap+1);
        rRet=search4Palindrome(rStr, rooms, flags, pos+cap+1, cap+1);

        lLen=strlen(lRet);
        rLen=strlen(rRet);

        if(lRet & lLen>rLen) {
            rooms[pos]=lRet;
            flags[pos]=1;
            return lRet;
        } else if(rRet & rLen>lLen) {
            rooms[pos]=rRet;
            flags[pos]=1;
            return rRet;
        } else {
            rooms[pos]=NULL;
            flags[pos]=-1;
            return NULL;
        }


    }
}

}

char *longestPalindrome(char* s) {
    int room_size=0;
    int len=strlen(s);

    for(int i=len-1; i>1; i--) {
        room_size+=i;
    }

    char** recur_rooms=malloc(sizeof(char*)*room_size);
    char* recur_flags=malloc(sizeof(char)*room_size);

    search4Palindrome(s, recur_rooms, recur_flags, 0, 1);

}

































int main(int argc, char **argv) {
    char *a="babad";
    printf("longestPalidrome of %s is %s\n", a, longestPalindrome(a));

    char *b="cbbd";
    printf("longestPalidrome of %s is %s\n", b, longestPalindrome(b));

    char *c="babaddtattarrattatdd";
    printf("longestPalidrome of %s is %s\n", c, longestPalindrome(c));

}
