#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int SID;
	char * name;
	int mathscore;
	int englishscore;
	int programmingscore;
	
}Student;

void MakeTitle();
void DivergingPoint(int Diverging);
void Switch1();
void Switch2();
void Switch3();
void Switch4();
void Switch5();
void Switch6();
void Switch7();

int main(){
	MakeTitle();
	int Diverging = 0;
	while(1){		
		printf("\n\n What do you want to do =>");
			scanf("%d",&Diverging);				
				while(getchar()!= '\n');				
					DivergingPoint(Diverging);										
	if(Diverging ==7){break;}				
											
	}
	
	return 0;
}
void MakeTitle(){
	
	printf("=====================================\n");
	printf("    Student Score Management System\n");
	printf("=====================================\n");
	printf("1. Append Student Infor\n");
	printf("2. Selection All Stduents\n");
	printf("3. Selection One Student\n");
	printf("4. Update Student Score\n");
	printf("5. Delete Student Infor\n");
	printf("6. Selection All Scores\n");
	printf("7. Exit\n");
	printf("=====================================\n");
}


void DivergingPoint(int Diverging){
	switch(Diverging){
		case 1:
			Switch1();
			printf("\n New Student Appended. \n\n\n\n\n\n\n\n\n\n");
			MakeTitle();
			break;
		case 2:
			Switch2();			
			printf("\n\n\n\n");
			MakeTitle();
			break;			
		case 3:
			Switch3();
			printf("\n\n\n\n");
			MakeTitle();
			break;			
		case 4:
			Switch4();
			printf("\n\n\n\n");
			MakeTitle();
			break;			
		case 5:
			Switch5();
			printf("\n\n\n\n");
			MakeTitle();
			break;			
		case 6:
			Switch6();
			printf("\n\n\n\n");
			MakeTitle();															
			break;			
		case 7:
			printf("System Exit.\n");		
			break;				
		default:
			printf("Wrong Access.\n");
			break;			
		
	}	
	
		
	
}


void Switch1(){
	FILE *fp;	
	fp = fopen("studentDB.txt","a");
	
	Student student;
	student.SID = 0;
	student.name = (char*)malloc(50*sizeof(char));
	snprintf(student.name,50," ");
	student.mathscore = 0;
	student.englishscore = 0;
	student.programmingscore = 0;
	
	int a = 0;
	
	
        printf("\n\nInput SID => ");
        	scanf("%d", &student.SID); 	
        		while (getchar() != '\n'); 


        printf("Input Name => ");
        	fgets(student.name, 50, stdin); 
		        student.name[strcspn(student.name, "\n")] = 0;


		printf("Input Math Score (0~100) => ");
		while (scanf("%d", &student.mathscore) != 1 || student.mathscore < 0 || student.mathscore > 100) {
		    printf("score is ONLY between 0 and 100 => ");
		    	while (getchar() != '\n');
		}


        
		printf("Input English Score (0~100) => ");
		while (scanf("%d", &student.englishscore) != 1 || student.englishscore < 0 || student.englishscore > 100) {
		    printf("score is ONLY between 0 and 100 => ");
		    	while (getchar() != '\n');
		}

        
		printf("Input English Score (0~100) => ");
		while (scanf("%d", &student.programmingscore ) != 1 || student.programmingscore < 0 || student.programmingscore > 100) {
		    printf("score is ONLY between 0 and 100 => ");
		    	while (getchar() != '\n');
		} 
		        

	fprintf(fp, "SID: %d, name: %s, math: %d, eng: %d, PG: %d\n", 
    student.SID, student.name, student.mathscore, student.englishscore, student.programmingscore);
	
	free(student.name);	
	fclose(fp);	
}

void Switch2(){
 	FILE *fp;
    fp = fopen("studentDB.txt", "r"); 
	
    char buffer[256];
	int Len = 0;

	printf("\n ======== Students  List. ======== \n\n");
	
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    	Len++;
        printf("%s", buffer);
    }
	Len==0? 
	 printf("\nThere is no data.\n") :
	 printf("\nAll is %d.\n", Len);
        
    fclose(fp);  
}

