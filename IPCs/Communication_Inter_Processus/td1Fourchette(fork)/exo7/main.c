/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 22 septembre 2020, 11:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*
 * 
 */
int main(int argc, char** argv) 
{

    int pid1,pid2,pid3,pid4,pid5,pid6;
    char message[BUFSIZ]={0};
    //p1
    
    pid1=fork();
    if(pid1 == 0) //p3
    {
        pid2=fork(); 
        if(pid2==0) //p2
        {
            sprintf(message,"P2 pid=%d ppid=%d", getpid(),getppid());
            boite("P2",message);
        }
        else //p3
        {
            pid3=fork();
            if(pid3==0) //p4
            {
                sprintf(message,"P4 pid=%d ppid=%d", getpid(),getppid());
                boite("P4",message);
            }
            else //p3
            {
                pid4=fork();
                if(pid4==0) //p5
                {
                    pid5=fork();
                    if(pid5==0)//P6
                    {
                        sprintf(message,"P6 pid=%d ppid=%d", getpid(),getppid());
                        boite("P6",message);
                    }
                    else //P5
                    {
                        pid6=fork();
                        if(pid6==0) //P7
                        {
                            sprintf(message,"P7 pid=%d ppid=%d", getpid(),getppid());
                            boite("P7",message);
                        }
                        else //P5
                        {
                            sprintf(message,"P5 pid=%d ppid=%d", getpid(),getppid());
                            boite("P5",message);
                        }
                    }
                }
                else //p3
                {
                    sprintf(message,"P3 pid=%d ppid=%d", getpid(),getppid());
                    boite("P3",message);
                }
            }
        }
    }
    else    //p1
    {
        sprintf(message,"P1 pid=%d ppid=%d", getpid(),getppid());
        boite("P1",message);
    }
    return (EXIT_SUCCESS);
}

