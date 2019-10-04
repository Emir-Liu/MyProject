#include <sys/wait.h>
#include <unistd.h>
//unistd.h是C和C++中对POSIX(Portable Operating System Interface of UNIX)操作系统API的访问功能的头文件，由POSIC.1标准提出，所有遵循该标准的操作系统和编译器都应该提供这个头文件，如Unix，Mac OSX,Linux等。里面所定义的接口通常都是大量针对系统调用的封装
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
#include <sys/wait.h>
	waitpid() 和相关的宏
#include <unistd.h>
	chdir()
	fork()
	exec()
	pid_t
#include <stdlib.h>
	malloc()
	realloc()
	free()
	exit()
	execvp()
	EXIT_SUCCESS， EXIT_FAILURE
#include <stdio.h>
	fprintf()
	printf()
	stderr
	getchar()
	perror()
#include <string.h>
	strcmp()
	strtok()

*/

void lsh_loop(void);
char *lsh_read_line(void);
//*表示这个存储单元里面的数据为是另一个存储单元的地址
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_execute(char **args);
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};
//注意 **a 与 *a[]不同
int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit
};
//这是函数指针数组！！！

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int main(int argc,char **argv)
{
	lsh_loop();

	return EXIT_SUCCESS;
}

void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do{
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	}while(status);
}


/*
char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}
这一段程序可以代替下面的程序，主要是为getline()代替
*/
#define lsh_rl_bufsize 1024
char *lsh_read_line(void)
{
	int bufsize = lsh_rl_bufsize;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	//malloc返回指向被分配内存的指针，否则返回空指针NULL
	//通过free()释放内存
	//以前返回 char* ，现在返回 void* 必要时进行类型的转换,
	int c;

	if(!buffer)
	{
		fprintf(stderr,"lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		c = getchar();
		//getchar() 返回为int,为ASCII码或者EOF
		/*
int getchar(void)
{
    static char buf[BUFSIZ];
    static char* bb=buf;
    static int n=0;
    if(n==0)
    {
        n=read(0,buf,BUFSIZ);
				//头文件为unistd
        bb=buf;
    }
    return (--n>=0)?(unsigned char)*bb++:EOF;
}
		 */
		if(c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if(position >= bufsize)
		{
			bufsize += lsh_rl_bufsize;
			buffer = realloc(buffer,bufsize);
			//extern void *realloc(void *mem_address,unsigned int newsize)
			if(!buffer)
			{
				fprintf(stderr,"lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

#define lsh_tok_bufsize 64
#define lsh_tok_delim " \t\r\n\a"
char **lsh_split_line(char *line)
{
	int bufsize = lsh_tok_bufsize,position = 0;
	char **tokens = malloc(bufsize *sizeof(char*));
	char *token;

	if(!tokens)
	{
		fprintf(stderr,"lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line,lsh_tok_delim);
	//char *strtok(char s[], const char *delim);
	//strtok()用来将字符串分割成一个个片段。参数s指向欲分割的字符串，参数delim则为分割字符串中包含的所有字符。当strtok()在参数s的字符串中发现参数delim中包含的分割字符时,则会将该字符改为\0 字符。在第一次调用时，strtok()必需给予参数s字符串，往后的调用则将参数s设置成NULL。每次调用成功则返回指向被分割出片段的指针。
	//从s开头开始的一个个被分割的串。当s中的字符查找到末尾时，返回NULL。
	//如果查找不到delim中的字符时，返回当前strtok的字符串的指针。
	//所有delim中包含的字符都会被滤掉，并将被滤掉的地方设为一处分割的节点。
	//注意，strtok函数会破坏字符串的完整
	//最后，Linux 2.6.29,用strsep代替strtok，因为速度更快
/*
 * Get next token from string *stringp, where tokens are possibly-empty
 * strings separated by characters from delim.
 *
 * Writes NULs into the string at *stringp to end tokens.
 * delim need not remain constant from call to call.
 * On return, *stringp points past the last NUL written (if there might
 * be further tokens), or is NULL (if there are definitely no moretokens).
 *
 * If *stringp is NULL, strsep returns NULL.
 char *strsep(char **stringp, const char *delim)
{
    char *s;
    const char *spanp;
    int c, sc;
    char *tok;
    if ((s = *stringp)== NULL)
        return (NULL);
    for (tok = s;;) {
        c = *s++;
        spanp = delim;
        do {
            if ((sc =*spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *stringp = s;
                return (tok);
            }
        } while (sc != 0);
    }
}
 
 */
	while(token != NULL)
	{
		tokens[position] = token;
		position++;

		if(position >= bufsize)
		{
			bufsize += lsh_tok_bufsize;
			tokens = realloc(tokens,bufsize * sizeof(char*));
			if(!tokens)
			{
				fprintf(stderr,"lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL,lsh_tok_delim);
	}
	tokens[position] = NULL;
	//注意最后一个要为NULL
	return tokens;
}

int lsh_launch(char **args)
{
	pid_t pid,wpid;
	int status;

	pid = fork();
	//克隆一个原本的进程
	//子进程返回0
	//父进程返回子进程的ID
	if(pid == 0)
	{
		if(execvp(args[0],args) == -1)
						//从当前进程中把当前程序的机器指令清除，然后在空的进程中载入调用时指定的程序代码，最后运行这个新的程序。
						//运行失败返回-1
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid < 0)
	{
		perror("lsh");
	}
	else
	{
		do{
			wpid = waitpid(pid,&status,WUNTRACED);
			//waitpid()会暂时停止目前进程的执行，直到有信号来到或子进程结束。
			//WUNTRACED如果子进程已经停止（但未通过ptrace进行跟踪），它也返回。即使未指定此选项，也会提供已停止的跟踪子项的状态。
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
		//WIFEXITED(status) 这个宏用来指出子进程是否为正常退出的，如果是，它会返回一个非零值。
		//WEXITSTATUS(status) 当WIFEXITED返回非零值时，我们可以用这个宏来提取子进程的返回值，如果子进程调用exit(5)退出，WEXITSTATUS(status)就会返回5；如果子进程调用exit(7)，WEXITSTATUS(status)就会返回7。请注意，如果进程不是正常退出的，也就是说，WIFEXITED返回0，这个值就毫无意义。
	}

	return 1;
}

int lsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
						// int chdir(const char *path);
						// 成功返回1，失败返回0
      perror("lsh");
			//void perror(const char *str)
    }
  }
  return 1;
}

int lsh_help(char **args)
{
  int i;
  printf("Stephen Brennan's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int lsh_exit(char **args)
{
  return 0;
}

int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
						//extern int strcmp(const char *s1,const char *s2);
						//当s1<s2时，返回为负数；
						//当s1=s2时，返回值= 0；
						//当s1>s2时，返回正数。
      return (*builtin_func[i])(args);
    }
  }

  return lsh_launch(args);
}
