#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<string>
using namespace std;
int cou(){
                int y = 0;
                ifstream op;
                op.open("words.txt");
                string ca;
                while(op.eof()==0){
                    getline(op,ca);
                    y++;
                }
                op.clear();
                op.seekg(0,ios::beg);
                op.close();
                return y;
}
class game{
    private:
        int wrongCount;
        int n;
        int *c;
        int q;
        string choosenword;
    public:
            game(){}
            game(int a){
                wrongCount = 0;
                q = 0;
                ifstream op;
                op.open("words.txt");
                srand (time(NULL));
                int v1 = rand() % a;
                int n = 0;
                string ch;
                while(op.eof()==0){
                getline(op,ch);
                if(n==v1){
                    choosenword = ch;
                }
                n++;
                }
                op.close();
            }
            void displayHangman(int a){
                if(a == 0)
                    cout<< "---------" << endl << "|"  << endl<< "|" << endl<< "|" << endl<< "|" << endl<< "|" << endl;
                else if(a==1)
                    cout<< "---------" << endl << "| \t O"  << endl<< "|" << endl<< "|" << endl<< "|" << endl<< "|" << endl;
                else if(a==2)
                    cout<< "---------" << endl << "| \t O"  << endl<< "|\t | " << endl<< "| \t |" << endl<< "| " << endl<< "|" << endl;
                else if(a==3)
                    cout<< "---------" << endl << "| \t O"  << endl<< "|\t/|\\ " << endl<< "| \t |" << endl<< "|" << endl<< "|" << endl;
                else
                    cout<< "---------" << endl << "| \t O"  << endl<< "|\t/|\\ " << endl<< "| \t |" << endl<< "|\t/ \\ " << endl<< "|" << endl;
            }
            void wrongCheck(){
                n = choosenword.size();
                c = new int[n];
                srand (time(NULL));
                int v1 = rand() % n;
                int v2 = rand() % n;
                for(int i=0; i<n; i++){
                if(choosenword[v1]==choosenword[i]||choosenword[v2]==choosenword[i])
                    c[i] = 1;
                else
                    c[i] = 0;
                }
                while(wrongCount<4&&q!=n){
                    system("cls");
                displayHangman(wrongCount);
                for(int i=0;i<n;i++)
                {
                    if(c[i] == 1)
                        cout << choosenword[i];
                    else
                        cout << " _ ";
                }
                cout << endl << "Enter the alphabet: ";
                char cha;
                cin >> cha;
                int y=0;
                for(int i=0;i<n;i++){
                    if(cha==choosenword[i]||cha+32==choosenword[i]){
                        c[i] = 1;
                        y = 1;
                    }
                }
                if(y==0)
                    wrongCount++;
                q=0;
                for(int i=0;i<n;i++)
                {
                    if(c[i] == 1)
                        q++;
                }
                }
            }
            void resultDisplay(){
                if(wrongCount==4){
                    system("cls");
                    displayHangman(wrongCount);
                    cout << "GAME OVER!!! THE ANSWER IS: " << choosenword << endl;
                }
                if(q==n){
                    system("cls");
                    displayHangman(wrongCount);
                    cout << "CONGRATULATIONS!!! THE ANSWER IS: " << choosenword << endl;
                }
            }
};
int main(){
    char ch;
    int a = cou();
    do{
    system("cls");
    game player(a);
    player.wrongCheck();
    player.resultDisplay();
    cout << "Do you want to play again?(y/n)";
    cin >> ch;
    }while(ch=='y'||ch=='Y');
}
