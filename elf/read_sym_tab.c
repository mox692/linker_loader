#include<stdio.h>
#include<sys/stat.h>
#include<errno.h>
#include<elf.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>

typedef struct {
	int section_offset;
	int section_size;
} ret_getSectionOff;

//
// read elf's symbol table, and pritnt all symbol name.
//

// Return input section's offset(int) from file head.
// If given section doesn't exist, will return -1.
ret_getSectionOff getSectionOff(char *section_name, char *head) {
	ret_getSectionOff ret;
	// reach file's section header table.
	Elf_Ehdr *e_header;
	e_header = (Elf_Ehdr*)(head);

	// debug
	printf("num of section: %d\n", e_header->e_shnum);
	printf("str section index: %d\n", e_header->e_shstrndx);
	printf("section header start addr: %lu\n", e_header->e_shoff);

	int section_str_index = e_header->e_shstrndx;
	int sec_header_table_head = e_header->e_shoff;
	int sec_name_section_index = e_header->e_shstrndx;
	int shstrtab_section_offset;
	
	typedef struct {
		int key;   // str_offset
		int value; // sh_offset
		int size;
	} offset_map;
	offset_map m[e_header->e_shnum];

	// watch all section to get sh_name field.
	for(int i = 0; i < e_header->e_shnum; i++) {
		char *current_head = (char*)(head + sec_header_table_head + (i * sizeof(Elf_Shdr)));
		printf("index: %d, current_head: %p\n" ,i, current_head);

		Elf_Shdr *e_shdr = (Elf_Shdr*)(current_head);
		m[i].key = e_shdr->sh_name;
		m[i].value = e_shdr->sh_offset;
		m[i].size = e_shdr->sh_size;

		if(i == section_str_index) {
			// get shstrtab section's offset
			shstrtab_section_offset = e_shdr->sh_offset;
		}
	}

	// debug
	printf("\n");
	for (int i = 0; i < e_header->e_shnum; i++) {
		printf("m[%d].key = %d, m[%d].value = %d\n", i, m[i].key, i, m[i].value);
	}
	printf("strIndex: %d\n", sec_name_section_index);
	printf("shstrtab_section_offset: %d\n",shstrtab_section_offset);

	char *shstrtab_section_head = (char*)(head + shstrtab_section_offset);
	printf("shstrtab_srction_head: %p\n", shstrtab_section_head);
	for (int i = 0; i < e_header->e_shnum; i++) {
		// TODO: over 100 char sec name.
		char bin_section_name[100];
		strcpy(bin_section_name, shstrtab_section_head + m[i].key);
			
		printf("section name: %s\n", bin_section_name);
		// MEMO: if we permit i == 0 condition, 
		// strstr sometimes success unexpectedly (caused by white space?)
		if(strstr(bin_section_name, section_name) != NULL && i != 0) {
			printf("match to %s!!, m[%d].value = %d\n", bin_section_name, i, m[i].value);
			ret.section_offset = m[i].value;
			ret.section_size = m[i].size;

			return ret;
		}
	}
	ret.section_offset = -1;
	return ret;
}

int main(int argc, char *argv[]) {
	printf("argc is %d, argv[1] is %s\n", argc, argv[1]);

	// open file
	int fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		printf("open err: %s\n", strerror(errno));
		return -1;
	}

	// get file size for mmap.
	struct stat sb;
	if(fstat(fd, &sb) == -1) {
		printf("fstat err: %s\n", strerror(errno));
		return -1;
	}

	// map binfile to memory by mmap.
	char *head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if(head == MAP_FAILED) {
		printf("mmap err: %s\n", strerror(errno));
		return -1;
	}

	// access .symtab section
	char *secstr = ".strtab";
	// section_data contain section's offset and size.
	ret_getSectionOff section_data = getSectionOff(secstr, head);
	if(section_data.section_offset == -1) {
		printf("cannot find given section, %s", secstr);
		return -1;
	}

	// debug
	printf("section_data.section_offset: %d, section_data.section_size: %d\n",section_data.section_offset, section_data.section_size);
	
	// read .symtab section
	for(int i = 0; i < section_data.section_size + 30; i++) {
		printf("%s", (char*)(head + section_data.section_offset + i));
	}

	return 0;
}
