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
	
	// get size of bin
	struct stat sb;
	fstat(fd, &sb);

	// mmap!
 	char *head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);

	// read elf header part
	Elf_Ehdr *ehdr;
	ehdr = (Elf_Ehdr*)(head);

	// get head pointer of section header's section string section. 
	Elf_Shdr *shstr = (Elf_Shdr *)(head + ehdr->e_shoff + (ehdr->e_shstrndx * ehdr->e_shentsize)); // 

	// get each section
	printf("========:\n");
	printf("sections:\n");
	printf("========:\n");
	for(int i = 0; i < ehdr->e_shnum; i++) {
		// get each section's head
		Elf_Shdr *sec_hdr = (Elf_Shdr*)(head + ehdr->e_shoff + i * ehdr->e_shentsize);
		printf("%s\n",(char*)(head + shstr->sh_offset + sec_hdr->sh_name));
		// !! Wrong pattern
		// printf("%s\n", (char*)(shstr + sec_hdr->sh_name));
	}
	printf("-------\n");

	return 0;
}
