#ifndef VIDEO_H
#define VIDEO_H

#define MAIL_READ     0x2000B880
#define MAIL_POLL     0x2000B890
#define MAIL_SENDER   0x2000B894
#define MAIL_STATUS   0x2000B898
#define MAIL_CONFIG   0x2000B89C
#define MAIL_WRITE    0x2000B8A0

typedef struct framebuffer_info
{
	unsigned int width;
	unsigned int height;
	unsigned int vWidth;
	unsigned int vHeight;
	unsigned int pitch;
	unsigned int depth;
	unsigned int xOffset;
	unsigned int yOffset;
	unsigned int framebuffer;
	unsigned int framebuffer_size;
} framebuffer_info_t;

void *       video_init( unsigned int width, unsigned int height );
int          video_write( unsigned int channel, unsigned int data );
unsigned int video_read( unsigned int channel );
unsigned int video_peek( unsigned int channel );
unsigned int video_status();

#endif
