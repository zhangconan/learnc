#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "other/gloabl_variable.h"

struct testsss{
    int test[256];
};

int main()
{
    //learnPointer();
    //test();
    //printf("Hello world!\n");
    //testInt2Buff();
    //printf("%d",rand());
    //char buff[] = "aello" ;
    //charAdd(buff);
    //int a = PJWHash(buff,4);
    //printf("%d",a);
    //char *dest;
    //base64_encode_ex(buff,2,dest,3);
    /*
    char encoded[sizeof(int) * 8 + 1];
    char *a = encoded;
    *a++ = 12;
    *a++ = 12;
    *a++ = 12;
    *a = '\0';
    int *c = a - encoded;
    //testPointMinus(encoded,a);
    printf("%d",c);
    char encoded[128];
    char *szFormattedExt = "niha";
    int *filename_len = 5;
    get_file_name(encoded,&filename_len,szFormattedExt);
    printf("%s\n",encoded);
    printf("%d",filename_len);
    testmemset(0, '-', '_', '.');
    */
    char src[] = "hello";
    int nSrcLen = 2;
    bool bPad = false;
    base64_encode_ex(src,nSrcLen,bPad);
    return 0;
}


