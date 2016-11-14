/*
 * pANS stdio -- ftell
 */
#include "iolib.h"
long ftell(FILE *f){
	long seekp=seek(f->fd, 0, SEEK_CUR);
	if(seekp<0) return -1;		/* enter error state? */
	switch(f->state){
	default:
		return seekp;
	case RD:
		return seekp-(f->wp-f->rp);
	case WR:
		return (f->flags&LINEBUF?f->lp:f->wp)-f->buf+seekp;
	}
}
