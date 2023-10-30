a.out: expense_main.c expense_history.c file_generation.c expense_data_read.c expense_data_write.c
	gcc -I. expense_main.c expense_history.c file_generation.c expense_data_read.c expense_data_write.c
