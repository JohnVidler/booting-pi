#include "video.h"

void * video_init( unsigned int width, unsigned int height )
{
	framebuffer_info_t info;
	info.width            = width;
	info.height           = height;
	info.vWidth           = info.width;
	info.vHeight          = info.height;
	info.pitch            = 0;
	info.depth            = 16;
	info.xOffset          = 0;
	info.yOffset          = 0;
	info.framebuffer      = 0;
	info.framebuffer_size = 0;

	video_write( 1, (unsigned int)&info );  // Write the framebuffer info structure to mailbox 1
	if( video_read( 1 ) != 0 )
		return 0;

	if( info.framebuffer == 0 )
		return 0;

	return (void *)info.framebuffer;
}

int video_write( unsigned int channel, unsigned int data )
{
	unsigned int * mailbox = (unsigned int *)MAIL_WRITE;

	while( (video_status() & 0x80000000) != 0 ) { /* spin */ }  // Wait on bit 31

	*mailbox = (channel & 0xf) | (data << 4);

	return 0;
}

unsigned int video_read( unsigned int channel )
{
	unsigned int * mailbox = (unsigned int *)MAIL_READ;
	unsigned int data = 0;
	do
	{
		while( (video_status() & 0x40000000) != 0 ) { /* spin */ }  // Wait on bit 30
		data = *mailbox;
	}
	while( (data & (channel & 0xf)) != (channel & 0xf) );
	return data;
}

unsigned int video_peek( unsigned int channel )
{
	return 0;
}

unsigned int video_status()
{
	unsigned int * status = (unsigned int *)MAIL_STATUS;

	return *status;
}
