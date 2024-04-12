#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    char    *argv[6];
    char    *argv2[3];

    argv[0] = "cat";
    argv[1]    = "in.txt";
    argv[2] = NULL;

    argv2[0] = "wc";
    argv2[1] = "-l";
    argv2[2] = NULL;

    int    pipefd[2];
    int    num;
    int    pid_child1;
    int pid_child2;
    int    fd_infile;
    int    fd_outfile;
    
    num = pipe(pipefd); //error handling...
    pid_child1 = fork();
    if (pid_child1 == 0)
    {
        fd_infile = open("in.txt", O_RDWR | O_CREAT, 0644);
        dup2(fd_infile, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        execve("/bin/cat", argv, NULL);
        exit(0);
    }
    pid_child2 = fork();
    if (pid_child2 == 0)
    {
        close(pipefd[1]);
        fd_outfile = open("out.txt", O_WRONLY | O_CREAT, 0644);
        dup2(pipefd[0], STDIN_FILENO);
        dup2(fd_outfile, STDOUT_FILENO);
        execve("/usr/bin/wc", argv2, NULL);
        exit(0);
    }
    else
    {
        close(pipefd[0]);
        close(pipefd[1]);
        // printf("a\n");
        waitpid(pid_child1, NULL, 0);
        // printf("b\n");
        waitpid(pid_child2, NULL, 0);
        // printf("c\n");
        return (0);
    }
}

int    main(int argc, char **argv, char **envp)
{
    return (0);
}