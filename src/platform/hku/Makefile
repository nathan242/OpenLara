SRCS=main.cpp \
	App.cpp \
	MainWindow.cpp \
	GameView.cpp \
	 ../../libs/stb_vorbis/stb_vorbis.c \
	 ../../libs/minimp3/minimp3.cpp \
	 ../../libs/tinf/tinflate.c
CC=g++

#CFLAGS+=-O3
CFLAGS+=-g -D__HAIKU__ -DGL_GLEXT_PROTOTYPES -ffunction-sections -fdata-sections -Wl,--gc-sections -Wall
LDFLAGS+=-lm -lpthread -lbe -lgame -lGL -ltracker -lmedia

INCLUDES+=-I../../

openlara :
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) $(SRCS) -o $@

clean:
	rm -f OpenLara
