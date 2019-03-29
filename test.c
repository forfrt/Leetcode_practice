#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct student {
    char* name ;
    struct student* stds[20];
};

void stdsShow(struct student* root, char* prefix) {
    if(root->name)
        printf(strcat("%s\n", prefix), root->name);

    for(int i=0; i<20; i++) {
        if(root->stds[i]) {
            stdsShow(root->stds[i], strcat(" ", prefix));
        }
    }

}

void passArray(char *a) {

    printf("passArray: \n");
    fflush(stdout);

    printf("%s\n", a);
    fflush(stdout);
    a[1]="a";
    printf("%s\n", a);
    fflush(stdout);
}

int main(int argc, char* argv) {

    char* b="hello";
    passArray(b);
    printf("%s\n", b);
    fflush(stdout);

    struct student s;


    struct student a= {.name="forfrt"};

    for(int i=0; i<20; i++) {
        a.stds[i]=NULL;
    }

    printf("stds[0].name: %p\n", a.stds[0]);
    fflush(stdout);

    a.stds[1]->name="xhj";
    a.stds[2]->name="xhj";
    a.stds[9]->name="zj";
    a.stds[9]->name="hcx";
    a.stds[9]->stds[2]->name="tdhcx";


    stdsShow(&a, "");

}
