#include<stdio.h>
#include<stdbool.h>
#include<io.h>
#include<fcntl.h>
#include<unistd.h>

#define SPLIT_FILENAME_BODY(logic_filename, filename_len, true_filename, \
	store_path_index, check_path_index) \
	do \
	{ \
	char buff[3]; \
	char *pEnd; \
 \
	if (*filename_len <= 10) \
	{ \
		printf("ddddcccccddd"); \
		return -1; \
	} \
 \
	if (*logic_filename != 'M') \
	{ /* version < V1.12 */ \
		store_path_index = 0; \
		memcpy(true_filename, logic_filename, (*filename_len)+1); \
		break; \
	} \
 \
	if (*(logic_filename + 3) != '/') \
	{ \
		printf("ddddd");\
		return -1; \
	} \
 \
	*buff = *(logic_filename+1); \
	*(buff+1) = *(logic_filename+2); \
	*(buff+2) = '\0'; \
 \
	pEnd = NULL; \
	store_path_index = strtol(buff, &pEnd, 16); \
	if (pEnd != NULL && *pEnd != '\0') \
	{ \
		printf("eww");\
		return -1; \
	} \
 \
 printf("buff %s pEnd%s\n",buff,pEnd);\
	if (check_path_index && (store_path_index < 0 || \
		store_path_index >= 2)) \
	{ \
		printf("wwwwwqqq"); \
		return -1; \
	} \
 \
	*filename_len -= 4; \
	memcpy(true_filename, logic_filename + 4, (*filename_len) + 1); \
 \
	} while (0)

void testAccess(){
    int a = access("D:\\CUST\\work", 0);
    printf("%d",a);
}

void test01(){
    char logic_filename[] = "M00/CD/00/wKi0hVjqXGeAcyFfAAGSt-FxG-0872.jpg";
    int filename_len = 50 ;
    char true_filename[128];
    int store_path_index;
    int flag = storage_split_filename_ex(logic_filename,&filename_len,true_filename,&store_path_index);
    printf("%d\n",flag);
    printf("%s",true_filename);
    printf("%d",filename_len);
}

int storage_split_filename_ex(const char *logic_filename, \
		int *filename_len, char *true_filename, int *store_path_index)
{

	SPLIT_FILENAME_BODY(logic_filename, \
		filename_len, true_filename, *store_path_index, true);
	return 0;
}

void test02(){

      char dest[] = "sewesdtrhj6tkjhsagrjestw";
      int flag = 12;
      int dummies = 5;
      int dest_len = flag - dummies;
      *(dest + dest_len) = '\0';
      printf("%s",dest);
}

void readFile(){

    char buff[] = "qwertyuiopasdfghjkl";
    int fd = open("d:\\sql.sql",O_RDONLY);
    read(fd, buff, 15);
    printf("%s",buff);
}

void readLink(){
    static char buf[20];
    int i;
    //int rslt = readlink("d:\\sql.sql", buf, 20);
    printf("%s",buf);
}
