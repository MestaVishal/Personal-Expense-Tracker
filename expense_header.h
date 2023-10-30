#include <stdio.h>

#include <time.h>

#include <string.h>

#include <stdlib.h>

typedef struct
{
	int day ;
	
	int month ;
	
	int year ;
}date ;

typedef struct
{

	date temp_date ;
	
	float housing ;
	
	float transport ;
	
	float grocery ;
	
	float food ;
	
	float health ;
	
	float lifestyle ;
	
	float obligation ;
	
	float other ;
	
	char remark[ 50 ] ;
}category ;

void add_expense( void ) ;

void expense_history( void ) ;

void today( date *current_date ) ;

char *name( date current_date ) ;

void any_date_detail( date current_date , FILE *fp ) ;

category any_date( date current_date , FILE *fp ) ;

int days_month( date temp_date , char *which_month ) ;

void month_expense( date temp_date , FILE *fp ) ;

void today_expense( void ) ;

void any_month( void ) ;



