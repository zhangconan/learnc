#include <stdio.h>
#include <stdlib.h>

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
    char encoded[sizeof(int) * 8 + 1];
    char *a = encoded;
    *a++ = 12;
    *a++ = 12;
    *a++ = 12;
    *a = '\0';
    int *c = a - encoded;
    //testPointMinus(encoded,a);
    printf("%d",c);
    return 0;
}

