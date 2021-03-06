#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

enum data_type{
    data_str,
    data_int,
    data_lis,
    data_dic
};
typedef struct node{
    struct node *pre_node ;
    struct node *next_node ;
    enum data_type type;
    int int_data;
    char *char_data;
}build_node;

//char *tmp = "5:hello";
char *tmp = "5:hello";

char key[] ={
    'i',
    'l',
    'd',
    'e'
};

void decode(build_node *node_data,char *mid);
void check(build_node node_index);
int fun_int(build_node *node_data,char *mid);
int fun_lis(build_node *node_data,char *mid);
int fun_dic(build_node *node_data,char *mid);
int fun_end(build_node *node_data,char *mid);

int fun_str(build_node *node_data,char *mid);
int (*key_fun[])(build_node *node_data,char *mid)={
    fun_int,
    fun_lis,
    fun_dic,
    fun_end
};
build_node node_index,node_data;

int main()
{
    node_index.next_node = &node_data;
    char *mid=tmp;
    int offset;
    if(isdigit(*mid))
    {
        offset = fun_str(&node_data,mid);
    }
    else
    {
        for(int i = 0;i < 4;i++)
        {
            if( *mid == key[i])
            {
                offset = (*key_fun[i])(&node_tmp,mid);
            }
        }
    }
    if( *(mid+offset+1) == '\0')
    //NULL = '\0'
    {
        return;
    }
    else
    {
        decode(&node_tmp,mid+offset+1);
    }
    check(node_index);

    return 0;
}

void decode(build_node *node_data,char *mid)
{
    build_node node_tmp;
    node_tmp.next_node = NULL;
    (*node_data).next_node = &node_tmp;
    int offset;
    if(isdigit(*mid))
    {
        offset = fun_str(&node_tmp,mid);
    }
    else
    {
        for(int i = 0;i < 4;i++)
        {
            if( *mid == key[i])
            {
                offset = (*key_fun[i])(&node_tmp,mid);
            }
        }
    }
    if( *(mid+offset+1) == '\0')
    //NULL = '\0'
    {
        return;
    }
    else
    {
        decode(&node_tmp,mid+offset+1);
    }

}

void check(struct node node_index)
{
    printf("string = %s\n",tmp);
    do{
        node_index = *((node_index).next_node);
        if((node_index).type == data_str)
        {
            printf("str:");
            printf("%s\n",(node_index).char_data);
        }
        else if((node_index).type == data_int)
        {
            printf("int:");
            printf("%d\n",(node_index).int_data);
        }
    }while((node_index).next_node != NULL);
    printf("hello the world\n");
}
//返回该指令最后一位的偏移量
int fun_str(build_node *node_data,char *mid)
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
    return pointer+tmp_num;
}

int fun_int(build_node *node_data,char *mid)
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
    return pointer;
}

int fun_lis(build_node *node_data,char *mid)
{
    return 0;
}

int fun_dic(build_node *node_data,char *mid)
{
    return 0;
}

int fun_end(build_node *node_data,char *mid)
{
    return 0;
}
