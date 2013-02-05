#include "iops.h"
#include "video.h"

int bootmain ( void )
{
	unsigned int off;
	unsigned int pixel = 0;
	unsigned int * framebuffer = 0;
	
	while( (framebuffer = (unsigned int *)video_init( 1024, 768 )) == 0 ) { /* spin until we get a buffer */ } 
	
	for(;;)
	{
		for( off = 0; off < 1024*768; off++ )
			*(framebuffer+off) = pixel;
		pixel++;

	}

	return(0);
}
