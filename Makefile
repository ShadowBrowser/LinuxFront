all:
	#g++ -o ./bin/ShadowBrowser $(pkg-config x11  --cflags --libs) ./src/*.cpp
	g++ -o ./bin/ShadowBrowser ./src/*.cpp -lX11
