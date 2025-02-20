#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define SLEEP(x) Sleep(1000 * x)
void PRINT_TIME (int *hour, int *minute, int *second){
char *num_art[10][7] = {
    { 
        " 00000 ",
        "0     0",
        "0     0",
        "0     0",
        "0     0",
        "0     0",
        " 00000 "
    },
    { 
        "   1   ",
        "  11   ",
        "   1   ",
        "   1   ",
        "   1   ",
        "   1   ",
        " 11111 "
    },
    {
        " 22222 ",
        "      2",
        "      2",
        " 22222 ",
        "2      ",
        "2      ",
        "2222222"
    },
    {
        " 33333 ",
        "      3",
        "      3",
        " 33333 ",
        "      3",
        "      3",
        " 33333 "
    },
    { 
        "4     4",
        "4     4",
        "4     4",
        "4444444",
        "      4",
        "      4",
        "      4"
    },
    { 
        "5555555",
        "5      ",
        "5      ",
        "5555555",
        "      5",
        "      5",
        "5555555"
    },
    { 
        " 66666 ",
        "6      ",
        "6      ",
        "6666666",
        "6     6",
        "6     6",
        " 66666 "
    },
    { 
        "7777777",
        "      7",
        "     7 ",
        "    7  ",
        "   7   ",
        "  7    ",
        " 7     "
    },
    { 
        " 88888 ",
        "8     8",
        "8     8",
        " 88888 ",
        "8     8",
        "8     8",
        " 88888 "
    },
    { 
        " 99999 ",
        "9     9",
        "9     9",
        " 99999 ",
        "      9",
        "      9",
        " 99999 "
    }
};



    int hour_tens = *hour / 10;  
    int hour_ones = *hour % 10;  
    
	int min_tens = *minute / 10; 
    int min_ones = *minute % 10;  
    
    int sec_tens = *second / 10;  
	int sec_ones = *second % 10;      
    

    
    for (int i = 0; i < 7; i++) {
      
         printf("| %s %s : %s %s : %s %s     |\n",
            num_art[hour_tens][i], num_art[hour_ones][i],
               num_art[min_tens][i], num_art[min_ones][i],
		       num_art[sec_tens][i], num_art[sec_ones][i]);               	
    }
	
}

int main(){
	int hour,minute,second;
	while(1){
		system("cls");
		time_t now;
		struct tm*timeInfo;
		time(&now);
		timeInfo = localtime(&now);
		printf("Now : %04d-%02d-%02d %02d:%02d:%02d",
				timeInfo->tm_year + 1900, timeInfo->tm_mon +1, timeInfo->tm_mday,
				timeInfo->tm_hour, timeInfo->tm_min,timeInfo->tm_sec);
			
		hour= timeInfo->tm_hour;
		minute = timeInfo->tm_min;		
		second = timeInfo->tm_sec;
		printf("\n\n|-------------------------------------------------------------\n");			       		
		PRINT_TIME(&hour,&minute,&second);
		printf("|\t\t\t\t\t\t\t  |\n|--------------------------------------------------------------|");			       		
		fflush(stdout);		
		SLEEP(1);
	
		
	}
	
	return 0;
}