#include "header_file.h"




HMENU hMenu;
HWND hName,hAge,hOut,hMainWindow,hOpenFile;
HWND hOutput,hInput;

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
    char curr[100];
    char to_optput[100]={'0'};
    char* intermediate_array;
    long long int iInput=0;
    long long int iTemprary=0;
    long long int iOutput=0;
    int first_char;  //for multiplication button
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
            case ONE:
            set_input_text("1",curr);
            //std::cout<<curr<<std::endl;
            break;
            case TWO:
            set_input_text("2",curr);
             //std::cout<<curr<<std::endl;
            break;
            case THREE:
            set_input_text("3",curr);
             //std::cout<<curr<<std::endl;
            break;
            case FOUR:
            set_input_text("4",curr);
            break;
            case FIVE:
            set_input_text("5",curr);
            break;
            case SIX:
            set_input_text("6",curr);
            break;
            case SEVEN:
            set_input_text("7",curr);
            break;
            case EIGHT:
            set_input_text("8",curr);
            break;
            case NINE:
            set_input_text("9",curr);
            break;
            case ZERO:
            set_input_text("0",curr);
            break;
            case PLUS_BTN:
                set_input_text("",curr);   //important step
                SetWindowTextA(hInput,"");
                GetWindowTextA(hOutput,to_optput,100);
                iInput=charTointeger(curr);
                iOutput=charTointeger(to_optput);
                //std::cout<<iInput<<" "<<iOutput<<std::endl;
                iTemprary=iOutput+iInput;
                //std::cout<<iTemprary<<std::endl;
                delete [] intermediate_array;
                intermediate_array = convertIntegerToChar(iTemprary);
                //strcpy(intermediate_,curr);
                SetWindowTextA(hOutput,intermediate_array);
                
            break;
            case MINUS_BTN:
                set_input_text("",curr);   //important step
                SetWindowTextA(hInput,"");
                GetWindowTextA(hOutput,to_optput,100);
                iInput=charTointeger(curr);
                iOutput=charTointeger(to_optput);
                if (iOutput==0){
                    iTemprary=iInput;
                }
                else{
                    iTemprary=iOutput-iInput;
                }
                //std::cout<<iTemprary<<std::endl;
                delete [] intermediate_array;
                intermediate_array = convertIntegerToChar(iTemprary);
                //strcpy(intermediate_,curr);
                SetWindowTextA(hOutput,intermediate_array);
            break;
            case MULTIPLY_BTN:
                set_input_text("",curr);   //important step
                SetWindowTextA(hInput,"");
                GetWindowTextA(hOutput,to_optput,100);
                iInput=charTointeger(curr);
                iOutput=charTointeger(to_optput);
                first_char=to_optput[0];    //to_output has null character
                if (iOutput==0 and first_char==0){
                    iTemprary=iInput;
                }
                else{
                    iTemprary=iOutput*iInput;
                }
                //std::cout<<iTemprary<<std::endl;
                delete [] intermediate_array;
                intermediate_array = convertIntegerToChar(iTemprary);
                //strcpy(intermediate_,curr);
                SetWindowTextA(hOutput,intermediate_array);

            break;
            case DIVIDE_BTN:
                set_input_text("",curr);   //important step
                SetWindowTextA(hInput,"");
                GetWindowTextA(hOutput,to_optput,100);
                iInput=charTointeger(curr);
                iOutput=charTointeger(to_optput);
                first_char=to_optput[0];    //to_output has null character
                if (iOutput==0 and first_char==0){
                    iTemprary=iInput;
                }
                else{
                    iTemprary=iOutput/iInput;
                }
                //std::cout<<iTemprary<<std::endl;
                delete [] intermediate_array;
                intermediate_array = convertIntegerToChar(iTemprary);
                //strcpy(intermediate_,curr);
                SetWindowTextA(hOutput,intermediate_array);
            break;
            case CLR_BTN:
            SetWindowTextA(hOutput,"");
            SetWindowTextA(hInput,"");

            break;
            case PERIOD:
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
    CreateWindowW(L"button",L"All clear",WS_VISIBLE| WS_CHILD,275,280,70,160,hWnd,(HMENU)CLR_BTN,NULL,NULL);
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
    //ignore errors
    write_file(ofn.lpstrFile);

}

void write_file(char * path){
    FILE * file;
    file= fopen(path,"w");

    int __size =GetWindowTextLength(hOpenFile);
    char * data = new char[__size+1];
    //ignire errors
    GetWindowText(hOpenFile,data,__size+1);

    fwrite(data,__size+1,1,file);

    fclose(file);
}

void set_input_text(char* a,char curr1[]){
            GetWindowTextA(hInput,curr1,100);
            strcat(curr1,a);
            SetWindowTextA(hInput,curr1);
}