% readelf -a libsample.so.1
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 09 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - FreeBSD
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x4bc
  Start of program headers:          52 (bytes into file)
  Start of section headers:          2472 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         3
  Size of section headers:           40 (bytes)
  Number of section headers:         24
  Section header string table index: 21

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .hash             HASH            00000094 000094 0000d4 04   A  2   0  4
  [ 2] .dynsym           DYNSYM          00000168 000168 000220 10   A  3  15  4
  [ 3] .dynstr           STRTAB          00000388 000388 0000a5 00   A  0   0  1
  [ 4] .rel.data         REL             00000430 000430 000008 08   A  2   c  4
  [ 5] .rel.got          REL             00000438 000438 000020 08   A  2  11  4
  [ 6] .rel.plt          REL             00000458 000458 000018 08   A  2   8  4
  [ 7] .init             PROGBITS        00000470 000470 00000b 00  AX  0   0  4
  [ 8] .plt              PROGBITS        0000047c 00047c 000040 04  AX  0   0  4
  [ 9] .text             PROGBITS        000004bc 0004bc 000228 00  AX  0   0  4
  [10] .fini             PROGBITS        000006e4 0006e4 000006 00  AX  0   0  4
  [11] .rodata           PROGBITS        000006ea 0006ea 000077 00   A  0   0  1
  [12] .data             PROGBITS        00001764 000764 000010 00  WA  0   0  4
  [13] .eh_frame         PROGBITS        00001774 000774 000004 00  WA  0   0  4
  [14] .dynamic          DYNAMIC         00001778 000778 0000a8 08  WA  3   0  4
  [15] .ctors            PROGBITS        00001820 000820 000008 00  WA  0   0  4
  [16] .dtors            PROGBITS        00001828 000828 000008 00  WA  0   0  4
  [17] .got              PROGBITS        00001830 000830 000028 04  WA  0   0  4
  [18] .bss              NOBITS          00001858 000858 000020 00  WA  0   0  4
  [19] .comment          PROGBITS        00000000 000858 000078 00      0   0  1
  [20] .note             NOTE            00000000 0008d0 00003c 00      0   0  1
  [21] .shstrtab         STRTAB          00000000 00090c 00009c 00      0   0  1
  [22] .symtab           SYMTAB          00000000 000d68 0003f0 10     23  32  4
  [23] .strtab           STRTAB          00000000 001158 00019a 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x000000 0x00000000 0x00000000 0x00761 0x00761 R E 0x1000
  LOAD           0x000764 0x00001764 0x00001764 0x000f4 0x00114 RW  0x1000
  DYNAMIC        0x000778 0x00001778 0x00001778 0x000a8 0x000a8 RW  0x4

 Section to Segment mapping:
  Segment Sections...
   00     .hash .dynsym .dynstr .rel.data .rel.got .rel.plt .init .plt .text .fini .rodata 
   01     .data .eh_frame .dynamic .ctors .dtors .got .bss 
   02     .dynamic 

Dynamic segment at offset 0x778 contains 16 entries:
  Tag        Type                         Name/Value
 0x0000000e (SONAME)                     Library soname: [libsample.so.1]
 0x0000000c (INIT)                       0x470
 0x0000000d (FINI)                       0x6e4
 0x00000004 (HASH)                       0x94
 0x00000005 (STRTAB)                     0x388
 0x00000006 (SYMTAB)                     0x168
 0x0000000a (STRSZ)                      165 (bytes)
 0x0000000b (SYMENT)                     16 (bytes)
 0x00000003 (PLTGOT)                     0x1830
 0x00000002 (PLTRELSZ)                   24 (bytes)
 0x00000014 (PLTREL)                     REL
 0x00000017 (JMPREL)                     0x458
 0x00000011 (REL)                        0x430
 0x00000012 (RELSZ)                      40 (bytes)
 0x00000013 (RELENT)                     8 (bytes)
 0x00000000 (NULL)                       0x0

Relocation section '.rel.data' at offset 0x430 contains 1 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00001764  00000008 R_386_RELATIVE   

