#include<windows.h>
#include<string>
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
#define ENTER_BTN 25
#define ZERO 20
#define PERIOD 26








LRESULT CALLBACK Windowprocedure(HWND,UINT,
WPARAM,LPARAM);
LRESULT CALLBACK Dialogprocedure(HWND,UINT,WPARAM,LPARAM);
void registerDialogClass(HINSTANCE);
void displaydialog(HWND);
void addmenus(HWND);
void Addcontrols(HWND);
void open_file(HWND);
void display_file(char* path);
void save_file(HWND hWnd);
void write_file(char * path);
HMENU hMenu;
HWND hName,hAge,hOut,hMainWindow,hOpenFile;
HWND hInput,hOutput;


int CALLBACK WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR args,int ncmdshow){
    //std::string a="hello";
    //MessageBoxA(NULL,"hello","giu",MB_DEFAULT_DESKTOP_ONLY);
    WNDCLASSW wc = {0};
    wc.hbrBackground= (HBRUSH) COLOR_WINDOW;
    wc.hCursor= LoadCursor(NULL,IDC_ARROW);
    wc.hInstance =hInst;
    wc.lpszClassName = L"mywindowclass";
    wc.lpfnWndProc = Windowprocedure;
    
    RegisterClassW(&wc);

    /*if(!RegisterClassW(&wc)){
        return -1;
    }*/
    registerDialogClass(hInst);
    
    hMainWindow= CreateWindowW(L"mywindowclass",L"My window",WS_OVERLAPPEDWINDOW|WS_VISIBLE,100,100,450,500,NULL,NULL,NULL,NULL);
    
    //MessageBoxW(NULL,L"hi",L"hello",MB_OK);
    MSG msg = {0};
    while (GetMessage(&msg,NULL,NULL,NULL)){
           TranslateMessage(&msg);
           DispatchMessage(&msg);
    }
    
    
    
    return 0;
}

