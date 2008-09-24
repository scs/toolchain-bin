#ifndef _BLACKFIN_PAGE_H
#define _BLACKFIN_PAGE_H

/* PAGE_SHIFT determines the page size */

#define PAGE_SHIFT	12
#ifdef __ASSEMBLY__
#define PAGE_SIZE	(1 << PAGE_SHIFT)
#else
#define PAGE_SIZE	(1UL << PAGE_SHIFT)
#endif
#define PAGE_MASK	(~(PAGE_SIZE-1))


#endif				/* _BLACKFIN_PAGE_H */
