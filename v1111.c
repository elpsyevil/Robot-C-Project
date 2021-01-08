#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include"fonctions.h"
#define hei 750
#define wid 750
#define SPEED 510
#define N 10
int main(void){


    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)!=0){
        printf("error : %s\n",SDL_GetError());
        return 1;
    }
    SDL_Surface* icon = IMG_Load("resources/robot1.png");
    SDL_Window *win = SDL_CreateWindow("Robot Intelligent",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,wid,hei,0);
    if (!win){
        printf("error : %s",SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_SetWindowIcon(win,icon);
    SDL_FreeSurface(icon);


    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win,-1,render_flags);
    if (!rend){
        printf("error : %s",SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Surface* imgCircle = IMG_Load("resources/cercle.png");
    if (!imgCircle){
    printf("error : %s",SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
    }
    SDL_Surface* imgRobot = IMG_Load("resources/robot1.png");
    if (!imgRobot){
    printf("error : %s",SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
    }
    SDL_Surface* imgRect = IMG_Load("resources/rect.png");
    SDL_Surface* imgBack = IMG_Load("resources/back.png");
    SDL_Surface* imgTriangle = IMG_Load("resources/triangle.png");
    SDL_Surface* imgCarre = IMG_Load("resources/carre.png");
    SDL_Surface* imgMenu = IMG_Load("resources/menu.png");

    //SDL_Surface** imgN[10];

    /*imgN[0] = IMG_Load("resources/numbers/0.jpg");
    imgN[1] = IMG_Load("resources/numbers/1.jpg");
    imgN[2] = IMG_Load("resources/numbers/2.jpg");
    imgN[3] = IMG_Load("resources/numbers/3.jpg");
    imgN[4] = IMG_Load("resources/numbers/4.jpg");
    imgN[5] = IMG_Load("resources/numbers/5.jpg");
    imgN[6] = IMG_Load("resources/numbers/6.jpg");
    imgN[7] = IMG_Load("resources/numbers/7.jpg");
    imgN[8] = IMG_Load("resources/numbers/8.jpg");
    imgN[9] = IMG_Load("resources/numbers/9.jpg");*/

    SDL_Surface* imgN0 = IMG_Load("resources/numbers/0.jpg");
    SDL_Surface* imgN1 = IMG_Load("resources/numbers/1.jpg");
    SDL_Surface* imgN2 = IMG_Load("resources/numbers/2.jpg");
    SDL_Surface* imgN3 = IMG_Load("resources/numbers/3.jpg");
    SDL_Surface* imgN4 = IMG_Load("resources/numbers/4.jpg");
    SDL_Surface* imgN5 = IMG_Load("resources/numbers/5.jpg");
    SDL_Surface* imgN6 = IMG_Load("resources/numbers/6.jpg");
    SDL_Surface* imgN7 = IMG_Load("resources/numbers/7.jpg");
    SDL_Surface* imgN8 = IMG_Load("resources/numbers/8.jpg");
    SDL_Surface* imgN9 = IMG_Load("resources/numbers/9.jpg");

    SDL_Texture *texCircle = SDL_CreateTextureFromSurface(rend,imgCircle);
    SDL_FreeSurface(imgCircle);
    SDL_Texture *texRobot = SDL_CreateTextureFromSurface(rend,imgRobot);
    SDL_FreeSurface(imgRobot);
    SDL_Texture *texRect = SDL_CreateTextureFromSurface(rend,imgRect);
    SDL_FreeSurface(imgRect);
    SDL_Texture *texCarre = SDL_CreateTextureFromSurface(rend,imgCarre);
    SDL_FreeSurface(imgCarre);
    SDL_Texture *texBack = SDL_CreateTextureFromSurface(rend,imgBack);
    SDL_FreeSurface(imgBack);
    SDL_Texture *texTriangle= SDL_CreateTextureFromSurface(rend,imgTriangle);
    SDL_FreeSurface(imgTriangle);
    SDL_Texture *texMenu= SDL_CreateTextureFromSurface(rend,imgMenu);
    SDL_FreeSurface(imgMenu);
    //SDL_Texture *texCOMPTEUR= SDL_CreateTextureFromSurface(rend,imgN[0]);
    //SDL_FreeSurface(imgN[0]);
    SDL_Texture *texCOMPTEUR= SDL_CreateTextureFromSurface(rend,imgN0);
    SDL_FreeSurface(imgN0);



    //Initialistaion des variables
    SDL_Rect menu;
    SDL_Rect back;
    SDL_Rect robot;
    SDL_Rect compteur;
    SDL_Rect rect[N];

    SDL_QueryTexture(texMenu,NULL,NULL,&menu.w,&menu.h);
    SDL_QueryTexture(texRobot,NULL,NULL,&robot.w,&robot.h); //stores the texture image in the rectangle robot
    SDL_QueryTexture(texBack,NULL,NULL,&back.w,&back.h);
    SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);


    typedef enum shape
    {
        VIDE,CIRCLE,RECT,TRIANGLE,CARRE
    }shape;
    int T[N],comp[N],TT[N];
    srand(time(NULL));
    for (int i=0;i<N;i++){
        T[i]=(rand() % 4)+1;
        TT[i]=T[i];
    }
    int L=0,rr=0;
    for (int i=0;i<N;i++){
        if (T[i]==1){
        L++;
        comp[i]=L;
        }
        else comp[i]=0;
    }
   SDL_Point points[100];
   points[0].x=wid/N/2;points[0].y=5*hei/N/2;
    int x_vel=0,y_vel=0,m_vel=0,m_y=0;
    float x=0;
    float y=hei/2-hei/(2*N);
    int bb=0;
    compteur.w = wid/(2*N);
    compteur.h = hei/(2*N);
    compteur.x = wid - compteur.w;
    compteur.y = 0;
    robot.w=wid/N;
    robot.h=wid/N;
    menu.x=0;
    menu.y=0;
    menu.w=wid;
    menu.h=hei;
    //back.w=wid;
    //back.h=hei;
    back.x=0;
    back.y=0;
    int k;
    int z=0;
    z=1;
    int a=SPEED;
    int close = 0;
    int P[N]={0};
    int cc=0;
    int dd;
    int A=1;
    SDL_Event event2;
    storeShapes(T,texCircle,texRect,texTriangle, texCarre,rect); // stores shapes in textures
    dd=1;
    //SDL_RendererFlip flip = SDL_FLIP_NONE;


                    // game looooop
   while (!close){
    SDL_Event event;
    SDL_Event event1;

    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
            close= 1;
    }


    k=(int)((robot.x)*N)/wid;
    Move(&y,&y_vel,&z); // move robot to z
    if (T[k] == CIRCLE && y==2*hei/N ){
    y=2*hei/N+1;
    //cc++;
    z=2;
    P[k]=1;
    //compter(rend,texCOMPTEUR,imgN,&cc,&compteur.w,&compteur.h);
        /*switch(cc){
        case 1 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[1]);
            SDL_FreeSurface(imgN[1]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 2 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[2]);
            SDL_FreeSurface(imgN[2]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 3 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[3]);
            SDL_FreeSurface(imgN[3]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 4 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[4]);
            SDL_FreeSurface(imgN[4]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 5 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[5]);
            SDL_FreeSurface(imgN[5]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 6 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[6]);
            SDL_FreeSurface(imgN[6]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 7 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[7]);
            SDL_FreeSurface(imgN[7]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 8 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[8]);
            SDL_FreeSurface(imgN[8]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 9 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN[9]);
            SDL_FreeSurface(imgN[9]);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        }*/
        switch(comp[k]){
        case 1 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN1);
            SDL_FreeSurface(imgN1);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 2 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN2);
            SDL_FreeSurface(imgN2);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 3 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN3);
            SDL_FreeSurface(imgN3);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 4 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN4);
            SDL_FreeSurface(imgN4);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 5 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN5);
            SDL_FreeSurface(imgN5);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 6 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN6);
            SDL_FreeSurface(imgN6);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 7 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN7);
            SDL_FreeSurface(imgN7);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 8 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN8);
            SDL_FreeSurface(imgN8);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        case 9 :
            texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN9);
            SDL_FreeSurface(imgN9);
            SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
            break;
        }


        compteur.w = wid/(2*N);
        compteur.h = hei/(2*N);
        compteur.x = wid - compteur.w;
        compteur.y = 0;

        points[rr+1].x=(2*bb+1)*(wid/N/2);
        points[rr+1].y=hei-3*hei/N/2;
        points[rr+2].x=(2*bb+3)*(wid/N/2);
        points[rr+2].y=hei-3*hei/N/2;
        points[rr+3].x=(2*bb+3)*(wid/N/2);
        points[rr+3].y=5*hei/N/2;
        bb++;
        rr+=3;

    SDL_Delay(500);
    }
    else if (y<=2*wid/N && k<=9){
          if (x<wid -wid/N)
          x+=wid/N;
          points[rr+1].x=(2*bb+3)*(wid/N/2);
          points[rr+1].y=5*hei/N/2;
          rr+=1;
          bb++;
          SDL_Delay(500);
          }
        rect[k].y+=a*P[k]/60;
        if (rect[k].y>wid-2*wid/N){
            P[k]=0;
            rect[k].y=wid-2*wid/N;
            z=1;
        if (x<wid-wid/N)
           x+=wid/N;

          SDL_Delay(500);
        }


    x+=x_vel/60;
    y+=y_vel/60;
    robot.x=(int)x;
    robot.y=(int)y;
    m_y+=m_vel/60;
    menu.y+=(int)m_y;
    SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texBack, NULL, &back);
    SDL_RenderCopy(rend, texRobot, NULL, &robot);
    SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
    showShapes(T,rend,texCircle,texRect,texTriangle, texCarre,rect);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
    if (k==9){
        SDL_RenderDrawLine(rend,wid/N/2,hei/2-hei/(2*N),wid/N/2,5*hei/N/2);
        SDL_RenderDrawLines(rend,points,rr);

        }
    SDL_RenderCopy(rend, texMenu, NULL,&menu);
    SDL_RenderPresent(rend);
    while(dd)
    {
        SDL_PollEvent(&event2);
        if (event2.type==SDL_MOUSEBUTTONDOWN && event2.button.x>=230 && event2.button.x<=531 && event2.button.y>=434 && event2.button.y<= 535)
        {
                m_vel = SPEED;
                dd=0;

        }
    }

    SDL_Delay(1000/60);
    }

    SDL_DestroyTexture(texMenu);
    SDL_DestroyTexture(texBack);
    SDL_DestroyTexture(texCircle);
    SDL_DestroyTexture(texRect);
    SDL_DestroyTexture(texTriangle);
    SDL_DestroyTexture(texCarre);
    SDL_DestroyTexture(texRobot);
    SDL_DestroyTexture(texCOMPTEUR);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
