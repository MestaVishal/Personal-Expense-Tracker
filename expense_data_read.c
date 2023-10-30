#include "expense_header.h"

void any_date_detail( date current_date , FILE *fp )
{
	category expense , f;
	
	memset( &expense , 0 , sizeof( expense ) ) ;
	
	memset( &f , 0 , sizeof( f ) ) ;
		
	printf( "\n\033[1;31m%s : \033[1;0m%d-%d-%d\n" , "DATE" , current_date.day , current_date.month , current_date.year ) ;
	
	printf( "\n\033[1;31m%-13s%-12s%-12s%-12s%-11s%-11s%-12s%-13s%-11s%s\033[1;0m\n" , " " , "HOUSING" , "TRANSPORT" , "GROCERIES" , "FOOD" , "HEALTH" , "LIFESTYLE" , "OBLIGATION" , "OTHER" , "REMARK" ) ;

	while( fscanf( fp , "%d-%d-%d %f %f %f %f %f %f %f %f %[^\n]s" , &f.temp_date.day , &f.temp_date.month , &f.temp_date.year , &f.housing , &f.transport , &f.grocery , &f.food , &f.health , &f.lifestyle , &f.obligation , &f.other , f.remark ) != EOF ) 
	{
		if( current_date.day == f.temp_date.day && current_date.month == f.temp_date.month && f.temp_date.year == current_date.year )
		{
			printf( "%-13s%-12.2f%-12.2f%-12.2f%-11.2f%-11.2f%-12.2f%-13.2f%-11.2f%s\n" , " " , f.housing , f.transport , f.grocery , f.food , f.health , f.lifestyle , f.obligation , f.other , f.remark ) ;
			
			expense.housing += f.housing ;
			
			expense.transport += f.transport ;
			
			expense.grocery += f.grocery ;
			
			expense.food += f.food ;			

			expense.health += f.health ;
			
			expense.lifestyle += f.lifestyle ;
			
			expense.obligation += f.obligation ;
			
			expense.other += f.other ;
			
			memset( f.remark , 0 , 50 ) ;
		}
	}	
	
	float total = expense.housing + expense.transport + expense.grocery + expense.food + expense.health + expense.lifestyle + expense.obligation + expense.other ;
		
	printf( "\n\033[1;31m%-13s\033[1;32m%-12.2f%-12.2f%-12.2f%-11.2f%-11.2f%-12.2f%-13.2f%-11.2f\033[1;0m\n" , "TOTAL" , expense.housing , expense.transport , expense.grocery , expense.food , expense.health , expense.lifestyle , expense.obligation , expense.other ) ;
	
	printf( "\n\033[1;31mCUMMULATIVE TOTAL : \033[1;0m%1.2f\n" , total ) ;	
		
}


