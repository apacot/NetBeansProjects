/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 29 septembre 2020, 10:58
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
        printf("P2 : pid = %d ppid= %d\n",getpid(),getppid());
    }
    else //p1
    {
        pid = fork();
        if(pid == 0) //p3
        {
            printf("P3 : pid = %d ppid = %d\n", getpid(),getppid());
        }
        else //p1
        {
            printf("P1 : pid = %d ppid = %d\n", getpid(),getppid());
            //attendre la fin d'un processus fils
            retourWait=wait(&status);
            printf("processus avec pid %d est mort\n",retourWait);
            //attendre la fin d'un processus fils
            retourWait=wait(&status);
            printf("processus avec pid %d est mort\n",retourWait);
        }
    }
    
    return (EXIT_SUCCESS);
}

