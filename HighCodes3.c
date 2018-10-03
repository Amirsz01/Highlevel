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
	puts (line);
}
void process_line( char buffer[] )
{
	char *buf_ptr;
	char c;
	int i = 0;
	int i_pol;
	int flag;
	flag = NO;
	buf_ptr = buffer;
	while( *buf_ptr != '\0' )
	{
		i++;
		buf_ptr++;
	}
	i_pol = (i-1)/2;
	while(i-- != i_pol-1)
	{
		*(buf_ptr+3) = *buf_ptr;
		buf_ptr--;
	}
	*++buf_ptr = 'A';
	*(buf_ptr+1) = '2';
	*(buf_ptr+2) = '7';
}