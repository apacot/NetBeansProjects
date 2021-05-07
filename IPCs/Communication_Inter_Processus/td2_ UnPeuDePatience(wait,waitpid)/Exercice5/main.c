/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 29 septembre 2020, 11:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    int pid;
    pid_t retourWait;
    int status;
    
    //p1
    pid=fork();
    if(pid == 0) //p2
    {
        printf("P2 : pid = %d ppid = %d\n",getpid(),getppid());
        //attendre la fin du processus père
        retourWait=waitpid(getppid(),&status,0);        
        printf("processus ayant le pid %d est mort\n",retourWait);
    }
    else //p1
    {
        sleep(1);
        printf("P1 : pid = %d ppid = %d\n",getpid(),getppid());       
    }
    
    return (EXIT_SUCCESS);
}