void Switch3(){
	FILE *fp;
    fp = fopen("studentDB.txt", "r");

    int SID;
    printf("Enter SID. => \n");
    	scanf("%d", &SID);  
			while(getchar()!= '\n');
	
	Student student;	
    char searchbuffer[256];


    int found = 0;

    while (fgets(searchbuffer, sizeof(searchbuffer), fp) != NULL) {
		
        if (sscanf(searchbuffer, "SID: %d", &student.SID) == 1) {
            if (student.SID == SID) {
               
                printf("\n<<<   Student Information >>>");
                printf("\n\n%s", searchbuffer);
                found = 1;
                break; 
            }
        }
    }

    if (!found) {
        printf("This number is invalid."); 
    }

    fclose(fp);
}
void Switch4() {
    FILE *fp = fopen("studentDB.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        fclose(fp);        
        return;
    }

    int SID;
    printf("Enter SID. => ");
    	scanf("%d", &SID);
    		while (getchar() != '\n');

    Student student;
    student.name = (char *)malloc(50 * sizeof(char));

    char searchbuffer[256];
    int found = 0;

    while (fgets(searchbuffer, sizeof(searchbuffer), fp) != NULL) {
        int extractedSID;

       
        if (sscanf(searchbuffer, "SID: %d", &extractedSID) == 1) {
            if (extractedSID == SID) {
                printf("\n<<<   Student Information >>>\n%s", searchbuffer);
                found = 1;

              
                printf("\nEnter new name: ");
                scanf("%49s", student.name);
                printf("Enter new math score: ");
                scanf("%d", &student.mathscore);
                printf("Enter new English score: ");
                scanf("%d", &student.englishscore);
                printf("Enter new programming score: ");
                scanf("%d", &student.programmingscore);

                
				fprintf(temp, "SID: %d, name: %s, math: %d, eng: %d, PG: %d\n", 
			    SID, student.name, student.mathscore, student.englishscore, student.programmingscore);
            } else {
             
                fprintf(temp, "%s", searchbuffer);
            }
        } else {
            printf("[DEBUG] sscanf  %s", searchbuffer);
        }
    }

    free(student.name);
    fclose(fp);
    fclose(temp);

    if (!found) {
        printf("This number is invalid.\n");
        remove("temp.txt");
    } else {
        remove("studentDB.txt");
        rename("temp.txt", "studentDB.txt");
    }
}

void Switch5() {
    FILE *fp = fopen("studentDB.txt", "r");
    FILE *temp = fopen("temp.txt", "w");    

    int SID;
    printf("Enter SID to delete => ");
    	scanf("%d", &SID);
    		while (getchar() != '\n');
	
    char searchbuffer[256];
    int found = 0;

    while (fgets(searchbuffer, sizeof(searchbuffer), fp) != NULL) {
        int extractedSID;

        if (sscanf(searchbuffer, "SID: %d", &extractedSID) == 1) {

            if (extractedSID == SID) {
                printf("\n<<<   Delete This Student. >>>\n%s", searchbuffer);
                found = 1;
            } else {
                fprintf(temp, "%s", searchbuffer);
            }
        }
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        printf("This number is invalid.\n");
        remove("temp.txt");
    } else {
        remove("studentDB.txt");
        rename("temp.txt", "studentDB.txt");
    }
}
void Switch6() {
    double average;
    printf("Enter the threshold value for average score: ");
    	scanf("%lf", &average);
    		while (getchar() != '\n'); 

    FILE *fp = fopen("studentDB.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    char searchbuffer[256];
    int found = 0;

    while (fgets(searchbuffer, sizeof(searchbuffer), fp) != NULL) { 
        Student student;
        student.name = malloc(50 * sizeof(char));

		int parsed = sscanf(searchbuffer,
		    "SID: %d, name: %49[^,], math: %d, eng: %d, PG: %d",
		    &student.SID, student.name,
    		&student.mathscore, &student.englishscore, &student.programmingscore);


        if (parsed != 5) {
            continue; 
        }

       double avg = (student.mathscore + student.englishscore + student.programmingscore) / 3.0;


        if (avg >= average) {
            found = 1;
            printf("Name: %s Math: %d English: %d Programming: %d (%2.2lf)\n",
				   student.name, 
                   student.mathscore, student.englishscore, 
                   student.programmingscore, avg);
        }
        free(student.name);
    }

    if (!found) {
        printf("\n<<< No student passed with an average score of %d or higher >>>\n", average);
    }

    fclose(fp);
}
