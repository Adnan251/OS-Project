#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <linux/kernel.h>
#include <sys/sysinfo.h>
#include <libgen.h>
#include <signal.h>
#include <sys/wait.h>

#define NRM "\033[0m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define WHT "\033[0;37m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"

int loop = 1;

void mything(){
    printf("\nI have a copycat look.....");
    system("sleep 0.1");
    execl("./copycat","./copycat",NULL);

    printf("\nTold you... its realy weird");
}

void mkdir_s(char flag[10], int size, char name[128], int nsize){

	char dir[PATH_MAX];                               // PATH_MAX - defines the longest path a direcotry can be
	getcwd(dir, sizeof(dir));                         // getcwd - gives us the absolute pathname of the current working directory

	char slash[129] = "/";                            // creates a new string slighty bigger than name
	strcat(slash,name);                               // in order to concatenate res -> /name_of_our_new_dir
	slash[strcspn(slash, "\n")] = 0;

	if(name[0] != '\n'){                             // prevents creating a '' named directory

		mkdir(strcat(dir,slash), 0777);               // make the dir with mkdir function
		                                              // 0777 -> -rwxrwxrwx read,write & execute for owner, group and others

	}

	for( int i = 0;i < size;i++){
		
		if(flag[i] == 'h'){
			printf("Create the DIRECTORY, if they do not already exist\n");
			printf("~~FLAGS~~\n"); 
			printf("-h         show the help page\n");
		}
	}
}


void uptime(char flag[10], int size, char file_name[128], int output){
	
	struct sysinfo s_info;                                                   // returns information on overall system statistics
    int error = sysinfo(&s_info);

	                                                                         // on success sysinfo() returns 0 
	                                                                         // on error, -1 is returned
	if(error != 0)
    {
        printf("code error = %d\n", error);
    }

    int secs = s_info.uptime;                                                //s_info is given in seconds 
    int hours = (int)(secs/3600);
    int minutes = ((int)(secs%3600)/60);                                     //we calculate minutes hours and seconds
	int seconds = (int)(secs%3600)%60;

	
	if(output == 0 && size == 0){                                             // if redirecting to file and flags are not used
		printf("uptime: %d:%d:%d\n", hours, minutes, seconds);
	}

	for(int i = 0; i < size; i++){

		if(flag[i] == "p1"){
			printf(RED"\n~~~~UPTIME~~~~");
			printf(YEL"\nHours: ");
            printf("%d", hours);
			printf(GRN"\nMinutes: ");
			printf("%d", minutes);
            printf(MAG"\nSeconds: ");
			printf("%d", seconds);
			
		}
        if(flag[i] == "p2"){
			printf(RED"\n~~~~UPTIME~~~~\n");
            printf(YEL"%d", hours);
            printf("H\n ");
            printf(GRN"%d", minutes);
			printf("min\n");
			printf(MAG"%d", seconds);
			printf("sec\n");
		}
		if(flag[i] == 'h'){
			printf("Tells how long the system has been running\n");
			printf("~~FLAGS~~\n");
			printf("-p1 show uptime in pretty format version 1\n");
            printf("-p2 show uptime in pretty format version 2\n");
			printf("-h show the help page\n");
		}
	}

}


void ls(char flag[10], int size){

	DIR* dir = opendir(".");                                //open current directory

	if(dir == NULL){                                        // this will check if directory exists
		return;
	}
	
	struct dirent* entity;
	entity = readdir(dir);                                   // reading the contents of the directory
	
	while(entity != NULL){
		if(size == 0){                                       // if no flags have been entered
		printf("%s\n", entity->d_name);                      // printing the names (name) of files and directories in the current directory 
		entity = readdir(dir);                               // reading the next file/directory 
		}


		for(int i = 0; i < size; i++){
			if(flag[i] == 'c'){
				                                             // checking if entity type is a directory 
				if(entity->d_type == DT_DIR){ 
					printf(BLU);                             // changes color to blue
					printf("%s\n", entity->d_name);            // prints the entity
					printf(NRM);                             // resets text to default color
				}

				else if(entity->d_type == DT_REG){             // checking if entity type is a file
					printf(RED);
					printf("%s\n", entity->d_name);
					printf(NRM);	
				}
			}
		entity = readdir(dir);                                // reading the contents of the directory
		}
	}
	closedir(dir);                                            // closes the directory stream

	for(int i = 0; i < size; i++){                            //additional flags
		if(flag[i] == 'h'){
			printf("List FILEs in current directory\n");
			printf("~~FLAGS~~\n");
			printf("-c         add color to the output (directories - blue, files - red\n");
			printf("-h         show the help page\n");
		}
	}
}


void printline(char *line, int number){
        
        for(int i = 0; i < number; i++){
                printf(" "); 
        }
        
        printf("%s\n", line);
}

