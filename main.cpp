#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<windows.h>
#include<iomanip>
#include"print_font.h"
using namespace std;
int count_game=0;
int win=0;
class game_play{
private:
    char topic;
    char* file_name;
    int len;
    int emh;
    char word[20];
    char w_space[20];
    char spac_word[20];
public:
    int u_win=0;
    int len_c;
    void chose(char&);
    void get_word(ifstream&);
    void show_blank();
    void spell_check();
    void draw_hangman(int&);
    void chos_level();
};
int main()
{
    char t_chos;
    char rept;
    while(1)
    {
        game_play* game=new game_play;
        extern char* w_or_l;
        extern char draw_body[10];
        system("cls");
        game->chos_level();
        print1();
        print2();
        t_chos=getch();
        system("cls");
        game->chose(t_chos);
        game->show_blank();
        play_print();
        game->spell_check();
        system("cls");
        if(game->u_win)
        {
            count_game++;
            win++;
            w_or_l="you win";
        }
        else
        {
            count_game++;
            w_or_l="you lose";
        }
        play_print();
        reset_drawing();
        delete game;
        cout<<"\n\nplay again ? Y to continue : ";
        rept=getch();
        if(rept!='y')
            break;
    }
    return 0;
}
void game_play::chose(char& topic)
{
    this->topic=topic;
    ifstream infile;
    if(emh==0)
    {
        switch(this->topic)
        {
            case '1':
            {
                file_name="./easy/fruit.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            case '2':
            {
                file_name="./easy/country.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            case '3':
            {
                file_name="./easy/programing_language.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            default:
                cout<<"invalid input";
        }
    }

    if(emh==1)
    {
        switch(this->topic)
        {
            case '1':
            {
                file_name="./medium/fruit.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            case '2':
            {
                file_name="./medium/country.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            case '3':
            {
                file_name="./medium/programing_language.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            default:
                cout<<"invalid input";
        }
    }

    if(emh==2)
    {
        switch(this->topic)
        {
            case '1':
            {
                file_name="./hard/fruit.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            case '2':
            {
                file_name="./hard/country.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            case '3':
            {
                file_name="./hard/programing_language.txt";
                infile.open(file_name);
                get_word(infile);
                infile.close();
                break;
            }
            default:
                cout<<"invalid input";
        }
    }
}
void game_play::get_word(ifstream& infile)
{
    int i=0;
    int pil;
    srand(time(0));
    while(infile.getline(word,20))
        i++;
    pil=rand()%i+1;
    i=0;
    infile.close();
    infile.open(file_name);
    //infile.clear();
    //infile.seekg(0,ios::beg);
    while(infile.getline(word,20))
    {
        i++;
        if(i==pil)
            break;
    }
}
void game_play::show_blank()
{
    int i=0;
    int len;
    int font=0;
    extern char theme[20];
    extern char* hide;
    for(i=0;i<strlen(file_name);i++)
    {
        if(file_name[i]=='.')
        {
            theme[i]='\0';
            break;
        }
        else
            theme[i]=toupper(file_name[i]);
    }
    this->len=strlen(word);
    len=(strlen(word)*2);
    for(i=0;i<=len;i++)
    {
        if(i==len)
        {
            this->w_space[i]='\0';
            spac_word[i]='\0';
        }
        else if((i%2==0)&& i<len)
        {
            this->w_space[i]='_';
            spac_word[i]=word[font];
            font++;
        }
        else if((i%2==1)&&i<len)
        {
            this->w_space[i]=' ';
            spac_word[i]=' ';
        }
    }
    hide=w_space;
    len_c=len;
}
void game_play::spell_check()
{
    extern char* hide;
    extern char* w_or_l;
    char same_font[40];
    int i=0;
    int com_word=0;
    int com_fals=0;
    char wit_spac=' ';
    char user_in;
    while(1)
    {
        sm_font:
        int not_found=1;
        cout<<"\n\ninput your font : ";
        user_in=getch();
        for(i=0;i<40;i++)
        {
            if(user_in==same_font[i])
            {
                w_or_l="same font";
                system("cls");
                play_print();
                goto sm_font;
            }
        }
        for(i=0;i<len_c;i++)
        {
            if(spac_word[i]==user_in)
            {
                w_space[i]=user_in;
                same_font[com_word]=user_in;
                com_word++;
                not_found=0;
            }
        }
        if(not_found)
        {
            com_fals++;
            draw_hangman(com_fals);
        }
        system("cls");
        play_print();
        if(com_word==this->len)
        {
            this->u_win=1;
            break;
        }
        if(com_fals==9)
            break;
    }
}
void game_play::draw_hangman(int& d_fals)
{
    extern char draw_body[10];
    if(d_fals==1)
        draw_body[0]='\\';
    else if(d_fals==2)
        draw_body[1]='/';
    else if(d_fals==3)
        draw_body[2]='|';
    else if(d_fals==4)
        draw_body[3]='|';
    else if(d_fals==5)
        draw_body[4]='|';
    else if(d_fals==6)
        draw_body[5]='|';
    else if(d_fals==7)
        draw_body[6]='/';
    else if(d_fals==8)
        draw_body[7]='\\';
    else if(d_fals==9)
        draw_body[8]='X';
}
void game_play::chos_level()
{
    int i=0;
    char* lev[3];
    char* arrow="->";
    char* arrow_2="<-";
    unsigned char con;
    int arw=0;
    for(i=0;i<3;i++)
    {
        char* w_lev=new char[7];
        if(i==0)
            w_lev="easy";
        else if(i==1)
            w_lev="medium";
        else if(i==2)
            w_lev="hard";
        lev[i]=w_lev;
    }
    while(1)
    {
        cout<<setw(38)<<"choose your level\n\n";
        for(i=0;i<3;i++)
        {
            if(arw==i)
                cout<<setw(28)<<arrow<<lev[i]<<arrow_2<<endl;
            else
                cout<<setw(28)<<lev[i]<<endl;
            cout<<endl<<endl;
        }
        con=getch();
        if(con=='s'&&(arw>=0&&arw<2))
            arw++;
        else if(con=='w'&&(arw>0&&arw<=2))
            arw--;
        else if(con==0X0D)//=\r =0X0D =13
            break;
        system("cls");
    }
    system("cls");
    this->emh=arw;
}















































