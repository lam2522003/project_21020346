all :
	g++ -ISDL2/include -LSDL2/lib -o main main.cpp myGame.cpp mySDL.cpp pile.cpp bird.cpp background.cpp sound.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_Mixer