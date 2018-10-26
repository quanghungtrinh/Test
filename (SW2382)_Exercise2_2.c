#include <stdio.h>
#include <string.h>

int my_strlen(char* data) {
	int count;
	count = strlen(data);
	return count;
}



void main() { 
	char *strdata = "This is a test";    
	int leng;    
	leng = my_strlen(strdata);    
	printf("%d\n", leng); 
}