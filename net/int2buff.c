void int2buff(const int n, char *buff)
{
	unsigned char *p;
	p = (unsigned char *)buff;
	*p++ = (n >> 24) & 0xFF;
	*p++ = (n >> 16) & 0xFF;
	*p++ = (n >> 8) & 0xFF;
	*p++ = n & 0xFF;
}

void testInt2Buff(){
    int a = 12;
    int i=0;
    char buff[sizeof(int) * 9];
     for(i=0;i<20;i++){
         printf("%d",buff[i]);
         printf("\n");
    }
    //int转char数组
    int2buff(a,buff);
    printf("%s","fen ge xian");
    printf("\n");
    for(i=0;i<20;i++){
         printf("%d",buff[i]);
         printf("\n");
    }
    //转换的开始位置 buff+sizeof(int)
    int2buff(12,buff+sizeof(int));
        printf("%s","fen ge xian");
    printf("\n");
    for(i=0;i<20;i++){
         printf("%d",buff[i]);
         printf("\n");
    }
}
