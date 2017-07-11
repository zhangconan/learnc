#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void testSplit(){

    const char *pPort;
    const char *pIpAndPort;
    int port;
    pIpAndPort = "127.0.0.1:8001";
    //·Ö¸î×Ö·û´®
    pPort = strchr(pIpAndPort, ':');
    //snprintf(pPort,(int)(pPort - pIpAndPort), pIpAndPort);

    //printf("str=%s\n", pPort);
    //½ØÈ¡×Ö·û´®
    port = atoi(pPort+1);
    printf("str=%d\n",port);
}
