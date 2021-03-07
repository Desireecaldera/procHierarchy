/**
*Name: Desiree Caldera
*Lab/task: Lab03
*Date: 02/16/21
**/
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <errno.h>
#include    <sys/types.h>
#include    <sys/wait.h>

#define oops(m) {perror(m); exit(EXIT_FAILURE);}
//for annotations
const char *strs[7] = {"1", "1.1", "1.2", "1.1.1", "1.1.2", "1.2.1", "1.2.2"};

int main() {
   pid_t pid, pid2, gc1, gc2, gc3, gc4;
 
    // fork a child process
    pid = fork();
    int i;

    if (pid < 0) // error occurred
    oops("Fork Failed!");

    if (pid == 0) // first child
    {
        i = 1;
        gc1 = fork();

        //creating 1.1.1
        if( gc1 == 0 ){
         i = 3;

        } else {
        //creating 1.1.2
            gc2 = fork();
            if( gc2 == 0 ){
            i = 4;

            }
        }
       if (execlp("./iam", "iam", strs[i], NULL) < 0)
        oops("Execlp Failed!"); 
        
    //PARENT LOOP
    } else if ( pid > 0 ){
        // pid > 0 ==> must be parent
        printf("Process 1 pid is: %d\n", getpid()); 
      //i = 0;
        
        //Creating 1.2      
        pid2 = fork();
        if( pid2 == 0){
        i = 2;

           //creating 1.2.1
            gc3 = fork();

            if(gc3 == 0 ){
            i = 5;
            
            } else{
            //creating 1.2.2
                gc4 = fork();
                if( gc4 == 0 ){
                i = 6;
                }
            }
               if (execlp("./iam", "iam", strs[i], NULL) < 0)
                     oops("Execlp Failed!"); 
        }
        
  /*tried including parent in this execlp function for proper annotations
  however this caused an infinite loop*/ 
 //if (execlp("./iam", "iam", strs[i], NULL) < 0)
      // oops("Execlp Failed!");      
    }

       /* parent will wait for the child to complete */
       if (waitpid(-1, NULL, 0) < 0) 
           printf("-1 from wait() with errno = %d\n", errno);

    printf("Child terminated; parent exiting\n");  
    exit(EXIT_SUCCESS);

}
