//
//  Snake.c
//  Snake
//
//  Created by Cobi Mom on 10/19/18.
//  Copyright © 2018 Cobi Mom. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>


//CONSTANTS
#define EMPTY_SPACE ' '
#define FOOD 'O'
#define SNAKEBODYPART '*'
#define COLUMNS 25
#define ROWS 25
#define TRUE 1

typedef struct node{
    char data;
    struct node * next;
    struct node * prev;
    int row;
    int col;
}node;

//VARIABLES
int size;
char graph[COLUMNS][ROWS];
char* ptr;
node * head; // add head node

//PROTOTYPES

void startSnake();

//initialize the environment of the game
void startEnvironment();

//make a piece of food spawn in a random spot on the gameboard
void makeFood();

//Draw character to the screen
//position is (x,y)
void draw_character(int x, int y, char use);

void add();

void mov(char movee);

void main()
{
    int up = 0;
    int left = 0;
    int down = 0;
    int right = 0;
    
    //Setup screen for ncurses
    initscr();
    refresh();
    
    //make the map
    startEnvironment();
    
    startSnake();
    
    //generate a piece of food on at a random spot on the map
    makeFood();
    
    while(TRUE)
    {
        int dir = 0;
        //scan for dpad input
        scanf("%d, %d, %d, %d", &up, &left, &down, &right);
        
        //if up is pressed, return 1
        if(up == 1)
        {
            dir = 1;
        }
        
        //if left is pressed, return 2
        else if(left == 1)
        {
            dir = 2;
        }
        
        //if down is pressed, return 3
        else if(down == 1)
        {
            dir = 3;
        }
        
        //if right is pressed, return 4
        else if(right == 1)
        {
            dir = 4;
        }
    }
}

//initialize the environment of the game
void startEnvironment()
{
    int i = 0;
    int j = 0;
    
    //loop through and make every spot on our gameboard an empty space
    for(i = 0; i < COLUMNS; i++)
    {
        for(j = 0; j < ROWS; j++)
        {
            draw_character(i, j, EMPTY_SPACE);
        }
    }
}

//make a piece of food spawn in a random spot on the gameboard
void makeFood()
{
    srand(time(NULL));
    //generate random number between 3-22
    int randVert = rand() % (23 - 3) + 3;
    int randHori = rand() % (23 - 3) + 3;
    
    //value at random location is now a piece of food
    graph[randVert][randHori] = FOOD;
    draw_character(randVert, randHori, FOOD);
}

//Draw character to the screen
//position is (x,y)
void draw_character(int x, int y, char use)
{
    mvaddch(y, x, use);
    refresh();
}

//read an input from the dualshock dpad
//char direction()
//{
//    int up = 0;
//    int left = 0;
//    int down = 0;
//    int right = 0;
//
//    while(TRUE)
//    {
//        //scan for dpad input
//        scanf("%d, %d, %d, %d", &up, &left, &down, &right);
//
//        //if up is pressed, return u
//        if(up == 1)
//        {
//            return 'u';
//        }
//
//        //if left is pressed, return l
//        else if(left == 1)
//        {
//            return 'l';
//        }
//
//        //if down is pressed, return d
//        else if(down == 1)
//        {
//            return 'd';
//        }
//
//        //if right is pressed, return r
//        else if(right == 1)
//        {
//            return 'r';
//        }
//    }
//}

void mov(char movee)
{
    node * p = head;
    while(p->next != NULL){
        p= p->next;
    }
    
    // might have to move while loop
    while(p->prev != head){
        p->row = p->prev->row;
        p->col = p->prev ->col;
        p= p->prev;
    }
    p->row = head->row;
    p->col = head->col;
    
    switch(movee)
    {
        case 'u':
            
            head->row = head->row +1; //add if contraints
            break;
            
        case 'd':
            
            head->row = head->row - 1; //add if contraints
            break;
            
        case 'r':
            head->col = head->col ; //add if contraints
            break;
            
        case 'l':
            head->col = head->col - 1; //add if contraints
            break;
    }
    
}

void add()
{
    size++;
    node * temp = NULL;
    node * p = NULL;
    temp= (node*)malloc(sizeof(node));
    temp->data = SNAKEBODYPART;
    
    
    p=head;
    while(p->next !=NULL)
        p=p->next;
    p->next = temp;
    
    temp->next = NULL;
    temp->prev = p;
    temp->col = NULL;
    temp->row = NULL;
    
    
    
}

void

void startSnake(){
    size=1;
    head = (node*)malloc(sizeof(node));
    head->data = SNAKEBODYPART;
    head->next = NULL;
    head->prev = NULL;
    head->row = 0;
    head->col = 0;
    graph[head->row][head->col]= head->data;
    
}


