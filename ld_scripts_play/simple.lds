/* 
simple linker script.
The binary made by this script have sections,
that is all writeable.
*/

SECTIONS
{
	. = 0x08048000 + SIZEOF_HEADERS;
	.text= : { *(.text) 	}
	.data= : { *(.data) *(.rodata)}
	.bss= : { *(.bss) 	}
}
