#include<stdio.h>
#include<fcntl.h>
#include<elf.h>
#include<unistd.h>
#define E_IDENT_SIZE 4

// AIM: read Elf64_Ehd's e_type field to check input file is ELF format.

// ELF file starts with this magic number.
char ELF_MAGIC[4] = {0x7f, 'E', 'L', 'F'};


int main(int argc, char* argv[]){
	printf("argc %d, argv[1] is %s\n", argc, argv[1]);

	int fd = open(argv[1], 2);

	if(fd == -1) {
		printf("err open file\n");
		return -1;
	}

	Elf64_Ehdr elf;
	char buf[E_IDENT_SIZE];

	if(read(fd, &buf, sizeof(elf.e_ident)) == -1) {
		printf("read err \n");
		return -1;
	}

	int eval = 0;
	for(int i = 0; i < sizeof(ELF_MAGIC); i++) {
		eval |= !(buf[i] == ELF_MAGIC[i]);
	}

	if(eval != 0) {
		printf("This file is not ELF\n");
		return 0;
	}

	printf("This file is ELF!!\n");
	return 0;
}


