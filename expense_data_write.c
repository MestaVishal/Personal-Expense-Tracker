#include "expense_header.h"

void add_expense( void )
{
	category expense ;
	
	float amount = 0 ;
	
	memset( &expense , 0 , sizeof( expense ) ) ;
	
	int choice = 0 ;
	
	do
	{	
		printf( "\n\033[1;34mChoose a category:\n" ) ;
	
		printf( "\033[1;0mEnter \033[1;36m1 \033[1;0mto select: \033[1;33mHousing\n" ) ;

		printf( "\033[1;0mEnter \033[1;36m2 \033[1;0mto select: \033[1;33mTransport\n" ) ;

		printf( "\033[1;0mEnter \033[1;36m3 \033[1;0mto select: \033[1;33mGroceries\n" ) ;
		
		printf( "\033[1;0mEnter \033[1;36m4 \033[1;0mto select: \033[1;33mFood\n" ) ;
		
		printf( "\033[1;0mEnter \033[1;36m5 \033[1;0mto select: \033[1;33mHealth\n" ) ;
		
		printf( "\033[1;0mEnter \033[1;36m6 \033[1;0mto select: \033[1;33mLifestyle\n" ) ;
		
		printf( "\033[1;0mEnter \033[1;36m7 \033[1;0mto select: \033[1;33mObligation\n" ) ;
		
		printf( "\033[1;0mEnter \033[1;36m8 \033[1;0mto select: \033[1;33mOther\n" ) ;
		
		printf( "\n\033[1;34mEnter your choice\n\033[1;0m" ) ;
		
		scanf( "%d" , &choice ) ;
		
		if( choice >= 1 && choice <= 8 ) 
		{
			printf( "\033[1;34mEnter the amount\n\033[1;0m" ) ;
			
			scanf( "%f" , &amount ) ;
		}
		
		switch( choice )
		{
			case 1 : expense.housing = amount ;
				 
				 break ;
			
			case 2 : expense.transport = amount ;
			
				 break ;
			
			case 3 : expense.grocery = amount ;
			
				 break ;

			case 4 : expense.food = amount ;
			
				 break ;

			case 5 : expense.health = amount ;
			
				 break ;

			case 6 : expense.lifestyle = amount ;
			
				 break ;

			case 7 : expense.obligation = amount ;
			
				 break ;

			case 8 : expense.other = amount ;
				 
				 break ;
			
			default : printf( "\n\033[1;31mInvalid choice. Please enter valid choice\n\n\033[1;0m" ) ;
			
				  choice = 0 ;	  
		}
		
	}while( choice == 0 ) ;
	
	printf( "\n\033[1;34mWould you like to add description? Enter \033[1;31my \033[1;34mto add or press any other key to ignore\n\033[1;0m" ) ;
	
	char ch ;
	
	scanf( "%*c%c" , &ch ) ;
	
	if( ch == 'y' )
	{
	
		printf( "\n\033[1;34mEnter description\n\033[1;0m" ) ;
		
		scanf( "%*c" ) ;
		
		fgets( expense.remark , 50 , stdin ) ;

	}
	
	else
	{
		strcpy( expense.remark , "\n" ) ;
	}
	
	today( &expense.temp_date ) ;
	
	char *file_name = name( expense.temp_date ) ;
	
	FILE *fp = fopen( file_name , "a+" ) ;
	
	fprintf( fp , "%d-%d-%d %1.2f %1.2f %1.2f %1.2f %1.2f %1.2f %1.2f %1.2f %s" , expense.temp_date.day , expense.temp_date.month , expense.temp_date.year , expense.housing ,expense.transport , expense.grocery , expense.food , expense.health , expense.lifestyle , expense.obligation , expense.other , expense.remark ) ;
	
	free( file_name ) ;
	
	fclose( fp ) ;
	
	printf( "\n" ) ;

}	

