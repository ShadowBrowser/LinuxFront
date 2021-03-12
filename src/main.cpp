#include "main.h"

int main(int argc, char * argv[]) {

	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) { cmdlineHelp(); }
		if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--detach") == 0) { cmdlineDetach(); }
	}


	Display * display;
	Window window;
	XEvent event;
	const char * msg = RES_APP_TITLE;
	int screen;

	display = XOpenDisplay(NULL);
	if (display == NULL) {
		std::cerr << RES_DISPLAY_OPEN_ERR << std::endl;
		exit(1);
	}

	screen = DefaultScreen(display);
	window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 800, 450, 1,
		BlackPixel(display, screen), WhitePixel(display, screen));
	XSelectInput(display, window, ExposureMask | KeyPressMask);
	XMapWindow(display, window);

	while (1) {
		XNextEvent(display, & event);
		if (event.type == Expose) {
			XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 10, 10);
			XDrawString(display, window, DefaultGC(display, screen), 10, 50, msg, strlen(msg));
		}
		if (event.type == KeyPress)
			break;
	}

	XCloseDisplay(display);
	return 0;
}
