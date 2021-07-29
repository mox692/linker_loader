#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<a.out.h>
#define BUF_SIZE 512

char buf[BUF_SIZE];
struct exec aout;

int main(int argc, char* argv[]){
	printf("%d, %s\n", argc, argv[1]);

	int fd = open(argv[1], 2);
	if(fd == -1) {
		printf("fail\n");
		return -1;
	}

	if(read(fd, &buf, sizeof(aout)) == -1) {
		printf("read err\n");
		return -1;
	}

	printf("suc: size is %lu\nprint is %s\n", sizeof(aout), buf);
	close(fd);

}
