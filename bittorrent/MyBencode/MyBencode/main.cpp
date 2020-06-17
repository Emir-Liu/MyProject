
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

enum data_type{
    data_str,
    data_int,
    data_lis,
    data_dic,
    data_end
};

//节点数据结构分析
//*next_node和*pre_node分别指向下面和上面的节点
//type代表当前节点的类型
//*char_data,int_data,*list_node分别表示数据

typedef struct node{
    struct node *next_node =NULL;
    struct node *pre_node=NULL;

    enum data_type type = data_str;

    char *char_data = NULL;
    int int_data = 0;
    struct node *list_node = NULL;

}build_node;

//char *tmp = "5:hello";
//char *tmp = "i123e";
char *tmp = "l5:helloli123eei123ee5:hellol5:helloe5:hello";

char key[] ={
    'i',
    'l',
    'd',
    'e'
};

//node_data为之前节点的地址，mid为输入字符串的地址
void decode(build_node *node_data,char *mid);

//输出节点
void check(build_node node_data);

//各个指令的解析
char *fun_str(build_node *node_data,char *mid);
char *fun_int(build_node *node_data,char *mid);
char *fun_lis(build_node *node_data,char *mid);
char *fun_dic(build_node *node_data,char *mid);
char *fun_end(build_node *node_data,char *mid);
char *(*key_fun[])(build_node *node_data,char *mid)={
    fun_int,
    fun_lis,
    fun_dic,
    fun_end
};


int main()
{
    //node_index节点用于记录整条命令节点
    build_node node_index;
    //解析指令
    decode(&node_index,tmp);
    check(node_index);

    return 0;
}

void decode(build_node *node_data,char *mid)
{
    //维护node节点，将节点串联起来
    build_node *node_tmp = (build_node *)malloc(sizeof(build_node ));

    (*node_data).next_node = node_tmp;
    (*node_tmp).pre_node = node_data;

    (*node_tmp).list_node = (*node_data).list_node;

    char *next;
    if(isdigit(*mid))
    {
        next = fun_str(node_tmp,mid);
    }
    else
    {
        for(int i = 0;i < 4;i++)
        {
            if( *mid == key[i])
            {
                next = (*key_fun[i])(node_tmp,mid);
                break;
            }
        }
    }

    if( *next == '\0')
    //NULL = '\0'
    {
        return;
    }
    else
    {
        decode(node_tmp,next);
    }

}

void check(build_node node_index)
{

    printf("string = %s\n",tmp);
    do{
        node_index = *(node_index).next_node;

        build_node tmp_node = node_index;
        while(tmp_node.list_node != NULL )
        {
            printf("\t");
            tmp_node = *(*tmp_node.list_node).pre_node;
        }
        if((node_index).type == data_str)
        {
            printf("str:");
            printf("%s",(node_index).char_data);
        }
        else if((node_index).type == data_int)
        {
            printf("int:");
            printf("%d",(node_index).int_data);
        }
        else if((node_index).type == data_lis )
        {
            printf("list:");
        }
        printf("\n");
    }while((node_index).next_node != NULL);
    printf("hello the world\n");
}
//返回该指令最后一位的偏移量
char *fun_str(build_node *node_data,char *mid)
{
    (*node_data).type = data_str;
    int pointer = 0;
    int tmp_num = 0;
    do{
        tmp_num = tmp_num * 10 + (*(mid + pointer ) - '0');
        pointer++;
    }while(*(mid + pointer) != ':' );
    char *a = (char *)malloc(tmp_num*sizeof(char));

    for(int i = 0;i < tmp_num;i++)
    {
        a[i] = *(mid + pointer + i + 1);
    }
    (*node_data).char_data = a;
    (*node_data).next_node = NULL;
    return mid+pointer+tmp_num+1;
}

char *fun_int(build_node *node_data,char *mid)
{
    int sign = 1;
    int pointer = 1;
    int tmp_num = 0;
    (*node_data).type = data_int;
    while( *(mid+pointer) != 'e' )
    {
        if((pointer == 1) & (*(mid + pointer) == '-'))
        {
            sign = -1;
        }
        else
        {
            tmp_num = tmp_num * 10 + ( *(mid + pointer) - '0' );
            pointer++;
        }
    }
    tmp_num = sign * tmp_num;
    (*node_data).int_data = tmp_num;
    (*node_data).next_node = NULL;
    return mid+pointer+1;
}

char *fun_lis(build_node *node_data,char *mid)
{
    (*node_data).type = data_lis;
    (*node_data).list_node = node_data;
    return mid+1;
}

char *fun_dic(build_node *node_data,char *mid)
{
    return mid+1;
}

char *fun_end(build_node *node_data,char *mid)
{
    (*node_data).type = data_end;
    (*node_data).list_node = (*(*(*node_data).list_node).pre_node).list_node;
    return mid+1;
}
