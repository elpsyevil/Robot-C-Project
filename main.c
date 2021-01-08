#include "main.h"
int main(void){
//initialisation SDL
int toggle = 0;
int reponse = 1;
int rejouer;

SDL_Window* win = Debut();
//initialisation renderer
Uint32 render_flags = SDL_RENDERER_ACCELERATED;
SDL_Renderer* rend = SDL_CreateRenderer(win,-1,render_flags);
if (!rend) {
	printf("error : %s",SDL_GetError());
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 1;
}
//importation images
SDL_Surface* imgCircle = IMG_Load("resources/cercle.png");
if (!imgCircle) {
	printf("error : %s",SDL_GetError());
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 1;
}
SDL_Surface* imgRobot = IMG_Load("resources/robot1.png");
if (!imgRobot) {
	printf("error : %s",SDL_GetError());
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 1;
}
SDL_Surface* imgButton = IMG_Load("resources/button.png");
SDL_Surface* imgRect = IMG_Load("resources/rect.png");
SDL_Surface* imgBack = IMG_Load("resources/back.png");
SDL_Surface* imgTriangle = IMG_Load("resources/triangle.png");
SDL_Surface* imgCarre = IMG_Load("resources/carre.png");
SDL_Surface* imgMenu = IMG_Load("resources/menu.png");
SDL_Surface* imgYes= IMG_Load("resources/buttonyes.png");
SDL_Surface* imgNo = IMG_Load("resources/buttono.png");
SDL_Surface* imgRestart = IMG_Load("resources/restart.png");
SDL_Surface* imgOn = IMG_Load("resources/on.png");
SDL_Surface* imgOff = IMG_Load("resources/off.png");
SDL_Surface* imgN0 = IMG_Load("resources/numbers/0.png");
SDL_Surface* imgN1 = IMG_Load("resources/numbers/1.png");
SDL_Surface* imgN2 = IMG_Load("resources/numbers/2.png");
SDL_Surface* imgN3 = IMG_Load("resources/numbers/3.png");
SDL_Surface* imgN4 = IMG_Load("resources/numbers/4.png");
SDL_Surface* imgN5 = IMG_Load("resources/numbers/5.png");
SDL_Surface* imgN6 = IMG_Load("resources/numbers/6.png");
SDL_Surface* imgN7 = IMG_Load("resources/numbers/7.png");
SDL_Surface* imgN8 = IMG_Load("resources/numbers/8.png");
SDL_Surface* imgN9 = IMG_Load("resources/numbers/9.png");
SDL_Surface* imgN10 = IMG_Load("resources/numbers/10.png");

SDL_Surface* imgRand = IMG_Load("resources/buttonrand.png");
SDL_Surface* imgCont = IMG_Load("resources/buttocont.png");
SDL_Surface* imgChoix = IMG_Load("resources/backchoix.png");
//creation texture des images
SDL_Texture *texButton = SDL_CreateTextureFromSurface(rend,imgButton);
SDL_FreeSurface(imgButton);
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
SDL_Texture *texCOMPTEUR= SDL_CreateTextureFromSurface(rend,imgN0);
SDL_FreeSurface(imgN0);
SDL_Texture *texYes = SDL_CreateTextureFromSurface(rend,imgYes);
SDL_FreeSurface(imgYes);
SDL_Texture *texNo = SDL_CreateTextureFromSurface(rend,imgNo);
SDL_FreeSurface(imgNo);
SDL_Texture *texRestart = SDL_CreateTextureFromSurface(rend,imgRestart);
SDL_FreeSurface(imgRestart);
SDL_Texture *texOff = SDL_CreateTextureFromSurface(rend,imgOff);
SDL_FreeSurface(imgOff);
SDL_Texture *texOn = SDL_CreateTextureFromSurface(rend,imgOn);
SDL_FreeSurface(imgOn);
SDL_Texture *texChoix = SDL_CreateTextureFromSurface(rend,imgChoix);
SDL_FreeSurface(imgChoix);
SDL_Texture *texCont = SDL_CreateTextureFromSurface(rend,imgCont);
SDL_FreeSurface(imgCont);
SDL_Texture *texRand = SDL_CreateTextureFromSurface(rend,imgRand);
SDL_FreeSurface(imgRand);
SDL_Event event2;
SDL_Event event;
SDL_Event event3;
//creation des rectangles
SDL_Rect button;
SDL_Rect menu;
SDL_Rect back;
SDL_Rect robot;
SDL_Rect compteur;
SDL_Rect rect[N];
SDL_Rect Yes;
SDL_Rect No;
SDL_Rect Restart;
SDL_Rect Off;
SDL_Rect Cont;
SDL_Rect Rand;
//stores the texture image in the appropriate rectangle
SDL_QueryTexture(texButton,NULL,NULL,&button.w,&button.h);
SDL_QueryTexture(texMenu,NULL,NULL,&menu.w,&menu.h);
SDL_QueryTexture(texRobot,NULL,NULL,&robot.w,&robot.h);
SDL_QueryTexture(texBack,NULL,NULL,&back.w,&back.h);
SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
SDL_QueryTexture(texYes,NULL,NULL,&Yes.w,&Yes.h);
SDL_QueryTexture(texNo,NULL,NULL,&No.w,&No.h);
SDL_QueryTexture(texRestart,NULL,NULL,&Restart.w,&Restart.h);
SDL_QueryTexture(texOff,NULL,NULL,&Off.w,&Off.h);
SDL_QueryTexture(texCont,NULL,NULL,&Cont.w,&Cont.h);
SDL_QueryTexture(texRand,NULL,NULL,&Rand.w,&Rand.h);
//creation variable forme
typedef enum
{
	RECT,CIRCLE,TRIANGLE,CARRE
}shape;
int TabForm[N];
SDL_Point points[50];
int x_vel,y_vel,m_y;
float x;
float y;
int k;
int z;
int close;
int cc;
int dd;
int rr;
while(reponse == 1) {

    toggle = 0;
	imgButton = IMG_Load("resources/button.png");
	imgRect = IMG_Load("resources/rect.png");
	imgBack = IMG_Load("resources/back.png");
	imgTriangle = IMG_Load("resources/triangle.png");
	imgCarre = IMG_Load("resources/carre.png");
	imgMenu = IMG_Load("resources/menu.png");
	imgYes= IMG_Load("resources/buttonyes.png");
	imgNo = IMG_Load("resources/buttono.png");
	imgRestart = IMG_Load("resources/restart.png");
	imgN0 = IMG_Load("resources/numbers/0.png");
	imgN1 = IMG_Load("resources/numbers/1.png");
	imgN2 = IMG_Load("resources/numbers/2.png");
	imgN3 = IMG_Load("resources/numbers/3.png");
	imgN4 = IMG_Load("resources/numbers/4.png");
	imgN5 = IMG_Load("resources/numbers/5.png");
 	imgN6 = IMG_Load("resources/numbers/6.png");
	imgN7 = IMG_Load("resources/numbers/7.png");
 	imgN8 = IMG_Load("resources/numbers/8.png");
	imgN9 = IMG_Load("resources/numbers/9.png");
	imgN10 = IMG_Load("resources/numbers/10.png");
    imgOn = IMG_Load("resources/on.png");
    imgOff = IMG_Load("resources/off.png");
    imgRand = IMG_Load("resources/buttonrand");
    imgCont = IMG_Load("resources/buttocont");
    imgChoix = IMG_Load("resources/backchoix");

	SDL_QueryTexture(texButton,NULL,NULL,&button.w,&button.h);
	SDL_QueryTexture(texMenu,NULL,NULL,&menu.w,&menu.h);
	SDL_QueryTexture(texRobot,NULL,NULL,&robot.w,&robot.h);
	SDL_QueryTexture(texBack,NULL,NULL,&back.w,&back.h);
	SDL_QueryTexture(texCOMPTEUR,NULL,NULL,&compteur.w,&compteur.h);
	SDL_QueryTexture(texYes,NULL,NULL,&Yes.w,&Yes.h);
	SDL_QueryTexture(texNo,NULL,NULL,&No.w,&No.h);
	SDL_QueryTexture(texRestart,NULL,NULL,&Restart.w,&Restart.h);
	SDL_QueryTexture(texOff,NULL,NULL,&Off.w,&Off.h);
	SDL_QueryTexture(texCont,NULL,NULL,&Cont.w,&Cont.h);
    SDL_QueryTexture(texRand,NULL,NULL,&Rand.w,&Rand.h);
	//generation de formes aleatoire
	srand(time(NULL));
	for (int i=0; i<N; i++) {
		TabForm[i]=(rand() % 4);
	}
//initialisation variable
	points[0].x=wid/N/2; points[0].y=5*hei/N/2;
	x_vel=0,y_vel=0,m_y=0;
    x=0;
	y=hei/2-hei/(2*N);
    z=1;
	close = 0;
	int P[N] = {0};
	cc=0;
	dd=1;
	rr=0;
//coordonne et taille des rectangle
	compteur.w = wid/N/2;
	compteur.h = hei/N/2;
	compteur.x = wid - compteur.w;
	compteur.y = 0;
	robot.w=wid/N;
	robot.h=wid/N;
	menu.x=0;
	menu.y=0;
	menu.w=wid;
	menu.h=hei;
	Restart.x=0;
	Restart.y=0;
	Restart.w=wid;
	Restart.h=hei;
	back.x=0;
	back.y=0;
	back.w = wid;
	back.h = hei;
	button.x=230;
	button.y=329;
	button.w=301;
	button.h=301;
	No.x=nox;
	No.y=noy;
	No.w=widb;
	No.h=widb;
	Yes.x=yesx;
	Yes.y=yesy;
	Yes.w=widb;
	Yes.h=widb;
	Off.w = widb;
	Off.h = widb;
	Off.y = yesy;
	Off.x = 350;
	Rand.x=yesx;
	Rand.y=yesy;
	Rand.w=widb;
	Rand.h=widb;
	Cont.x=230;
	Cont.y=329;
	Cont.w=301;
	Cont.h=301;
	rejouer = 0;
	SDL_Event event4;

    texCOMPTEUR= SDL_CreateTextureFromSurface(rend,imgN0);
    SDL_FreeSurface(imgN0);

    dd=1;
    while(dd==1)
		{
			while(SDL_PollEvent(&event2)){
			if (event2.button.x>=230 && event2.button.x<=531 && event2.button.y>=434 && event2.button.y<= 535)
			{
				button.w = 400;
				button.h = 400;
				button.x = 180;
				button.y = 279;
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, texMenu, NULL, &menu);
				SDL_RenderCopy(rend, texButton, NULL, &button);
				SDL_RenderPresent(rend);
				if (event2.type==SDL_MOUSEBUTTONDOWN) {
					dd=0;

				}
			}
				else {
					button.w = 301;
					button.h = 301;
					button.x = 230;
					button.y = 329;
					SDL_RenderClear(rend);
					SDL_RenderCopy(rend, texMenu, NULL, &menu);
					SDL_RenderCopy(rend, texButton, NULL, &button);
					SDL_RenderPresent(rend);
				}
				if(event2.type == SDL_QUIT){
                    dd = 0;
                    close = 1;
                    rejouer = 1;
                    reponse = 0;
				}
			}
		}
		if (close == 1)
            dd=1;

	while (!dd){
        while(SDL_PollEvent(&event4)){
                    if(event4.button.y>=wid/N && event4.button.y<=2*wid/N && event4.type == SDL_MOUSEBUTTONDOWN){
                        k = (int)(event4.button.x*N)/wid;
                        TabForm[k]++;
                        if (TabForm[k]>3)
                            TabForm[k]=0;
                    }


                    if (event4.button.x>=230 && event4.button.x<=531 && event4.button.y>=434 && event4.button.y<= 535 ){
                        if(event4.type == SDL_MOUSEBUTTONDOWN)
                                dd=1;
                        Cont.w = 400;
                        Cont.h = 400;
                        Cont.x = 180;
                        Cont.y = 279;
                        SDL_RenderClear(rend);
                        SDL_RenderCopy(rend, texChoix, NULL, &back);
                        SDL_RenderCopy(rend, texRand, NULL, &Rand);
                        SDL_RenderCopy(rend, texCont, NULL, &Cont);
                        showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
                        SDL_RenderPresent(rend);
                    }

                    else if (event4.button.x>=yesx && event4.button.x<=yesx+widb && event4.button.y>=yesy+0.35*widb && event4.button.y<= yesy + 0.65*widb)
			{
                    if(event4.type == SDL_MOUSEBUTTONDOWN){
                        for (int i=0; i<N; i++) {
                        TabForm[i]=(rand() % 4);
                        }
                    }
                        Rand.w = widp;
                        Rand.h = widp;
                        Rand.x = yesx-(widp-widb)/2;
                        Rand.y = yesy-(widp-widb)/2;
                        SDL_RenderClear(rend);
                        SDL_RenderClear(rend);
                        storeShapes(TabForm,texCircle,texRect,texTriangle, texCarre,rect);
                        SDL_RenderCopy(rend, texChoix, NULL, &back);
                        SDL_RenderCopy(rend, texRand, NULL, &Rand);
                        SDL_RenderCopy(rend, texCont, NULL, &Cont);
                        showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
                        SDL_RenderPresent(rend);


			}
                        else{
                        Cont.x=230;
                        Cont.y=329;
                        Cont.w=301;
                        Cont.h=301;
                        Rand.x=yesx;
                        Rand.y=yesy;
                        Rand.w=widb;
                        Rand.h=widb;

                    }
                       if(event4.type == SDL_QUIT){
                        dd = 1;
                        close = 1;
                        rejouer = 1;
                        reponse = 0;
				}

                        SDL_RenderClear(rend);
                        storeShapes(TabForm,texCircle,texRect,texTriangle, texCarre,rect);
                        SDL_RenderCopy(rend, texChoix, NULL, &back);
                        SDL_RenderCopy(rend, texRand, NULL, &Rand);
                        SDL_RenderCopy(rend, texCont, NULL, &Cont);
                        showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
                        SDL_RenderPresent(rend);
        }

	}
	 // stores shapes in textures
	//menu
	//Menu(TabForm,&close,&reponse,&rejouer);



	int TabCopie[N];
	for (int i=0; i<N; i++) {
		TabCopie[i]=TabForm[i];
	}
	// game looooop
	while (!close) {
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				{close= 1;
				rejouer = 1;
				reponse = 0;}

		}
		k=(int)((robot.x)*N)/wid; //colonne actuelle du robot
		Move(&y,&y_vel,&z); // move robot to zone1 ou 2
		if ( verifier(TabForm,k) && y==2*hei/N && TabCopie[k] != -1 ) { //si un cercle
			printf("CERCLE DETECTE\n");
			y=2*hei/N+0.1;
			cc++;
			z=2;
			P[k]=1;
			if(cc<=10){
			switch(cc){
	         case 1 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN1);
	             SDL_FreeSurface(imgN1);
	             break;
	         case 2 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN2);
	             SDL_FreeSurface(imgN2);
	             break;
	         case 3 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN3);
	             SDL_FreeSurface(imgN3);
	             break;
	         case 4 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN4);
	             SDL_FreeSurface(imgN4);
	             break;
	         case 5 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN5);
	             SDL_FreeSurface(imgN5);
	             break;
	         case 6 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN6);
	             SDL_FreeSurface(imgN6);
	             break;
	         case 7 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN7);
	             SDL_FreeSurface(imgN7);
	             break;
	         case 8 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN8);
	             SDL_FreeSurface(imgN8);
	             break;
	         case 9 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN9);
	             SDL_FreeSurface(imgN9);
	             break;
             case 10 :
	             texCOMPTEUR = SDL_CreateTextureFromSurface(rend,imgN10);
	             SDL_FreeSurface(imgN10);
	             break;
	         }
}
			compteur.w = wid/N/2;
			compteur.h = hei/N/2;
			compteur.x = wid - compteur.w;
			compteur.y = 0;
