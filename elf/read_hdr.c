#include<stdio.h>
#include<elf.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	printf("argc is %d, argv[1] is %s\n", argc, argv[1]);

	int fd = open(argv[1], 2);
	if (fd == -1) {
		printf("open err\n");
		return -1;
	}
	printf("open success!\n");
	
	// get size of bin
	struct stat sb;
	fstat(fd, &sb);

	// mmap!
 	char *head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	printf("head addr: %p\n", head);

	return 0;

}