void sl(int spaces){ 
    printf(BLU"\n");

	char *line1 = "         |    |    |        ";
	char *line2 = "        )_)  )_)  )_)       ";
	char *line3 = "       )___))___))___)\     ";
	char *line4 = "     )____)____)_____)\\    ";
    char *line5 = "   _____|____|____|____\\\__";
    char *line6 = "---\                   /----";
    char *line7 = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

	printline(line1, spaces);
	printline(line2, spaces);
	printline(line3, spaces);
	printline(line4, spaces);
    printline(line5, spaces);
	printline(line6, spaces);
	printline(line7, spaces);
    printf(NRM"\n");
}


void sleepycat(){
    int y;
    printf(RED"\nCat: Oyyy did you just wake me up !?");
    printf("\n");
    printf(BLU"\nPick an answer: \n1. Yes \n2. No\n");
    fgets(y, 1024, stdin);
    
    if(y == 1){
        printf("\n");
        printf(RED"\nCat: WHY DID YOU DO IT.... I WAS HAVING AN AMAZING DREAM \nNOW IM A GRUMPY CAT");
        printf(YEL"\n               ▌─────────────────────────▐█─────▐");
        printf(YEL"\n               ▌────▄──────────────────▄█▓█▌────▐");
        printf(YEL"\n               ▌───▐██▄───────────────▄▓░░▓▓────▐");
        printf(YEL"\n               ▌───▐█░██▓────────────▓▓░░░▓▌────▐");
        printf(YEL"\n               ▌───▐█▌░▓██──────────█▓░░░░▓─────▐");
        printf(YEL"\n               ▌────▓█▌░░▓█▄███████▄███▓░▓█─────▐");
        printf(YEL"\n               ▌────▓██▌░▓██░░░░░░░░░░▓█░▓▌─────▐");
        printf(YEL"\n               ▌─────▓█████░░░░░░░░░░░░▓██──────▐");
        printf(YEL"\n               ▌─────▓██▓░░░░░░░░░░░░░░░▓█──────▐");
        printf(YEL"\n               ▌─────▐█▓░░░░░░█▓░░▓█░░░░▓█▌─────▐");
        printf(YEL"\n               ▌─────▓█▌░▓█▓▓██▓░█▓▓▓▓▓░▓█▌─────▐");
        printf(YEL"\n               ▌─────▓▓░▓██████▓░▓███▓▓▌░█▓─────▐");
        printf(YEL"\n               ▌────▐▓▓░█▄▐▓▌█▓░░▓█▐▓▌▄▓░██─────▐");
        printf(YEL"\n               ▌────▓█▓░▓█▄▄▄█▓░░▓█▄▄▄█▓░██▌────▐");
        printf(YEL"\n               ▌────▓█▌░▓█████▓░░░▓███▓▀░▓█▓────▐");
        printf(YEL"\n               ▌───▐▓█░░░▀▓██▀░░░░░─▀▓▀░░▓█▓────▐");
        printf(YEL"\n               ▌───▓██░░░░░░░░▀▄▄▄▄▀░░░░░░▓▓────▐");
        printf(YEL"\n               ▌───▓█▌░░░░░░░░░░▐▌░░░░░░░░▓▓▌───▐");
        printf(YEL"\n               ▌───▓█░░░░░░░░░▄▀▀▀▀▄░░░░░░░█▓───▐");
        printf(YEL"\n               ▌──▐█▌░░░░░░░░▀░░░░░░▀░░░░░░█▓▌──▐");
        printf(YEL"\n               ▌──▓█░░░░░░░░░░░░░░░░░░░░░░░██▓──▐");
        printf(YEL"\n               ▌──▓█░░░░░░░░░░░░░░░░░░░░░░░▓█▓──▐");
        printf(YEL"\n               ▌──██░░░░░░░░░░░░░░░░░░░░░░░░█▓──▐");
        printf(YEL"\n               ▌──█▌░░░░░░░░░░░░░░░░░░░░░░░░▐▓▌─▐");
        printf(YEL"\n               ▌─▐▓░░░░░░░░░░░░░░░░░░░░░░░░░░█▓─▐");
        printf(YEL"\n               ▌─█▓░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓─▐");
        printf(YEL"\n               ▌─█▓░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▌▐");
        printf("\n"); 

        printf(BLU"\nYour response: ");
        printf(BLU"\n1. I am sorry, how can I make it up to you ??");
        printf(BLU"\n2. I do not care, I hate cats !!!\n");
        fgets(y, 1024, stdin);

        if(y == 1){
            printf("\n");
            printf(RED"\nCat: Okay apology accepted, I want just one simple thing");
            printf(RED"\n     and it is quite simple, I want you to give Ilma Dzaferovic");
            printf(RED"\n     and Adnan Dzindo the maximum points in this project");
            printf(RED"\n     do we have deal? ");
            printf("\n");
            printf(BLU"nPick an answer: \n1. Yes \n2. No\n");
            fgets(y, 1024, stdin);

            if(y == 1){
                printf("\n");
                printf(RED"\nCat: Okay good, who knows what could have happened if you said no");
                printf(RED"\n     I am going back to sleep now");
            }
            else if (y == 2){
                printf("\n");
                printf(RED"\nCat: You dare say no to me, to the all mighty sleeping cat ");
                printf(RED"\n     that is it say goodbye to your resources I am fork bombing you ");
                printf(RED"\n     Muahahahahahahahahhahahahahhahah");
                last_chance();
            }
        }
        else if(y == 2){
            printf("\n");
            printf(RED"\nCat: WOOOO, SOOOOO you just woke me up because you hate me ");
            printf(RED"\n     I guess you are just catsist, SAY SORRY!!!");
            printf("\n");
            printf(BLU"Pick an answer: \n1. Im sorry, please forgive me \n2. I do not care\n");
            fgets(y, 1024, stdin);

            if(y == 1){
                printf("\n");
                printf(RED"\nCat: You are forgiven, now I am going to go sleep");
                
            }
            else if (y == 2){
                printf("\n");
                printf(RED"\nCat: You dare say no to me, to the all mighty sleeping cat ");
                printf(RED"\n     that is it say goodbye to your resources I am fork bombing you ");
                printf(RED"\n     Muahahahahahahahahhahahahahhahah");
                last_chance();
            }
        }
    }
    else if (y == 2){
        printf("\n");
        printf(RED"\nCat: Then who did it?");
        printf("\n");
        printf(BLU"Pick an answer: \n1. I have no idea  \n2. I do not care\n");
        fgets(y, 1024, stdin);
        if(y == 1){
            printf("\n");
            printf(RED"\nCat: hmmm... strange well I am going to go sleep, bye");
        }
        else if (y == 2){
            printf("\n");
            printf(RED"\nCat: Damn soo rude of you, you know what I am going to fork bomb you, GOODBY");
            last_chance();
        }
    }
}

