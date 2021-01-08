void Move(float* y,int* yvel,int* z);
void storeShapes(int T[],SDL_Texture *t1,SDL_Texture *t2,SDL_Texture *t3,SDL_Texture *t4,SDL_Rect rect[] );
void showShapes(int T[],SDL_Renderer* rend,SDL_Texture *t1,SDL_Texture *t2,SDL_Texture *t3,SDL_Texture *t4,SDL_Rect rect[] );
int verifier(int T[],int k);
void draw(SDL_Renderer *rend, int rr,SDL_Point points[],int k, int z,int T[]);
void Menu(int T[],int* c,int* r,int* d);
void Quitter(SDL_Renderer *rend,SDL_Texture* texMenu,SDL_Texture* texBack,SDL_Texture* texCircle,SDL_Texture* texRect,SDL_Texture* texTriangle,SDL_Texture* texCarre,SDL_Texture* texCOMPTEUR,SDL_Texture* texRobot,SDL_Texture* texButton,SDL_Window* win);
void storePoints(SDL_Point points[],int *bb,int *rr,int choix);
void moveObject(SDL_Rect rect[],int P[],int k,int* z,float* x);
SDL_Window* Debut();



