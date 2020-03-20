#include<iostream>

using namespace std;

char board[50][50];//board
int n,x[50],y[50],soln=0;//n is the number of queens and x and y are the positions of queens

void initialize() // Initializing the board
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            board[i][j]='_';
        x[i]=-1;
        y[i]=-1;
    }
}
int legal(int i,int j) // To check the diagonal constraint of each placed queen
{
    for(int k=0;k<i;k++){
        if((abs(x[k]-i)==abs(y[k]-j)))
            return 0;
    }
    return 1;
}
void disp() // To display the board
{           //*** To calculate the number of solutions, just hide every occurrence of this function ***
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<' ';
        cout<<endl;
    }
    system("pause");
    system("cls");
}

int place(int q_placed){
    int check;
    for(int j=0;j<n;j++){
        check=0;
        for(int k=0;k<q_placed;k++){
            if(j==y[k]){
                check=1;
                break;
            }
        }
        if(check){
            //cout<<"Continued";
            //system("pause");
            continue;
        }
        if(legal(q_placed,j)){
            //cout<<"Legal";
            x[q_placed]=q_placed;
            y[q_placed]=j;
            board[x[q_placed]][y[q_placed]]='Q';
            q_placed++;
            //cout<<q_placed<<endl;
            //disp();
            q_placed=place(q_placed);
        }
        if(q_placed==n){
            cout<<"**Solution**\n\n";
            soln++;
            disp();
            q_placed--;
            board[x[q_placed]][y[q_placed]]='_';
            x[q_placed]=-1;
            y[q_placed]=-1;
            //cout<<"in middle solution"<<endl;
        }

    }
    if(q_placed==n)
        return n;
    q_placed--;
    board[x[q_placed]][y[q_placed]]='_';
    x[q_placed]=-1;
    y[q_placed]=-1;
    //cout<<"Loop ended, value of queen: "<<q_placed<<endl;
    //disp();
    return q_placed;
}

int main()
{
    int q_placed;
    cout<<"Enter the number of queens: ";
    cin>>n;
    system("cls");
    for(int i=0;i<n;i++){
        initialize();
        x[0]=0;
        y[0]=i;
        board[x[0]][y[0]]='Q';
        q_placed=1;
        //cout<<"Initial"<<endl;
        //disp();
        if(place(q_placed)==n){
            cout<<"**Solution**\n\n";
            soln++;
            disp();
        }
    }
    cout<<"\nTotal solutions: "<<soln<<endl<<endl;
}
