
ENTRY (__start)

MEMORY {
	flatmem : ORIGIN = 0x0, LENGTH = 0xfffffff
}

SECTIONS {

	.text 0x0 : {
		. = . + 4;
		. = ALIGN(0x4) ;
		__stext = . ;
		*(.text)
		*(.text.*)
		*(.gnu.warning)
		*(.stub)
		*(.gnu.linkonce.t*)
		*(.glue_7t)
		*(.glue_7)
		*(.jcr)
		KEEP (*(.init))
		KEEP (*(.fini))

W_RODAT		*(.rodata)
W_RODAT		*(.rodata1)
W_RODAT		*(.rodata.*)
W_RODAT		*(.gnu.linkonce.r*)

		/* This is special code area at the end of the normal
		   text section.  It contains a small lookup table at
		   the start followed by the code pointed to by entries
		   in the lookup table.  */
		. = ALIGN (4) ;
		PROVIDE(___ctbp = .);
		*(.call_table_data)
		*(.call_table_text)

		. = ALIGN(0x20) ;
		__etext = . ;
	} > flatmem

	.data : {
		. = ALIGN(0x4) ;
		__sdata = . ;
		___data_start = . ;
		_data_start = . ;
		*(.got.plt)
		*(.got)
		FILL(0) ;
		. = ALIGN(0x20) ;
		LONG(-1)
		. = ALIGN(0x20) ;
R_RODAT		*(.rodata)
R_RODAT		*(.rodata1)
R_RODAT		*(.rodata.*)
R_RODAT		*(.gnu.linkonce.r*)
		*(.data)
		*(.data1)
		*(.data.*)
		*(.gnu.linkonce.d*)

		/* Microblaze has .sdata and .sbss (small bss).  They must
		   be contiguous, so please don't move any of this. JW */
		__ssrw = . ;
		*(.sdata)
		*(.sdata.*)
		*(.sbss)			/* Don't move this! */
		*(.gnu.linkonce.sb*)
		__essrw = . ;

		__ssrw_size = __essrw - __ssrw;
		PROVIDE(__SDA_BASE_ = __ssrw + (__ssrw_size / 2));

		*(.gnu.linkonce.s.*)
		*(__libc_atexit)
		*(__libc_subinit)
		*(__libc_subfreeres)
		*(.note.ABI-tag)

		/* microblaze-specific read-only small data area
		   and associated locating symbols */
		__ssro = . ;
		*(.sdata2)
		__essro = . ;
		__ssro_size = __essro - __ssro;
		PROVIDE(__SDA2_BASE_ = __ssro + (__ssro_size / 2));

		. = ALIGN(4) ;
SINGLE_LINK:	/* gcc uses crtbegin.o to find the start of
SINGLE_LINK:	   the constructors, so we make sure it is
SINGLE_LINK:	   first.  Because this is a wildcard, it
SINGLE_LINK:	   doesn't matter if the user does not
SINGLE_LINK:	   actually link against crtbegin.o; the
SINGLE_LINK:	   linker won't look for a file to match a
SINGLE_LINK:	   wildcard.  The wildcard also means that it
SINGLE_LINK:	   doesn't matter which directory crtbegin.o
SINGLE_LINK:	   is in.  */
SINGLE_LINK:	KEEP (*crtbegin*.o(.ctors))
SINGLE_LINK:	/* We don't want to include the .ctor section from
SINGLE_LINK:	   from the crtend.o file until after the sorted ctors.
SINGLE_LINK:	   The .ctor section from the crtend file contains the
SINGLE_LINK:	   end of ctors marker and it must be last */
SINGLE_LINK:	KEEP (*(EXCLUDE_FILE (*crtend*.o ) .ctors))
SINGLE_LINK:	KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
SINGLE_LINK:	KEEP (*crtbegin*.o(.dtors))
SINGLE_LINK:	KEEP (*(EXCLUDE_FILE (*crtend*.o ) .dtors))
SINGLE_LINK:	KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))

		PROVIDE (___preinit_array_start = .);
		KEEP (*(.preinit_array))
		PROVIDE (___preinit_array_end = .);

		PROVIDE (___init_array_start = .);
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array))
		PROVIDE (___init_array_end = .);

		PROVIDE (___fini_array_start = .);
		KEEP (*(.fini_array))
		KEEP (*(SORT(.fini_array.*)))
		PROVIDE (___fini_array_end = .);
	} > flatmem

	.eh_frame_hdr : { *(.eh_frame_hdr) } > flatmem
	.eh_frame : { KEEP(*(.eh_frame)) } > flatmem
	.gcc_except_table : {
		KEEP(*(.gcc_except_table))
		KEEP(*(.gcc_except_table.*))
	} >flatmem

	. = ALIGN(0x10) ;
	__edata = . ;
 
	.bss : {
		. = ALIGN(0x4) ;
		__sbss = ALIGN(0x4) ;
		___bss_start = . ;
		*(.dynsbss)
		*(.sbss)
		*(.sbss.*)
		*(.scommon)
		*(.dynbss)
		*(.bss)
		*(.bss.*)
		*(.bss*)
		*(.gnu.linkonce.b*)
		*(COMMON)
		. = ALIGN(0x10) ;
		__ebss = . ;
		__end = . ;
		_end = . ;
	} > flatmem

	.stack : {
		. = ALIGN(0x4);
		__stack_start = .;
	}

	.junk 0 : { *(.rel*) *(.rela*) }
	/DISCARD/ : { *(.note.GNU-stack) }
	/* Stabs debugging sections.    */
	.stab 0 : { *(.stab) }
	.stabstr 0 : { *(.stabstr) }
	.stab.excl 0 : { *(.stab.excl) }
	.stab.exclstr 0 : { *(.stab.exclstr) }
	.stab.index 0 : { *(.stab.index) }
	.stab.indexstr 0 : { *(.stab.indexstr) }
	.comment 0 : { *(.comment) }
	/* DWARF debug sections.
	   Symbols in the DWARF debugging sections are relative to the beginning
	   of the section so we begin them at 0.  */
	/* DWARF 1 */
	.debug          0 : { *(.debug) }
	.line           0 : { *(.line) }
	/* GNU DWARF 1 extensions */
	.debug_srcinfo  0 : { *(.debug_srcinfo) }
	.debug_sfnames  0 : { *(.debug_sfnames) }
	/* DWARF 1.1 and DWARF 2 */
	.debug_aranges  0 : { *(.debug_aranges) }
	.debug_pubnames 0 : { *(.debug_pubnames) }
	/* DWARF 2 */
	.debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
	.debug_abbrev   0 : { *(.debug_abbrev) }
	.debug_line     0 : { *(.debug_line) }
	.debug_frame    0 : { *(.debug_frame) }
	.debug_str      0 : { *(.debug_str) }
	.debug_loc      0 : { *(.debug_loc) }
	.debug_macinfo  0 : { *(.debug_macinfo) }
	/* SGI/MIPS DWARF 2 extensions */
	.debug_weaknames 0 : { *(.debug_weaknames) }
	.debug_funcnames 0 : { *(.debug_funcnames) }
	.debug_typenames 0 : { *(.debug_typenames) }
	.debug_varnames  0 : { *(.debug_varnames) }
}
