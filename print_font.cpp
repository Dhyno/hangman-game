#include<iostream>
#include<iomanip>
#include<windows.h>
#include"print_font.h"
using namespace std;
char theme[20]={NULL};//theme of topic.
char draw_body[10]={' '};
char* hide;//hide a word
char* w_or_l="      ";
extern int count_game;
extern int win;
void reset_drawing()
{
    for(int i=0;i<10;i++)
        draw_body[i]={' '};
}
void print1()
{
    cout<<"###################################\n";
    cout<<"##  SIMPLE HANGMAN CONSOLE GAME  ##\n";
    cout<<"###################################\n\n";
}
void play_print()
{
    cout<<"################################\n";
    cout<<"##                          "<<draw_body[4]<<"                      THEME : "<<theme<<endl;
    cout<<"##                          "<<draw_body[5]<<endl;
    cout<<"##                          "<<draw_body[8]<<endl;
    cout<<"##                         "<<draw_body[6]<<draw_body[3]<<draw_body[7]
    <<"                     COUNT GAME : "<<count_game<<endl;
    cout<<"##                          "<<draw_body[2]<<endl;
    cout<<"##                         "<<draw_body[1]<<" "<<draw_body[0]<<endl;
    cout<<"##                                                 WIN : "<<win<<endl;
    cout<<"##\n";
    cout<<"##\n";
    cout<<"##\n";
    cout<<"##\n";
    cout<<"##         "<<hide<<endl;
    cout<<"#############################################################\n";
    cout<<"##                                                         ##\n";
    cout<<"##"<<setw(26)<<"++"<<w_or_l<<"++\n";
    cout<<"##                                                         ##\n";
    cout<<"#############################################################\n";
}

void print2()
{
    cout<<"################################\n";
    cout<<"##                          |                      choose topic\n";
    cout<<"##                          |\n";
    cout<<"##                          |\n";
    cout<<"##                          0                      1.Country\n";
    cout<<"##                         /|\\\n";
    cout<<"##                          |\n";
    cout<<"##                         / \\\                     2.Fruit\n";
    cout<<"##\n";
    cout<<"##\n";
    cout<<"##\n";
    cout<<"##                                                 3.Programing Language\n";
    cout<<"##\n";
    cout<<"##\n";
    cout<<"#############################################################\n";
    cout<<"#############################################################\n";
    cout<<"\nchoose topic : ";
}