Relocation section '.rel.got' at offset 0x438 contains 4 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00001848  00001906 R_386_GLOB_DAT    0000176c   extvalue
0000184c  00001a06 R_386_GLOB_DAT    00000000   __deregister_frame_inf
00001850  00002006 R_386_GLOB_DAT    00001874   extbssvalue
00001854  00002106 R_386_GLOB_DAT    00000000   __register_frame_info

Relocation section '.rel.plt' at offset 0x458 contains 3 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0000183c  00001507 R_386_JUMP_SLOT   00000000   printf
00001840  00001a07 R_386_JUMP_SLOT   00000000   __deregister_frame_inf
00001844  00002107 R_386_JUMP_SLOT   00000000   __register_frame_info

There are no unwind sections in this file.

Symbol table '.dynsym' contains 34 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000094     0 SECTION LOCAL  DEFAULT    1 
     2: 00000168     0 SECTION LOCAL  DEFAULT    2 
     3: 00000388     0 SECTION LOCAL  DEFAULT    3 
     4: 00000430     0 SECTION LOCAL  DEFAULT    4 
     5: 00000438     0 SECTION LOCAL  DEFAULT    5 
     6: 00000458     0 SECTION LOCAL  DEFAULT    6 
     7: 00000470     0 SECTION LOCAL  DEFAULT    7 
     8: 0000047c     0 SECTION LOCAL  DEFAULT    8 
     9: 000004bc     0 SECTION LOCAL  DEFAULT    9 
    10: 000006e4     0 SECTION LOCAL  DEFAULT   10 
    11: 000006ea     0 SECTION LOCAL  DEFAULT   11 
    12: 00001764     0 SECTION LOCAL  DEFAULT   12 
    13: 00001774     0 SECTION LOCAL  DEFAULT   13 
    14: 00001778     0 SECTION LOCAL  DEFAULT   14 
    15: 00001820     0 SECTION LOCAL  DEFAULT   15 
    16: 00001828     0 SECTION LOCAL  DEFAULT   16 
    17: 00001830     0 SECTION LOCAL  DEFAULT   17 
    18: 00001858     0 SECTION LOCAL  DEFAULT   18 
    19: 00000000     0 SECTION LOCAL  DEFAULT   19 
    20: 00000000     0 SECTION LOCAL  DEFAULT   20 
    21: 00000000     0 NOTYPE  GLOBAL DEFAULT  UND printf
    22: 0000064c    73 FUNC    GLOBAL DEFAULT    9 extfunc
    23: 00001778     0 OBJECT  GLOBAL DEFAULT  ABS _DYNAMIC
    24: 00000470     0 FUNC    GLOBAL DEFAULT    7 _init
    25: 0000176c     4 OBJECT  GLOBAL DEFAULT   12 extvalue
    26: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __deregister_frame_info
    27: 00001858     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
    28: 000006e4     0 FUNC    GLOBAL DEFAULT   10 _fini
    29: 00001858     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
    30: 00001830     0 OBJECT  GLOBAL DEFAULT  ABS _GLOBAL_OFFSET_TABLE_
    31: 00001878     0 NOTYPE  GLOBAL DEFAULT  ABS _end
    32: 00001874     4 OBJECT  GLOBAL DEFAULT   18 extbssvalue
    33: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __register_frame_info

