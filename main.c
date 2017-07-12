#include <stdio.h>
#include <stdlib.h>

int main()
{
    //learnPointer();
    //test();
    //printf("Hello world!\n");
    //testInt2Buff();
    //printf("%d",rand());
    char buff[] = "aello" ;
    //charAdd(buff);
    //int a = PJWHash(buff,4);
    //printf("%d",a);
    char *dest;
    base64_encode_ex(buff,2,dest,3);
    return 0;
}

