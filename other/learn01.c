#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "structLearn.h"

void sizeofStruct(){

    int a = sizeof(TrackerHeader);

    printf("%d\n",a);
}
void charPointer(){

    char *p;
    p = 10;

    int64_t file_offset = buff2long(p);
    printf("%d\n",file_offset);
}

 int64_t buff2long(const char *buff)
{
	unsigned char *p;
	p = (unsigned char *)buff;
	return  (((int64_t)(*p)) << 56) | \
		(((int64_t)(*(p+1))) << 48) |  \
		(((int64_t)(*(p+2))) << 40) |  \
		(((int64_t)(*(p+3))) << 32) |  \
		(((int64_t)(*(p+4))) << 24) |  \
		(((int64_t)(*(p+5))) << 16) |  \
		(((int64_t)(*(p+6))) << 8) | \
		((int64_t)(*(p+7)));
}


 int64_t buff2long01(const char *buff)
{
	unsigned char *p;
	p = (unsigned char *)buff;
    printf("%c\n",((*(p+4))));
	printf("%d\n",((int64_t)(*(p+4))));
	printf("%s\n",buff);
	return  (((int64_t)(*(p+4))) << 24);
}

int buff2int(const char *buff)
{
	return  (((unsigned char)(*buff)) << 24) | \
		(((unsigned char)(*(buff+1))) << 16) |  \
		(((unsigned char)(*(buff+2))) << 8) | \
		((unsigned char)(*(buff+3)));
}
