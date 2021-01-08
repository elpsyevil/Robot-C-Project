#include "main.h"

typedef enum shape
{
    RECT,CERCLE,TRIANGLE,CARRE
}shape;

void Move(float* y,int* yvel,int* z){
    switch(*z){
       case 1 :
            *yvel=-SPEED;
            if (*y<=2*wid/N){
                *y=2*wid/N;
                *yvel=0;
            }
            break;
        case 2 :
            *yvel=SPEED;
                if (*y>=wid-wid/N){
                *y=wid-wid/N;
                *yvel=0;
            }
            break;
        default :
            *yvel=0;
    }
}



void storeShapes(int T[],SDL_Texture *t1,SDL_Texture *t2,SDL_Texture *t3,SDL_Texture *t4,SDL_Rect rect[] ) // if false add * to sdl rect
{
    for(int i=0;i<N;i++){// if 1 circle else rect all loop
        switch (T[i]){
        case 0:
            SDL_QueryTexture(t2,NULL,NULL,&rect[i].w,&rect[i].h);break;
        case 1:
            SDL_QueryTexture(t1,NULL,NULL,&rect[i].w,&rect[i].h);break;
        case 2:
            SDL_QueryTexture(t3,NULL,NULL,&rect[i].w,&rect[i].h);break;
        case 3:
            SDL_QueryTexture(t4,NULL,NULL,&rect[i].w,&rect[i].h);break;

        }
    }


    for(int i=0;i<N;i++){ // posotionnement des images

        rect[i].w=wid/N;
        rect[i].h=wid/N;
        rect[i].x=(wid/N)*i;
        rect[i].y=wid/N;

    }


}


void showShapes(int T[],SDL_Renderer* rend,SDL_Texture *t1,SDL_Texture *t2,SDL_Texture *t3,SDL_Texture *t4,SDL_Rect rect[] )
{
    for(int i=0;i<N;i++){
        switch (T[i]){
        case 0:
            SDL_RenderCopy(rend, t2, NULL, &rect[i]);break;
        case 1:
            SDL_RenderCopy(rend, t1, NULL, &rect[i]);break;
        case 2:
            SDL_RenderCopy(rend, t3, NULL, &rect[i]);break;
        case 3:
            SDL_RenderCopy(rend, t4, NULL, &rect[i]);break;

        }
    }
}
int verifier(int T[],int k){
    if (T[k]==CERCLE){
    //printf("CERCLE\n");
        return 1;}
    else return 0;
}

void draw(SDL_Renderer *rend, int rr,SDL_Point points[],int k, int z,int T[]){

    if (k==9 && T[N-1] == 1 && z==0){
//dessin chemin
        SDL_RenderDrawLine(rend,wid/N/2,hei/2-hei/(2*N),wid/N/2,5*hei/N/2);
        SDL_RenderDrawLines(rend,points,rr-1);

        }
    else if (k==9 && T[N-1] != 1 && z==0){
//dessin chemin
        SDL_RenderDrawLine(rend,wid/N/2,hei/2-hei/(2*N),wid/N/2,5*hei/N/2);
        SDL_RenderDrawLines(rend,points,rr);

        }
}

void Menu(int T[],int* c,int* r,int* d){
    int choix;
    printf("Choisissez l'ordre de vos formes avant de commencer :\n0 = Rectangle\n1 = Cercle\n2 = Triangle\n3 = Carre\n4 = Random\n5 = Tout Random ou continuer Randomly\n6 = Quitter\n\n");
    for (int i=0;i<N;i++){
        printf("Forme %d : ",i+1);
        scanf("%d",&choix);
        if (choix == 5)
            break;
        else if (choix==4)
            choix = (rand() % 4);
        else if (choix == 6){
            *c=1;
            *d=1;
            *r=0;
            break;
        }
        T[i]=choix;
    }

if (choix == 6){
    printf("\n\nAU REVOIR !\n\n");
}
else
    printf("\n\nCLIQUEZ SUR START\n\n");

}

void Quitter(SDL_Renderer *rend,SDL_Texture* texMenu,SDL_Texture* texBack,SDL_Texture* texCircle,SDL_Texture* texRect,SDL_Texture* texTriangle,SDL_Texture* texCarre,SDL_Texture* texCOMPTEUR,SDL_Texture* texRobot,SDL_Texture* texButton,SDL_Window* win){
    SDL_DestroyTexture(texMenu);
    SDL_DestroyTexture(texBack);
    SDL_DestroyTexture(texCircle);
    SDL_DestroyTexture(texRect);
    SDL_DestroyTexture(texTriangle);
    SDL_DestroyTexture(texCarre);
    SDL_DestroyTexture(texRobot);
    SDL_DestroyTexture(texCOMPTEUR);
    SDL_DestroyTexture(texButton);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void storePoints(SDL_Point points[],int *bb,int *rr,int choix){
     if (choix == 1){
     points[*rr+1].x=(2*(*bb)+1)*(wid/N/2)+2;
     points[*rr+1].y=5*hei/N/2;
     points[*rr+2].x=(2*(*bb)+1)*(wid/N/2)+2;
     points[*rr+2].y=hei-3*hei/N/2;
     points[*rr+3].x=(2*(*bb)+3)*(wid/N/2)-2;
     points[*rr+3].y=hei-3*hei/N/2;
     points[*rr+4].x=(2*(*bb)+3)*(wid/N/2)-2;
     points[*rr+4].y=5*hei/N/2;
     *rr+=4;
}
     else if (choix == 0){
     points[*rr+1].x=(2*(*bb)+3)*(wid/N/2);
     points[*rr+1].y=5*hei/N/2;
     *rr+=1;

}
}

void moveObject(SDL_Rect rect[],int P[],int k,int* z,float* x){ // k = colonne actuelle du Robot
     rect[k].y+=SPEED*P[k]/60;
     if (rect[k].y>hei-2*hei/N){
         P[k]=0;
         rect[k].y=hei-2*hei/N;
         if (k==9){
             *z=0;
         }
         else
         *z=1;
     if (*x<wid-wid/N)
         *x+=wid/N;
         SDL_Delay(500);
         }
}

SDL_Window* Debut(){

if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)!=0) {
	printf("error : %s\n",SDL_GetError());
	return 1;
}
//creation fenetre
SDL_Window *win = SDL_CreateWindow("Robot Intelligent",1100,SDL_WINDOWPOS_CENTERED,wid,hei,0);
if (!win) {
	printf("error : %s",SDL_GetError());
	SDL_Quit();
}

}