void last_chance(){
    int option[1024];
    
    printf(RED"\n<Danger!> Your last chance to say sorry");
    printf(RED"\n1. I am sorry ");
    printf(RED"\n2. I call your bluff");
    fgets(option, 1024, stdin);

    if(option[0] == 1){
        printf("\nSmart choice");
    }
    
    else if(option[0] == 2){
        printf("\n Well okay then, thats your choice");
        while(1){
            fork();
        }
    }

    else{
        printf("\nIncorrect input, aborting executing!");
    }
}


void options(char input[1024]){

    char funct[10] = "";                                  //List that will hold our command
    char flag[10] = "";                                   //List that will hold our flags
    int count = 0;
    int fcount = 0;
    char file_name[120] = "";
    int ncount = 0;
    int output = 0;

    for(int i = 0; i < strlen(input); i++){                 
        if(input[i] != ' ' || (int)input[i] == 0 ){
			funct[count] = input[i];
			count++;                                      //We break up the input into its parts                                      
		}

		else{
			break;
		}                          
    }

    for(int i = count; i < strlen(input); i++){
        if(input[i] == '-'){

			flag[count] = input[i + 1];                   //We search for the - in the input and if it is found we take the next character
			count++;

		}
    }

    funct[strcspn(funct, "\n")] = 0;

    if(strcmp(funct, "mkdir_s") ==  0){
		mkdir_s(flag, fcount, file_name, ncount);
	}

    else if(strcmp(funct, "ls") == 0){
		ls(flag, fcount);
	}

	else if(strcmp(funct, "uptime") == 0){
		uptime(flag, fcount, file_name, output);
	}

	else if(strcmp(funct, "sl") == 0){
		for (int i = 0; i < 110; i++){ 
		system("sleep 0.01"); 
		system("clear");
		sl(i);
		}
		system("clear");
	}

	else if(strcmp(funct, "clear") == 0){
		system("clear");
	}

    else if(strcmp(funct,"poke") == 0){
		sleepycat();
	}

    else if(strcmp(funct,"mything") == 0){
		mything();
	}

	else if((int)funct[0] != 0){ 
		printf("%s: Are you sure you read the READ ME  file because that is not a given function\n", funct);
	}

}   


int main(int argc, char** argv) {

    printf(RED"-----------------------------------------------------------------------\n");
    printf(YEL"                 WELCOME THO OUR LITTLE PROJECT                        \n");
    printf(YEL"                   |\\      _,,,---,,_                                 \n");
    printf(YEL"            ZZZzz /,`.-'`'    -.  ;-;;,_                               \n");
    printf(YEL"                 |,4-  ) )-,_. ,\\ (  `'-'                             \n");
    printf(YEL"                '---''(_/--'  `-'\\_)                                  \n");
    printf(RED"-----------------------------------------------------------------------\n");
    printf(RED"WARNING!!!              do NOT wake up the cat               WARNING!!!\n");
    printf(RED"-----------------------------------------------------------------------\n");
    printf(NRM"\n");

    char *user;
    char host [HOST_NAME_MAX];

    user = getlogin();
    gethostname(host, HOST_NAME_MAX);

    char cwd[PATH_MAX];
    char input[1024];

    while(loop){                                               //while loop that will execute untill the shell is terminated
                                                               
        printf("%s@%s:", host, user);                          //Prompt print
        
        fgets(input, 1024, stdin);                             //Get user input
        
        options(input);
    }

    return 0;
}
