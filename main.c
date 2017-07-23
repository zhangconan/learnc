#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "other/gloabl_variable.h"

#define FDFS_STORAGE_META_FILE_EXT           "-m"
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
    /*
    char src[] = "hellohellohellohellohello";
    int nSrcLen = 20;
    bool bPad = false;
    base64_encode_ex(src,nSrcLen,bPad);
    */
    //sizeof_tracker_header();
    //char fname2log[128+sizeof(FDFS_STORAGE_META_FILE_EXT)];
    //printf("%d",sizeof(fname2log));
    /*
    char fiileName[] = {'C','D','\0'};
    char *pEnd;
    pEnd = NULL;
    int store_path_index = strtol(fiileName, &pEnd, 16);
    if(pEnd != NULL && *pEnd != '0'){
        printf("pEnd %s\n",pEnd);
    }
    printf("%s\n",pEnd);
    printf("%d",store_path_index);
    */
    //test01();
    //test02();
    //char p[] = "192aqsqw1dafdretgdfdf";
    //printf("%d",buff2long(p));
    //printf("%d",buff2int(p));
    //printf("%c",*p);
    //char file[] = "wewewewewewewewe12121212";
    //printf("%s",(char *)file+12);
    //readFile();
    //readLink();
    char buff[] = "/data/";
    char *buff_bak = buff + 6;
    printf("%c",buff_bak[6]);
    printf("%d\n",sizeof(buff)/sizeof(char));
    printf("%s",buff_bak);
    return 0;
}

void testPlus(char *file){

    printf("%syu",file);
}


