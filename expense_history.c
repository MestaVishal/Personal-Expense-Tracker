#include <expense_header.h>

void today_expense( void ) 
{
	
	date temp_date ;
	
	today( &temp_date ) ;
	
	char *file_name = name( temp_date ) ;
	
	FILE *fp = fopen( file_name , "r" ) ;
	
	if( fp == NULL )
	{
		printf( "\n\033[1;31mSorry...No records found\n" ) ;
		
		char temp = 0 ;
		
		printf( "\n\n\033[1;34mPress \033[1;31mx \033[1;34mkey to exit to main menu\033[1;31m\n" ) ;
	
		while( temp != 'x' )
		{
			scanf( "%*c%c" , &temp ) ; 
		}
		
		return ;
	}
	
	any_date_detail( temp_date , fp ) ;

	free( file_name ) ;
	
	fclose( fp ) ;
	
	printf( "\n\033[1;34mPress \033[1;31mx \033[1;34mkey to exit to main menu\033[1;31m\n" ) ;
	
	char temp = 0 ;
	
	while( temp != 'x' )
	{
		scanf( "%*c%c" , &temp ) ; 
	}
}	


void any_month( void )
{

	system( "clear" ) ;
	
	FILE *fp = NULL ;
	
	char *file_name = NULL ;
	
	date temp_date = { 1 , 1, 2023 };
	
	int repeat_flag = 0 ;
	
	for( int i = 2023 ; i <= 2025 ; i++ )
	{
		temp_date.year = i ;
		
		repeat_flag = 0 ;
		
		for( int j = 1 ; j <= 12 ; j++ )
		{
			temp_date.month = j ;
			
			file_name = name( temp_date ) ;

			FILE *fp = fopen( file_name , "r" ) ;
			
			if( fp != NULL )
			{
				if( repeat_flag == 0 )
				{
					printf( "\033[1;34mRecord of following months for Year : \033[1;33m%d \033[1;34mare avaivale\033[1;0m\n" , i ) ;
				}
				
				repeat_flag = 1 ;
				
				printf( "\033[1;32m%s\t" , file_name ) ;
				
				fclose( fp ) ;	
			}
			
			free( file_name ) ;
		}
		
		printf( "\n" ) ;
	}
	
	printf( "\n\033[1;34mEnter name of the month in the format month year \033[1;32m( e.g. 1 2023 for Jan 2023 )\033[1;34m to view expenses\033[1;32m\n" ) ;
	
	scanf( "%d%d" , &temp_date.month , &temp_date.year ) ;
	
	while( ( temp_date.month < 1 || temp_date.month > 12 ) || ( temp_date.year < 2023 || temp_date.year > 2100 ) )
	{
		printf( "\n\033[1;31mInvalid input. Enter month and year whose record is present\n\033[1;0m" ) ;
		
		scanf( "%d%d" , &temp_date.month , &temp_date.year ) ;
	}
	
	
	file_name = name( temp_date ) ;
	
	fp = fopen( file_name , "r" ) ;
	
	if( fp == NULL )
	{
		printf( "\n\033[1;31mSorry...No records found\n" ) ;
		
		char temp = 0 ;
		
		printf( "\n\n\033[1;34mPress \033[1;31mx \033[1;34mkey to exit to main menu\033[1;31m\n" ) ;
	
		while( temp != 'x' )
		{
			scanf( "%*c%c" , &temp ) ; 
		}
		
		return ;
	}
	
	month_expense( temp_date , fp ) ;

	free( file_name ) ;
	
	fclose( fp ) ;	
	
}

void current_month( void ) 
{

	date temp_date ;
	
	today( &temp_date ) ;
	
	char *file_name = name( temp_date ) ;
	
	FILE *fp = fopen( file_name , "r" ) ;
	
	if( fp == NULL )
	{
		printf( "\n\033[1;31mSorry...No records found\n" ) ;
		
		char temp = 0 ;
		
		printf( "\n\n\033[1;34mPress \033[1;31mx \033[1;34mkey to exit to main menu\033[1;31m\n" ) ;
	
		while( temp != 'x' )
		{
			scanf( "%*c%c" , &temp ) ; 
		}
		
		return ;
	}
	
	month_expense( temp_date , fp ) ;

	free( file_name ) ;
	
	fclose( fp ) ;	
	
}			


void expense_history( void )
{

	int choice = 0 ;
	
	do
	{
		printf( "\n\033[1;34mWhich expense history would you like to view?\n" ) ;
	
		printf( "\033[1;0mEnter \033[1;36m1 \033[1;0m: \033[1;33mToday's\n" ) ;

		printf( "\033[1;0mEnter \033[1;36m2 \033[1;0m: \033[1;33mCurrent month's\n" ) ;

		printf( "\033[1;0mEnter \033[1;36m3 \033[1;0m: \033[1;33mMonth of choice\n" ) ;
		
		printf( "\n\033[1;34mEnter your choice\n\033[1;0m" ) ;
		
		scanf( "%d" , &choice ) ;
		
		switch( choice )
		{
			case 1 : today_expense() ;
			
				 break ;
				 
			case 2 : current_month() ;
			
				 break ;
				 
			case 3 : any_month() ;
			
				 break ;
				 
			default : printf( "\n\033[1;31mInvalid choice. Please enter valid choice\n\n\033[1;0m" ) ; 
			
				  choice  = 0 ;
				  
		}
	
	}while( choice == 0 ) ;		 
}
