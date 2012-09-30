#include<stdio.h>

typedef struct TIFF_head
{
	short byte_order;
	short version;
	int offset_to_ifd;
		
}TIFF_HEAD;

typedef struct header
{
	short lsb;
	long  bits_per_pixel;
  	long  image_length;
	long  image_width;
	long  strip_offset;
}header;

int main()
{
	FILE *fp;
//	TIFF_HEAD head;
	header head;	

	fp=fopen("temp.tiff","rb");

	if(fp==NULL)
	{
		printf("\nError: opening file");
		return 1;
	}


	fread(&head,1,sizeof(head),fp);

	

	printf("\nVersion:%x",head.lsb);
	printf("\nByte_order:%x",head.bits_per_pixel);
	printf("\nOffset to IFD:%x",head.image_length);
	printf("\nwidth: %x",head.image_width);
	printf("\noffset:%x",head.strip_offset);



	fclose(fp);
	return 0;
}