//store points
			storePoints(points,&k,&rr,1);
			TabCopie[k] = -1;
			SDL_Delay(500);
			printf("MOVING...\n");
		}

		else if (y<=2*wid/N ) {
			if (x<wid -wid/N)
				x+=wid/N;
			if (TabCopie[k]!=-1) {
				printf("PAS DE CERCLE DETECTE\n");
//store points
				storePoints(points,&k,&rr,0);
			}
			if (k == 9) {
				z = 0;
			}
			TabCopie[k]=-1;
			SDL_Delay(500);
		}
//mouvements des objets
		moveObject(rect,P,k,&z,&x);
//les vitesses
		x+=x_vel/60;
		y+=y_vel/60;
		robot.x=(int)x;
		robot.y=(int)y;
		menu.y+=(int)m_y;
		//button.y=(int)m_y;
		SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
//apparaitre le contenu de la fenetre
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, texBack, NULL, &back);
		SDL_RenderCopy(rend, texRobot, NULL, &robot);
		SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
		SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
		showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
//dessiner le chemin
		//draw(rend,rr,points,k,z,TabForm);
		SDL_RenderPresent(rend);
//boutton start

		if (z==0) {
			close = 1;
		}
		SDL_Delay(1000/60);

	}

	SDL_RenderCopy(rend,texOff,NULL, &Off);
                            //SDL_RenderCopy(rend, texRestart, NULL, &Restart);
    SDL_RenderCopy(rend, texYes, NULL, &Yes);
    SDL_RenderCopy(rend, texNo, NULL, &No);
    SDL_RenderPresent(rend);

	while(!rejouer)
	{
		while(SDL_PollEvent(&event3)){
			if (event3.button.x>=yesx && event3.button.x<=yesx+widb && event3.button.y>=yesy+0.35*widb && event3.button.y<= yesy + 0.65*widb)
			{
				Yes.w = widp;
				Yes.h = widp;
				Yes.x = yesx-(widp-widb)/2;
				Yes.y = yesy-(widp-widb)/2;
				Off.w = widb;
                Off.h = widb;
                Off.y = yesy;
                Off.x = 350;
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, texBack, NULL, &back);
                		SDL_RenderCopy(rend, texRobot, NULL, &robot);
                		SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
                		SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
               			showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
//dessiner le chemin
                if (toggle){
				draw(rend,rr,points,k,z,TabForm);
                SDL_RenderCopy(rend,texOn,NULL, &Off);;
                		}
                		else
                		SDL_RenderCopy(rend,texOff,NULL, &Off);
				//SDL_RenderCopy(rend, texRestart, NULL, &Restart);
				SDL_RenderCopy(rend, texYes, NULL, &Yes);
				SDL_RenderCopy(rend, texNo, NULL, &No);
				SDL_RenderPresent(rend);
				if (event3.type==SDL_MOUSEBUTTONDOWN) {
					SDL_RenderClear(rend);
					rejouer = 1;
					reponse = 1;
				}
			}
			else if (event3.button.x>=nox && event3.button.x<=nox+widb && event3.button.y>=noy+0.35*widb && event3.button.y<=0.65*widb+noy)
			{
				No.w = widp;
				No.h = widp;
				No.x = nox-(widp-widb)/2;
				No.y = noy-(widp-widb)/2;
				Off.w = widb;
                Off.h = widb;
                Off.y = yesy;
                Off.x = 350;
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, texBack, NULL, &back);
                SDL_RenderCopy(rend, texRobot, NULL, &robot);
                SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
                SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
                showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
				if (toggle){
				draw(rend,rr,points,k,z,TabForm);
                SDL_RenderCopy(rend,texOn,NULL, &Off);
                		}
                		else
                		SDL_RenderCopy(rend,texOff,NULL, &Off);
				SDL_RenderCopy(rend, texYes, NULL, &Yes);
				SDL_RenderCopy(rend, texNo, NULL, &No);
				SDL_RenderPresent(rend);
				if (event3.type==SDL_MOUSEBUTTONDOWN) {
					SDL_RenderClear(rend);
					rejouer = 1;
					reponse = 0;
					printf("\n\nAU REVOIR !!\n\n");
				}
			}
			else {
				No.x=nox;
				No.y=noy;
				No.w=widb;
				No.h=widb;
				Yes.x=yesx;
				Yes.y=yesy;
				Yes.w=widb;
				Yes.h=widb;
				Off.w = widb;
                Off.h = widb;
                Off.y = yesy;
                Off.x = 350;
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, texBack, NULL, &back);
                SDL_RenderCopy(rend, texRobot, NULL, &robot);
                SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
                SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
                showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
                		if (toggle){
				draw(rend,rr,points,k,z,TabForm);
                SDL_RenderCopy(rend,texOn,NULL, &Off);
                		}
                		else
                SDL_RenderCopy(rend,texOff,NULL, &Off);
				//SDL_RenderCopy(rend, texRestart, NULL, &Restart);
				SDL_RenderCopy(rend, texYes, NULL, &Yes);
				SDL_RenderCopy(rend, texNo, NULL, &No);
				SDL_RenderPresent(rend);
			}
			if (event3.button.x>=382 && event3.button.x<=415 && event3.button.y>=20 && event3.button.y<=40 && event3.type == SDL_MOUSEBUTTONDOWN){
                    if (toggle){
                    toggle = 0;
					Off.w = widb;
					Off.h = widb;
					Off.y = yesy;
					Off.x = 350;
				        SDL_RenderClear(rend);
				        SDL_RenderCopy(rend, texBack, NULL, &back);
                			SDL_RenderCopy(rend, texRobot, NULL, &robot);
                			SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
                			SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
                			showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
                    if (toggle){
                    draw(rend,rr,points,k,z,TabForm);
                        SDL_RenderCopy(rend,texOn,NULL, &Off);
                		}
                		else
                            SDL_RenderCopy(rend,texOff,NULL, &Off);
                            //SDL_RenderCopy(rend, texRestart, NULL, &Restart);
                            SDL_RenderCopy(rend, texYes, NULL, &Yes);
                            SDL_RenderCopy(rend, texNo, NULL, &No);
                            SDL_RenderPresent(rend);
                                      }
                        else {
                            toggle = 1;
                            Off.w = widb;
                            Off.h = widb;
                            Off.y = yesy;
                            Off.x = 350;
                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, texBack, NULL, &back);
                            SDL_RenderCopy(rend, texRobot, NULL, &robot);
                            SDL_RenderCopy(rend, texCOMPTEUR, NULL, &compteur);
                            SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
                            showShapes(TabForm,rend,texCircle,texRect,texTriangle, texCarre,rect);
					if (toggle){
                        draw(rend,rr,points,k,z,TabForm);
                        SDL_RenderCopy(rend,texOn,NULL, &Off);
                		}
                		else
                		SDL_RenderCopy(rend,texOff,NULL, &Off);
                        //SDL_RenderCopy(rend, texRestart, NULL, &Restart);
                        SDL_RenderCopy(rend, texYes, NULL, &Yes);
                        SDL_RenderCopy(rend, texNo, NULL, &No);
                        SDL_RenderPresent(rend);
       					}
                   }
                   if(event3.type == SDL_QUIT){
                    rejouer = 1;
                    reponse = 0;
				}
		}
	}
}
Quitter(rend,texMenu,texBack,texCircle,texRect,texTriangle,texCarre,texCOMPTEUR,texRobot,texButton,win);
}
