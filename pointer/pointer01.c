#include <stdio.h>

void learnPointer()
{

    int a = 5;
    int b = 10;
    float c = 3.14;
    //&������ʼ��һ��ָ��
    int *d = &a;
    float *e = &c;
    //�����������a���ڴ��ַ��ֵ
    printf("a���ڴ��ֵַ%d",d);
    printf("\n");
    //�����������a��ֵ
    printf("a��ֵ%d",d);
    printf("\n");
    *d = 20;
    printf("a��ֵ�ǣ�%d",a);
    printf("\n");
    //ע�������Ǵ����д������Ϊ����û�ж�ָ����г�ʼ����
    //��UNIX�Ͽ��ܻ���֣�segmentation violation����memory fault
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
    printf("%s\n","��");
    pEnd = (unsigned char *)ppSrcs[0]+lens[0];
    printf("%d\n",lens[0]);
    printf("%s",pEnd);
    printf("%s\n","��");
    printf("%s\n",ppSrcs[0]);
}
