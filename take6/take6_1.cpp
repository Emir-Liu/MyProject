#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define num_of_chosen 44
#define num_of_card 104

bool card_is_chosen[num_of_card] = {false};
int card_of_player[4][10] = {0};
int card_of_table[4][6] = {0};
int card_of_chosen[num_of_chosen] = {0};

void random_cards();
void choose_cards();
void order_cards();

void show_chosen_cards();
void show_cards();
void show_table();

int main()
{
    random_cards();
    choose_cards();

    show_chosen_cards();
    show_cards();
    show_table();

    order_cards();
    show_cards();
	return 0;
}

//进行洗牌的操作
void random_cards()
{
	srand(time(NULL));
	for(int i = 0;i < num_of_chosen;i++)
	{
		int tmp_card = 0;
		tmp_card = rand()%num_of_card+1;
		if(card_is_chosen[tmp_card] == true)
		{
			i--;
		}
		else
		{
			card_is_chosen[tmp_card] = true;
			card_of_chosen[i] = tmp_card;
		}
	}
}
//玩家抽牌
void choose_cards()
{
	for(int i = 0;i < 40 ;i++)
	{
		card_of_player[i/10][i%10] = card_of_chosen[i];
	}
	card_of_table[0][0] = card_of_chosen[40];
	card_of_table[1][0] = card_of_chosen[41];
	card_of_table[2][0] = card_of_chosen[42];
	card_of_table[3][0] = card_of_chosen[43];
}
//显示洗之后的牌
void show_chosen_cards()
{
	for(int i = 0;i < 44 ;i++)
	{
		printf("%d ",card_of_chosen[i] );
	}
	printf("\n");
}
//显示玩家手上的牌
void show_cards()
{
	for(int i = 0; i < 4 ;i++)
	{
		printf("player i :\n");
		for(int j = 0; j < 10 ;j++)
		{
			printf("%d ",card_of_player[i][j]);
		}
		printf("\n");
	}
}
//显示桌面上的牌
void show_table()
{
    for(int i = 0;i < 4;i++)
    {
        printf("line %d:",i);
        for(int j = 0;j < 10;j++)
        {
            if( card_of_table[i][j] == 0)
            {
                break;
            }
            else
            {
                printf("%d ",card_of_table[i][j]);
            }
        }
        printf("\n");
    }
}
//对玩家手上的牌进行排序
void order_cards()
{
    for(int i = 0 ;i < 4;i++)
    {
        for(int j = 0;j<10;j++)
        {
            for(int k = j+1;k <10;k++)
            {
                if(card_of_player[i][j] > card_of_player[i][k] )
                {
                    int tmp_swap = 0;
                    tmp_swap = card_of_player[i][j];
                    card_of_player[i][j] = card_of_player[i][k];
                    card_of_player[i][k] = tmp_swap;
                }
            }
        }
    }
}