void month_expense( date temp_date , FILE *fp )
{
		
	int repeat_flag = 0 ;
	
	char temp = 0 ;
	
	do{
	
		system( "clear" ) ;
	
		printf( "\n\033[1;32m%-13s%-12s%-12s%-12s%-11s%-11s%-12s%-13s%-11s\033[1;36m%s\033[1;0m\n" , "DATE" , "HOUSING" , "TRANSPORT" , "GROCERIES" , "FOOD" , "HEALTH" , "LIFESTYLE" , "OBLIGATION" , "OTHER" , "TOTAL" ) ;
	
		char which_month[ 10 ] ;
	
		int days = days_month( temp_date , which_month ) ;
	
		category expense ;
	
		memset( &expense , 0 , sizeof( expense ) ) ;
	
		for( int i = 1 ; i <= days ; i++ )
		{
			fseek( fp , 0 , SEEK_SET ) ;
			
			temp_date.day = i ;
		
			category temp_expense = any_date( temp_date , fp ) ;
		
			expense.housing += temp_expense.housing ;
			
			expense.transport += temp_expense.transport ;
			
			expense.grocery += temp_expense.grocery ;
			
			expense.food += temp_expense.food ;			

			expense.health += temp_expense.health ;
			
			expense.lifestyle += temp_expense.lifestyle ;
			
			expense.obligation += temp_expense.obligation ;
			
			expense.other += temp_expense.other ;			
		}

		float total = expense.housing + expense.transport + expense.grocery + expense.food + expense.health + expense.lifestyle + expense.obligation + expense.other ;

		printf( "\n\033[1;31m%-13s\033[1;32m%-12.2f%-12.2f%-12.2f%-11.2f%-11.2f%-12.2f%-13.2f%-11.2f\033[1;36m%1.2f\033[1;0m\n" , "TOTAL" , expense.housing , expense.transport , expense.grocery , expense.food , expense.health , expense.lifestyle , expense.obligation , expense.other , total ) ;
	
		printf( "\n\033[1;31mCUMMULATIVE TOTAL OF %s : \033[1;0m%1.2f\n" , which_month , total ) ;
		
	
		if( repeat_flag == 0 )
		{

			printf( "\n\n\033[1;34mDo you wish to view details of expenditure of any particular day of the month?\n" ) ;
	
			printf( "\033[1;34mPress \033[1;32my \033[1;34mfor \033[1;32mYES \033[1;34mor \033[1;31many other key \033[1;34mfor \033[1;31mNO\n" ) ;
			
			scanf( "%*c%c" , &temp ) ;
	
			if( temp == 'y' ) 
			{
				repeat_flag = 1 ;
			}
		}
	
		if( temp == 'y' )
		{
			printf( "\n\033[1;34mEnter valid day\033[1;0m\n" ) ;
		
			scanf( "%d" , &temp_date.day ) ; 
		
			while( temp_date.day < 1 || temp_date.day > days )
			{
				printf( "\n\033[1;31mInvalid input. Enter a valid day\n\033[1;0m" ) ;
		
				scanf( "%d" , &temp_date.day ) ;
			}
		
			fseek( fp , 0 , SEEK_SET ) ;
		
			any_date_detail( temp_date , fp ) ;
			
		}
	
		if( repeat_flag == 1 )
		{
			printf( "\n\n\033[1;34mDo you wish to view details of expenditure of any other day of the month?\n" ) ;	

			printf( "\033[1;34mPress \033[1;32my \033[1;34mfor \033[1;32mYES \033[1;34mor \033[1;31many other key \033[1;34mfor \033[1;31mNO\n" ) ;
	
			temp = 0 ;
	
			scanf( "%*c%c" , &temp ) ;
		}
		
	}while( temp == 'y' ) ;
		
	
	printf( "\n\n\033[1;34mPress \033[1;31mx \033[1;34mkey to exit to main menu\033[1;31m\n" ) ;
	
	while( temp != 'x' )
	{
		scanf( "%*c%c" , &temp ) ; 
	}	
		
}
	
	
category any_date( date current_date , FILE *fp )
{

	char date[ 11 ] ;
	
	sprintf( date , "%d-%d-%d" , current_date.day , current_date.month , current_date.year ) ;

	category expense , f;
	
	memset( &expense , 0 , sizeof( expense ) ) ;
	
	memset( &f , 0 , sizeof( f ) ) ;

	while( fscanf( fp , "%d-%d-%d %f %f %f %f %f %f %f %f %[^\n]s" , &f.temp_date.day , &f.temp_date.month , &f.temp_date.year , &f.housing , &f.transport , &f.grocery , &f.food , &f.health , &f.lifestyle , &f.obligation , &f.other , f.remark ) != EOF ) 
	{
		if( current_date.day == f.temp_date.day && current_date.month == f.temp_date.month && f.temp_date.year == current_date.year )
		{			
			expense.housing += f.housing ;
			
			expense.transport += f.transport ;
			
			expense.grocery += f.grocery ;
			
			expense.food += f.food ;			

			expense.health += f.health ;
			
			expense.lifestyle += f.lifestyle ;
			
			expense.obligation += f.obligation ;
			
			expense.other += f.other ;
			
		}
	}	
	
	float total = expense.housing + expense.transport + expense.grocery + expense.food + expense.health + expense.lifestyle + expense.obligation + expense.other ;
	
	if( total != 0.00 )
	{
		printf( "\n\033[1;33m%-13s\033[1;0m%-12.2f%-12.2f%-12.2f%-11.2f%-11.2f%-12.2f%-13.2f%-11.2f\033[1;33m%1.2f\033[1;0m\n" , date , expense.housing , expense.transport , expense.grocery , expense.food , expense.health , expense.lifestyle , expense.obligation , expense.other , total ) ;
	}
	
	return expense ;

}		


