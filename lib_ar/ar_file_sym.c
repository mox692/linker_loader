#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/mman.h>
#include<ar.h>

// read_each_obj_name reads char from given start address to `/` charactor,
// which indicate the end position of obj's name, 
// and will return the number of reading bytes.
int read_each_obj_name(char* pos) {
	int offset = 0;
	for(;;) {
		if(*pos == '/') {
			printf("will return %d\n", offset);
			return offset;
		}
		if(*pos == '\0') {
			printf("not found...\n");
			return -1;
		}
		offset++;
		pos++;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		printf("open err: %s\n", strerror(errno));
		return -1;
	}

	struct stat sb;
	if(fstat(fd, &sb) == -1) {
		printf("fstat err; %s\n", strerror(errno));
		return -1;
	}

	void* v_head = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (v_head == (void*)(-1)) {
		printf("mmap err: %s\n", strerror(errno));
		return -1;
	}

	printf("file size; %lu\n", sb.st_size);

	// check ar magic
	if(strncmp(v_head, ARMAG, 8) != 0) {
		printf("input file %s is not ar file.\n", argv[1]);
		return -1;
	}

	// move head to after magic
	v_head += 8;

	char* ar_header = (char*)(v_head);
	int count = 0;
	do {
		int offset = read_each_obj_name((char*)ar_header);
		char buf[offset];
		ar_header = stpncpy(buf, ar_header, offset + 1);
		printf("name: %s\n", buf);
		count++;
	}while(count < 3);

	return 0;
}
