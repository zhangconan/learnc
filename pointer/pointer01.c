#include <stdio.h>

void learnPointer()
{

    int a = 5;
    int b = 10;
    float c = 3.14;
    //&用来初始化一个指针
    int *d = &a;
    float *e = &c;
    //这里输出的是a的内存地址的值
    printf("a的内存地址值%d",d);
    printf("\n");
    //这里输出的是a的值
    printf("a的值%d",d);
    printf("\n");
    *d = 20;
    printf("a的值是：%d",a);
    printf("\n");
    //注意这里是错误的写法：因为这里没有对指针进行初始化。
    //在UNIX上可能会出现：segmentation violation或者memory fault
    /*
    int *aa;
    *aa = 12;
    */
    char ch = 'a';
    char cb = ch;
    char *cp = &ch;
    printf("%c",ch);
    printf(&cb);
    printf("\n");
    printf("%c",(++*cp));
}

void charAdd(const char *src){

    unsigned char *pEnd;
    const char *ppSrcs[2];
    int lens[2];
    lens[0] = 7;
    ppSrcs[0] = src;
    printf("%s",pEnd);
    printf("%s\n","飞");
    pEnd = (unsigned char *)ppSrcs[0]+lens[0];
    printf("%d\n",lens[0]);
    printf("%s",pEnd);
    printf("%s\n","张");
    printf("%s\n",ppSrcs[0]);
}
