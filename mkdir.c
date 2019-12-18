#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main(int argc,char** argv){


	if(argc>1){
		int errnum;
		int e = mkdir(argv[1],S_IRWXU|S_IRWXG|S_IRWXO);
		if(errno !=0){
			fprintf(stderr,"value of errno: %d\n",errno);
			perror("Error printed by perror");
			fprintf(stderr,"Error opening file: %s\n", strerror(errno) );
		}
	}




	return 0;
}
