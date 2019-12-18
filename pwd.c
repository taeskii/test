#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define size 4096
char buffer[size];

int main(int argc, char** argv)
{
	char* p = getcwd(buffer,size);
	if(p!=NULL){
		strcat(buffer,"\n");
	  	write(1,buffer,size);
	}

	return 0;
}
