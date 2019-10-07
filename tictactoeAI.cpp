#include<bits/stdc++.h>
using namespace std;
bool chkDiagonal1(char board[][3],char ch)
{
    int k;
    for(k=0;k<3;k++)
    {    
        if(board[k][k]==ch)
            continue;
        else
            break;
    }
    if(k==3)
        return true;
    else
        return false;
}
bool chkDiagonal2(char board[][3],char ch)
{
    int k;
    for(k=0;k<3;k++)
        if(board[k][2-k]==ch)
            continue;
        else
            break;
    if(k==3)
        return true;
    else
        return false;        
}
bool check(char board[][3],int r,int c)
{
    char ch=board[r][c];
    int k;
    for(k=0;k<3;k++)
    {
        if(board[k][c]==ch)
            continue;
        else
            break;
    }
    if(k==3)
        return true;
    for(k=0;k<3;k++)
    {
        if(board[r][k]==ch)
            continue;
        else
            break;
    }
    if(k==3)
        return true;
    if(r==1 && c==1)
        return chkDiagonal1(board,ch)||chkDiagonal2(board,ch);
    else if(r==c)
        return chkDiagonal1(board,ch);
    else if(r+c==2)
        return chkDiagonal2(board,ch);
    else
        return false;
}
void printBoard(char board[][3])
{
    for(int i=0;i<3;i++)
    {
        cout<<"-------------"<<endl;
        for(int j=0;j<3;j++)
            printf("| %c ",board[i][j]);
        cout<<"|"<<endl;
    }
    cout<<"-------------"<<endl;
}
int main()
{
    cout<<"Choose a mode:"<<endl;
    cout<<"1)Easy\n2)Hard\n3)Multiplayer"<<endl;
    int choice;
    cin>>choice;
    char board[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
    if(choice==1)
    {
        printBoard(board);
        int cnt=0;
        while(1)
        {
            int r,c;
            bool invalidFlag=0,winFlag=0;
            cout<<"Your Turn:";
            cin>>r>>c;
            r--;
            c--;
            if(board[r][c]!=' ')
            {
                cout<<"Invalid move"<<endl;
                invalidFlag=1;
            }
            else
            {
                cnt++;
                board[r][c]='X';
                printBoard(board);
            }
            winFlag=check(board,r,c);
            if(winFlag)
            {
                cout<<"You Win!"<<endl;
                break;
            }
            else
            {
                if(invalidFlag)
                    continue;
                else
                {
                    while(cnt!=9)
                    {
                        srand(time(0));
                        r=rand()%3;
                        c=rand()%3;
                        if(board[r][c]==' ')
                        {
                            cout<<"Computer's Turn:"<<endl;
                            board[r][c]='O';
                            printBoard(board);
                            cnt++;
                            break;
                        }
                    }
                }
                if(check(board,r,c))
                {
                    cout<<"Computer Wins!"<<endl;
                    break;
                }
                else if(cnt==9)
                {
                    cout<<"Match Draw"<<endl;
                    break;
                }
            }  
        }        
    }
    else
    {
        /*write code here*/
        cout<<"This Section is under development"<<endl;
    }
    
}