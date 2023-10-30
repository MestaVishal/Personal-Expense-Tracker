#include "expense_header.h"

void today( date *current )
{	
	time_t t ;

	time( &t ) ;

	struct tm *x = localtime( &t ) ;

	current -> day = x -> tm_mday ;
	
	current -> month = x -> tm_mon + 1 ;
	
	current -> year = x -> tm_year + 1900 ;
}

int days_month( date any_date , char *which_month )
{
	int day = 0 ;
	
	memset( which_month , 0 , 10 ) ;
	
	switch( any_date.month )
	{
		case 1 : sprintf( which_month , "JAN %d" , any_date.year ) ;
			 
			 day = 31 ;
			 
			 break ;
			 
		case 2 : sprintf( which_month , "FEB %d" , any_date.year ) ;
			 
			 day = 28 ;
			 
			 break ;
		
		case 3 : sprintf( which_month , "MAR %d" , any_date.year ) ;
		
			 day = 31 ;
			 
			 break ;

		case 4 : sprintf( which_month , "APR %d" , any_date.year ) ;
		
			 day = 30 ;
			 
			 break ;

		case 5 : sprintf( which_month , "MAY %d" , any_date.year ) ;
		
			 day = 31 ;
			 
			 break ;

		case 6 : sprintf( which_month , "JUN %d" , any_date.year ) ;
		
			 day = 30 ;
			 
			 break ;

		case 7 : sprintf( which_month , "JUL %d" , any_date.year ) ;
		
			 day = 31 ;
			 
			 break ;

		case 8 : sprintf( which_month , "AUG %d" , any_date.year ) ;
		
			 day = 31 ;
			 
			 break ;

		case 9 : sprintf( which_month , "SEP %d" , any_date.year ) ;
		
			 day = 30 ;
			 
			 break ;

		case 10 : sprintf( which_month , "OCT %d" , any_date.year ) ;
		
			  day = 31 ;
			  
			  break ;

		case 11 : sprintf( which_month , "NOV %d" , any_date.year ) ;
		
			  day = 30 ;
			  
			  break ;

		case 12 : sprintf( which_month , "DEC %d" , any_date.year ) ;
		
			  day = 31 ;
			  
			  break ;
	}
	
	return day ;
	
}

char *name( date any_date )
{
	char *file_name = ( char * )malloc( 13 * sizeof( char ) ) ;
		
	switch( any_date.month )
	{
		case 1 : sprintf( file_name , "Jan_%d.txt" , any_date.year ) ;
		
			 break ;
			 
		case 2 : sprintf( file_name , "Feb_%d.txt" , any_date.year ) ;
		
			 break ;
		
		case 3 : sprintf( file_name , "Mar_%d.txt" , any_date.year ) ;
		
			 break ;

		case 4 : sprintf( file_name , "Apr_%d.txt" , any_date.year ) ;
		
			 break ;

		case 5 : sprintf( file_name , "May_%d.txt" , any_date.year ) ;
		
			 break ;

		case 6 : sprintf( file_name , "Jun_%d.txt" , any_date.year ) ;
		
			 break ;

		case 7 : sprintf( file_name , "Jul_%d.txt" , any_date.year ) ;
		
			 break ;

		case 8 : sprintf( file_name , "Aug_%d.txt" , any_date.year ) ;
		
			 break ;

		case 9 : sprintf( file_name , "Sep_%d.txt" , any_date.year ) ;
		
			 break ;

		case 10 : sprintf( file_name , "Oct_%d.txt" , any_date.year ) ;
		
			 break ;

		case 11 : sprintf( file_name , "Nov_%d.txt" , any_date.year ) ;
		
			 break ;

		case 12 : sprintf( file_name , "Dec_%d.txt" , any_date.year ) ;
		
			 break ;
	}
	
	return file_name ;
}
	

