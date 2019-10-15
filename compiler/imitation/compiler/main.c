#include <stdio.h>
#include <string.h>
//出现了问题，当string.h被注释掉之后，printf("%s ",args[i]);会出现错误Segmentation fault (core dumped)
#define line_bufsize 255
#define num_arg 32
#define arg_bufsize 32
#define split " \t\r\n\a"

int read_line(char *,int *);
void read_arg(char *,char **,int *);
FILE *fp = NULL;
int main()
{
    //打开文件
    fp = fopen("test.c","r");
    //用于存储行号，有利于Debug显示
    int num_line = 0;
    //printf("ok\n");
    //逐行读取数据
    while(1)
    {
        //申请空间存储行数据
        //动态大小待定
        char *line_buffer = malloc(sizeof(char)*line_bufsize) ;

        //判断文档是否已经读取完毕
        if( read_line(line_buffer,&num_line) == 0)
        {
            break;
        }

        //申请空间存放变量
        char **args = malloc(num_arg*sizeof(char*));

        //将每一行分解为多个输入变量
        read_arg(line_buffer,args,&num_line);

        //释放当前行的空间
        free(line_buffer);
    }
}

int read_line(char *line_buffer,int *num_line)
{
        //检测是否到达文档结束，结束返回0
        int flag = fgets(line_buffer,line_bufsize,fp);
        if(flag == 0 )
        {
            return 0;
        }
        (*num_line)++;
        return 1;
        //下面的用于检测是否能够正常读取一整行的数据
        //printf("%d %d %s\n",num_line,flag,line_buffer);
        //printf("%d %s\n",num_line,line_buffer);
}

void read_arg(char *line_buffer,char **args,int *num_line)
{
        char *arg ;
        int args_position = 0;
        arg = strtok(line_buffer,split);

        while(arg != NULL)
        {
            args[args_position] = arg;
            args_position++;
            arg = strtok(NULL,split);
        }
        args[args_position] = NULL;

        //以下用于检查是否能够正常工作
        printf("%5d ",*num_line);
        for(int i = 0;i < args_position;i++)
        {
            printf("%s ",args[i]);
        }
        printf("\n");
}
