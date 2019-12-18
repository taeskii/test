#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int errno;

int main(int argc,char** argv){


	if(argc>1){
		int errnum;
		int e = open(argv[1],O_CREAT|O_EXCL,S_IRWXU|S_IRWXG|S_IRWXO);
		if(errno ==-1){
			fprintf(stderr,"value of errno: %d\n",errno);
			perror("Error printed by perror");
			fprintf(stderr,"Error opening file: %s\n", strerror(errno) );
		}
	}




	return 0;
}
