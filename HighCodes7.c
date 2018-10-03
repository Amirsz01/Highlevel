#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
	char line[MAXLINE];
	fgets(line,sizeof(line),stdin);
	process_line( line );
}
void process_line( char buffer[] )
{
	char *buf_ptr;
	char c;
	int i;
	int counter = 0;
	int flag;
	flag = NO;
	buf_ptr = buffer;
	do
	{
		c = *buf_ptr;
		if (flag)
		{
			if (c == 'c')
			{
				counter++;
				flag = NO;
			}
			if (c != 'b')
			{
				flag = NO;
			}
		}
		else
		{
			if(c == 'b')
			{
				flag = YES;
			}
		}
		buf_ptr++;
	}
	while( c != '\0' );
	printf("KOJL-BO = %d",counter);
}