#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


int main(){
        chmod("/bigtemp/cso1-f22/cmn5et.chat", 0666);
        FILE *inbox = fopen("/bigtemp/cso1-f22/cmn5et.chat", "r");
        char *me = getenv("USER");
        puts(me);

        size_t got = 0;

        char buffer[4096];
        if(inbox != NULL){

                got = fread(buffer, sizeof(char), 4096, inbox);
                if(got > (size_t) 0){
                        truncate("/bigtemp/cso1-f22/cmn5et.chat", 0);
                        printf("Your message: \n %s", buffer);
                        printf("\n");
                }
                else{
                        printf("You have no new messages \n");
                }

        }

        //read in user you want to send
        char recipiant[10];
        char path[4096];
        char ch;
        //char *message[4096] ="";

        path[0] = '\0';
        strcat(path, "/bigtemp/cso1-f22/");

        //read in the user you want to send
        printf("Who would you like to message? \n");
        scanf("%s", recipiant);
        strcat(path, recipiant);
        strcat(path, ".chat");

        //eats the new line
        scanf("%c",&ch);

        //takes the message
        printf("What do you want to say? \n");
        fgets(buffer, 4096, stdin);
        FILE *outbox = fopen(path, "a");
        chmod(path, 0666);
        fprintf(outbox, "%s: %s\n", "cmn5et", buffer);

        fclose(inbox);
        fclose(outbox);
        return 0;
