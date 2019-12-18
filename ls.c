#include <dirent.h>     /* Defines DT_* constants */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <string.h>



struct linux_dirent {
	long d_ino;
	off_t d_off;
	unsigned short d_reclen;
	char d_name[];
};

#define size 1024
char buf[size];

int main(int argc,char** argv){

	struct linux_dirent *d;
	int fd = openat(AT_FDCWD, ".", O_RDONLY|O_NONBLOCK|O_DIRECTORY|O_CLOEXEC);
	if(fd == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	int cnt = syscall(SYS_getdents,fd,buf,size);
	if(cnt!=0){
		int bpos;
		for(bpos = 0; bpos<cnt ;){
			d = (struct linux_dirent *) (buf+bpos);
			//d_type = *(buf + bpos + d->d_reclen - 1);
			write(1,d->d_name,strlen(d->d_name));
			bpos += d->d_reclen;
		}
}
	close(fd);
	return 0;
}



