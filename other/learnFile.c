#include<stdio.h>

void testAccess(){
    int a = access("D:\\CUST\\work", 0);
    printf("%d",a);
}
