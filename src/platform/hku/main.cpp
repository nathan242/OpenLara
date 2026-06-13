#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <SupportDefs.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include "game.h"
#include "App.h"

// timing
unsigned int startTime;

// sound
#define SND_FRAME_SIZE  4
#define SND_FRAMES      1024

Sound::Frame        *sndData;

int osGetTimeMS() {
    timeval t;
    gettimeofday(&t, NULL);
    return int((t.tv_sec - startTime) * 1000 + t.tv_usec / 1000);
}

/**void sndFill(void *udata, Uint8 *stream, int len) {
	
}**/

bool sndInit() {
	return true;
}

void sndFree() {

}

/**bool isKeyPressed (SDL_Scancode scancode) {
    
}**/

void osJoyVibrate(int index, float L, float R) {
}

InputKey codeToInputKey(int code) {
    switch (code) {
    // keyboard
        /**case SDL_SCANCODE_LEFT       : return ikLeft;
        case SDL_SCANCODE_RIGHT      : return ikRight;
        case SDL_SCANCODE_UP         : return ikUp;
        case SDL_SCANCODE_DOWN       : return ikDown;
        case SDL_SCANCODE_SPACE      : return ikSpace;
        case SDL_SCANCODE_TAB        : return ikTab;
        case SDL_SCANCODE_RETURN     : return ikEnter;
        case SDL_SCANCODE_ESCAPE     : return ikEscape;
        case SDL_SCANCODE_LSHIFT     :
        case SDL_SCANCODE_RSHIFT     : return ikShift;
        case SDL_SCANCODE_LCTRL      :
        case SDL_SCANCODE_RCTRL      : return ikCtrl;
        case SDL_SCANCODE_LALT       :
        case SDL_SCANCODE_RALT       : return ikAlt;
        case SDL_SCANCODE_0          : return ik0;
        case SDL_SCANCODE_1          : return ik1;
        case SDL_SCANCODE_2          : return ik2;
        case SDL_SCANCODE_3          : return ik3;
        case SDL_SCANCODE_4          : return ik4;
        case SDL_SCANCODE_5          : return ik5;
        case SDL_SCANCODE_6          : return ik6;
        case SDL_SCANCODE_7          : return ik7;
        case SDL_SCANCODE_8          : return ik8;
        case SDL_SCANCODE_9          : return ik9;
        case SDL_SCANCODE_A          : return ikA;
        case SDL_SCANCODE_B          : return ikB;
        case SDL_SCANCODE_C          : return ikC;
        case SDL_SCANCODE_D          : return ikD;
        case SDL_SCANCODE_E          : return ikE;
        case SDL_SCANCODE_F          : return ikF;
        case SDL_SCANCODE_G          : return ikG;
        case SDL_SCANCODE_H          : return ikH;
        case SDL_SCANCODE_I          : return ikI;
        case SDL_SCANCODE_J          : return ikJ;
        case SDL_SCANCODE_K          : return ikK;
        case SDL_SCANCODE_L          : return ikL;
        case SDL_SCANCODE_M          : return ikM;
        case SDL_SCANCODE_N          : return ikN;
        case SDL_SCANCODE_O          : return ikO;
        case SDL_SCANCODE_P          : return ikP;
        case SDL_SCANCODE_Q          : return ikQ;
        case SDL_SCANCODE_R          : return ikR;
        case SDL_SCANCODE_S          : return ikS;
        case SDL_SCANCODE_T          : return ikT;
        case SDL_SCANCODE_U          : return ikU;
        case SDL_SCANCODE_V          : return ikV;
        case SDL_SCANCODE_W          : return ikW;
        case SDL_SCANCODE_X          : return ikX;
        case SDL_SCANCODE_Y          : return ikY;
        case SDL_SCANCODE_Z          : return ikZ;
        case SDL_SCANCODE_AC_HOME    : return ikEscape;**/
    }
    return ikNone;
}

bool inputInit() {
    return true;
}

void inputFree() {
    
}

void inputUpdate() {
	
}

int main() {
	cacheDir[0] = saveDir[0] = contentDir[0] = 0;
    char *lvlName = nullptr;
    
    const char *home;
   	if (!(home = getenv("HOME")))
       	home = getpwuid(getuid())->pw_dir;
   	strcat(cacheDir, home);
   	strcat(cacheDir, "/.openlara/");

   	struct stat st = {0};
   	if (stat(cacheDir, &st) == -1 && mkdir(cacheDir, 0777) == -1)
       	cacheDir[0] = 0;
   	strcpy(saveDir, cacheDir);

   	timeval t;
   	gettimeofday(&t, NULL);
   	startTime = t.tv_sec;
	
	Core::width  = 320;
   	Core::height = 200;
	
	App* app = new App();
	app->Run();
	delete app;
	return 0;
}
