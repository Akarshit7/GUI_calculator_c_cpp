#pragma once

#include<windows.h>
#include<cstring>
#include <iostream>
#include<stdio.h>
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define GENERATE_BUTTON 4
#define OPEN_FILE 5
#define SAVE_FILE 6
#define ONE 11
#define TWO 12
#define THREE 13
#define FOUR 14
#define FIVE 15 
#define SIX 16
#define SEVEN 17
#define EIGHT 18
#define NINE 19
#define PLUS_BTN 21
#define MINUS_BTN 22
#define MULTIPLY_BTN 23
#define DIVIDE_BTN 24
#define CLR_BTN 25
#define ZERO 20
#define PERIOD 26








LRESULT CALLBACK Windowprocedure(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK Dialogprocedure(HWND,UINT,WPARAM,LPARAM);
void registerDialogClass(HINSTANCE);
void displaydialog(HWND);
void addmenus(HWND);
void Addcontrols(HWND);
void open_file(HWND);
void display_file(char* path);
void save_file(HWND hWnd);
void write_file(char * path);
void set_input_text(char*,char curr[]);
int charTointeger(char out[]);
char* convertIntegerToChar(int N);