Symbol table '.symtab' contains 63 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000094     0 SECTION LOCAL  DEFAULT    1 
     2: 00000168     0 SECTION LOCAL  DEFAULT    2 
     3: 00000388     0 SECTION LOCAL  DEFAULT    3 
     4: 00000430     0 SECTION LOCAL  DEFAULT    4 
     5: 00000438     0 SECTION LOCAL  DEFAULT    5 
     6: 00000458     0 SECTION LOCAL  DEFAULT    6 
     7: 00000470     0 SECTION LOCAL  DEFAULT    7 
     8: 0000047c     0 SECTION LOCAL  DEFAULT    8 
     9: 000004bc     0 SECTION LOCAL  DEFAULT    9 
    10: 000006e4     0 SECTION LOCAL  DEFAULT   10 
    11: 000006ea     0 SECTION LOCAL  DEFAULT   11 
    12: 00001764     0 SECTION LOCAL  DEFAULT   12 
    13: 00001774     0 SECTION LOCAL  DEFAULT   13 
    14: 00001778     0 SECTION LOCAL  DEFAULT   14 
    15: 00001820     0 SECTION LOCAL  DEFAULT   15 
    16: 00001828     0 SECTION LOCAL  DEFAULT   16 
    17: 00001830     0 SECTION LOCAL  DEFAULT   17 
    18: 00001858     0 SECTION LOCAL  DEFAULT   18 
    19: 00000000     0 SECTION LOCAL  DEFAULT   19 
    20: 00000000     0 SECTION LOCAL  DEFAULT   20 
    21: 00000000     0 SECTION LOCAL  DEFAULT   21 
    22: 00000000     0 SECTION LOCAL  DEFAULT   22 
    23: 00000000     0 SECTION LOCAL  DEFAULT   23 
    24: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    25: 000004bc     0 NOTYPE  LOCAL  DEFAULT    9 gcc2_compiled.
    26: 00001764     0 OBJECT  LOCAL  DEFAULT   12 p.3
    27: 00001828     0 OBJECT  LOCAL  DEFAULT   16 __DTOR_LIST__
    28: 00001768     0 OBJECT  LOCAL  DEFAULT   12 completed.4
    29: 000004bc     0 FUNC    LOCAL  DEFAULT    9 __do_global_dtors_aux
    30: 00001774     0 OBJECT  LOCAL  DEFAULT   13 __EH_FRAME_BEGIN__
    31: 00000520     0 FUNC    LOCAL  DEFAULT    9 fini_dummy
    32: 00001858    24 OBJECT  LOCAL  DEFAULT   18 object.11
    33: 00000538     0 FUNC    LOCAL  DEFAULT    9 frame_dummy
    34: 00000570     0 FUNC    LOCAL  DEFAULT    9 init_dummy
    35: 0000176c     0 OBJECT  LOCAL  DEFAULT   12 force_to_data
    36: 00001820     0 OBJECT  LOCAL  DEFAULT   15 __CTOR_LIST__
    37: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    38: 00000698     0 NOTYPE  LOCAL  DEFAULT    9 gcc2_compiled.
    39: 00000698     0 FUNC    LOCAL  DEFAULT    9 __do_global_ctors_aux
    40: 00001824     0 OBJECT  LOCAL  DEFAULT   15 __CTOR_END__
    41: 000006cc     0 FUNC    LOCAL  DEFAULT    9 init_dummy
    42: 00001774     0 OBJECT  LOCAL  DEFAULT   12 force_to_data
    43: 0000182c     0 OBJECT  LOCAL  DEFAULT   16 __DTOR_END__
    44: 00001774     0 OBJECT  LOCAL  DEFAULT   13 __FRAME_END__
    45: 00000000     0 FILE    LOCAL  DEFAULT  ABS sample.c
    46: 00000588     0 NOTYPE  LOCAL  DEFAULT    9 gcc2_compiled.
    47: 00001770     4 OBJECT  LOCAL  DEFAULT   12 value
    48: 00000588   193 FUNC    LOCAL  DEFAULT    9 func
    49: 00001870     4 OBJECT  LOCAL  DEFAULT   18 bssvalue
    50: 00000000     0 NOTYPE  GLOBAL DEFAULT  UND printf
    51: 0000064c    73 FUNC    GLOBAL DEFAULT    9 extfunc
    52: 00001778     0 OBJECT  GLOBAL DEFAULT  ABS _DYNAMIC
    53: 00000470     0 FUNC    GLOBAL DEFAULT    7 _init
    54: 0000176c     4 OBJECT  GLOBAL DEFAULT   12 extvalue
    55: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __deregister_frame_info
    56: 00001858     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
    57: 000006e4     0 FUNC    GLOBAL DEFAULT   10 _fini
    58: 00001858     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
    59: 00001830     0 OBJECT  GLOBAL DEFAULT  ABS _GLOBAL_OFFSET_TABLE_
    60: 00001878     0 NOTYPE  GLOBAL DEFAULT  ABS _end
    61: 00001874     4 OBJECT  GLOBAL DEFAULT   18 extbssvalue
    62: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __register_frame_info

Histogram for bucket list length (total of 17 buckets):
 Length  Number     % of total  Coverage
      0  8          ( 47.1%)
      1  5          ( 29.4%)     38.5%
      2  4          ( 23.5%)    100.0%

No version information found in this file.
% 
