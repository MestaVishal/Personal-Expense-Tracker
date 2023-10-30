#include "expense_header.h"

int main() 
{
	system( "clear" ) ;
	
	printf( "\033[1;31mWelcome to the Expense Tracker\n\n" ) ;
	
	int choice , repeat = 0 ;
	
	category expense ;

	do
	{	
		if( repeat ) 
		{
			system( "clear" ) ;
		}
		
		printf( "\033[1;34mWhat do you like to do?\n" ) ;
	
		printf( "\033[1;0mEnter \033[1;36m1 \033[1;0mto add an expense\n" ) ;

		printf( "\033[1;0mEnter \033[1;36m2 \033[1;0mto view expense history\n" ) ;

		printf( "\033[1;0mEnter \033[1;36m3 \033[1;0mto Exit\n\n" ) ;
		
		printf( "\033[1;34mEnter your choice\n\033[1;0m" ) ;
		
		scanf( "%d" , &choice ) ;
		
		switch( choice )
		{
			case 1 : add_expense() ;
			
				 break ;
			
			case 2 : expense_history() ;
				
				 break ;
			
			case 3 : printf( "\n\n\033[1;34mExiting the program..\n\n\033[1;0m" ) ;
				 
				 break ;
			
			default : printf( "\n\033[1;31mInvalid choice. Please enter valid choice\n\n\033[1;0m" ) ;
		}
		
		repeat = 1 ;	
		
	}while( choice != 3 ) ;
		
	return 0 ;
}



	
	
	
	
	