LRESULT CALLBACK Windowprocedure(HWND hWnd,UINT msg,
WPARAM wp,LPARAM lp){
    int ival_msgbox;
    switch (msg)
    {
    case WM_COMMAND:
        switch(wp){
            case FILE_MENU_EXIT:
            ival_msgbox = MessageBoxW(hWnd,L"Are you sure",L"wait",MB_YESNO | MB_ICONEXCLAMATION| MB_ICONERROR);
            if(ival_msgbox==IDYES){
                DestroyWindow(hWnd);
            }
            break;
            case FILE_MENU_NEW:
                displaydialog(hWnd);
                MessageBeep(MB_ICONINFORMATION);
                break;
            case GENERATE_BUTTON:
                char name[100],age[100],out[200];
                GetWindowTextA(hName,name,100);
                GetWindowTextA(hAge,age,100);
                if(strcmp(name,"")==0 || strcmp(age,"")==0){
                    ival_msgbox= MessageBoxW(hWnd,L"pls enter stuff",NULL,MB_ABORTRETRYIGNORE);
                    switch (ival_msgbox)
                    {
                    case IDABORT:
                        DestroyWindow(hWnd);
                        break;
                    case IDRETRY:
                    return 0;
                    break;
                    case IDIGNORE:
                        break;
                    
                }
            case OPEN_FILE:
                open_file(hWnd);
                break;

            case SAVE_FILE:
                save_file(hWnd);
                break;
                }
            strcpy(out,name);
            strcat(out," is ");
            strcat(out,age);
            strcat(out," years old. ");
            SetWindowTextA(hOut,out);
            break;
        }
        break;
    case WM_CREATE:
        
        addmenus(hWnd);
        Addcontrols(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}

void addmenus(HWND hWnd){
    hMenu= CreateMenu();
    HMENU hFilemenu = CreateMenu();
    HMENU hSubmenu = CreateMenu();
    
    AppendMenuA(hSubmenu,MF_STRING,NULL,"change title");


    AppendMenuA(hFilemenu,MF_STRING,FILE_MENU_NEW,"new");
    AppendMenuA(hFilemenu,MF_POPUP,(UINT_PTR)hSubmenu,"open submenu");
    AppendMenuA(hFilemenu,MF_SEPARATOR,NULL,NULL);
    AppendMenuA(hFilemenu,MF_STRING,FILE_MENU_EXIT,"exit");


    AppendMenuA(hMenu, MF_POPUP,(UINT_PTR)hFilemenu,"file");
    AppendMenuA(hMenu, MF_STRING,NULL,"help");
    SetMenu(hWnd,hMenu);
}

void  Addcontrols(HWND hWnd){
    hInput=CreateWindowW(L"edit",L"",WS_VISIBLE| WS_CHILD| WS_BORDER,50,50,300,40,hWnd,NULL,NULL,NULL);
    hOutput=CreateWindowW(L"edit",L"",WS_VISIBLE| WS_CHILD| WS_BORDER,50,100,300,40,hWnd,NULL,NULL,NULL);
    
    CreateWindowW(L"Static",L": INPUT",WS_VISIBLE| WS_CHILD,355,55,80,38,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L": OUTPUT",WS_VISIBLE| WS_CHILD,355,105,80,38,hWnd,NULL,NULL,NULL);
    //hAge=CreateWindowW(L"edit",L"",WS_VISIBLE| WS_CHILD| WS_BORDER,200,90,98,38,hWnd,NULL,NULL,NULL);

    CreateWindowW(L"button",L"/",WS_VISIBLE| WS_CHILD,50,170,70,50,hWnd,(HMENU)DIVIDE_BTN,NULL,NULL);
    CreateWindowW(L"button",L"*",WS_VISIBLE| WS_CHILD,125,170,70,50,hWnd,(HMENU)MULTIPLY_BTN,NULL,NULL);
    CreateWindowW(L"button",L"-",WS_VISIBLE| WS_CHILD,200,170,70,50,hWnd,(HMENU)MINUS_BTN,NULL,NULL);

    CreateWindowW(L"button",L"7",WS_VISIBLE| WS_CHILD,50,225,70,50,hWnd,(HMENU)SEVEN,NULL,NULL);
    CreateWindowW(L"button",L"8",WS_VISIBLE| WS_CHILD,125,225,70,50,hWnd,(HMENU)EIGHT,NULL,NULL);
    CreateWindowW(L"button",L"9",WS_VISIBLE| WS_CHILD,200,225,70,50,hWnd,(HMENU)NINE,NULL,NULL);

    CreateWindowW(L"button",L"4",WS_VISIBLE| WS_CHILD,50,280,70,50,hWnd,(HMENU)FOUR,NULL,NULL);
    CreateWindowW(L"button",L"5",WS_VISIBLE| WS_CHILD,125,280,70,50,hWnd,(HMENU)FIVE,NULL,NULL);
    CreateWindowW(L"button",L"6",WS_VISIBLE| WS_CHILD,200,280,70,50,hWnd,(HMENU)SIX,NULL,NULL);

    CreateWindowW(L"button",L"1",WS_VISIBLE| WS_CHILD,50,335,70,50,hWnd,(HMENU)ONE,NULL,NULL);
    CreateWindowW(L"button",L"2",WS_VISIBLE| WS_CHILD,125,335,70,50,hWnd,(HMENU)TWO,NULL,NULL);
    CreateWindowW(L"button",L"3",WS_VISIBLE| WS_CHILD,200,335,70,50,hWnd,(HMENU)THREE,NULL,NULL);

    CreateWindowW(L"button",L"0",WS_VISIBLE| WS_CHILD,50,390,145,50,hWnd,(HMENU)ZERO,NULL,NULL);
    CreateWindowW(L"button",L".",WS_VISIBLE| WS_CHILD,200,390,70,50,hWnd,(HMENU)PERIOD,NULL,NULL);

    CreateWindowW(L"button",L"+",WS_VISIBLE| WS_CHILD,275,170,70,105,hWnd,(HMENU)PLUS_BTN,NULL,NULL);
    CreateWindowW(L"button",L"Enter",WS_VISIBLE| WS_CHILD,275,280,70,160,hWnd,(HMENU)ENTER_BTN,NULL,NULL);
}

LRESULT CALLBACK DialogProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp){
    switch(msg){
         case WM_COMMAND:
         switch (wp)
         {
         case 1:
             EnableWindow(hMainWindow,true);
             DestroyWindow(hWnd);
             break;
         
         default:
             break;
         }
         break;
        case WM_CLOSE:
            DestroyWindow(hWnd);
            EnableWindow(hMainWindow,true);
            break;

        default:
         return DefWindowProcW(hWnd,msg,wp,lp);
         
    }
}



void registerDialogClass(HINSTANCE hInst){
    WNDCLASSW dialog = {0};
    dialog.hbrBackground= (HBRUSH) COLOR_WINDOW;
    dialog.hCursor= LoadCursor(NULL,IDC_CROSS);
    dialog.hInstance = hInst;
    dialog.lpszClassName = L"myDialogClass";
    dialog.lpfnWndProc = DialogProcedure;

    RegisterClassW(&dialog);
}

void displaydialog(HWND hWnd){

    HWND hDlg= CreateWindowW(L"myDialogClass",L"Dialog", WS_OVERLAPPEDWINDOW|WS_VISIBLE,400,400,200,200,hWnd,NULL,NULL,NULL);

    CreateWindowW(L"Button",L"close",WS_VISIBLE| WS_CHILD,20,20,100,40,hDlg,(HMENU)1,NULL,NULL);
    EnableWindow(hWnd,false);

}

void display_file(char* path){
    FILE * file;
    file= fopen(path,"rb");
    fseek(file,0,SEEK_END);
    int __size = ftell(file);
    rewind(file);
    char *data = new char[__size+1];
    fread(data,__size,1,file);
    data[__size]='\0';

    SetWindowText(hOpenFile,data);
    fclose(file);
    
}

void open_file(HWND hWnd){
    char filename_destination[100];

    OPENFILENAME ofn;
    ZeroMemory(&ofn,sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner= hWnd;
    ofn.lpstrFile = filename_destination;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = "all files\0*.*\0";
    ofn.nFilterIndex =1;

    GetOpenFileName(&ofn);
    display_file(ofn.lpstrFile);


}


void save_file(HWND hWnd){
    char filename_destination[100];

    OPENFILENAME ofn;
    ZeroMemory(&ofn,sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner= hWnd;
    ofn.lpstrFile = filename_destination;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = "all files\0*.*\0";
    ofn.nFilterIndex =1;

    GetSaveFileName(&ofn);
    write_file(ofn.lpstrFile);

}

void write_file(char * path){
    FILE * file;
    file= fopen(path,"w");

    int __size =GetWindowTextLength(hOpenFile);
    char * data = new char[__size+1];
    GetWindowText(hOpenFile,data,__size+1);

    fwrite(data,__size+1,1,file);

    fclose(file);
}