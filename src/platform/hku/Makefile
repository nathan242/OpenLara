SRCS=main.cpp \
	 App.cpp \
	 MainWindow.cpp \
	 GameView.cpp \
     ../../libs/stb_vorbis/stb_vorbis.c \
     ../../libs/minimp3/minimp3.cpp \
     ../../libs/tinf/tinflate.c
CC=g++

# -std=c++11
#CFLAGS+=-D__HAIKU__ -O3 -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections -Wl,--gc-sections -Wall
CFLAGS+=-g -D__HAIKU__ -DGL_GLEXT_PROTOTYPES -ffunction-sections -fdata-sections -Wl,--gc-sections -Wall
LDFLAGS+=-lm -lpthread -lbe -lgame -lGL -lEGL


INCLUDES+=-I../../

openlara :
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) $(SRCS) -o $@

#install : openlara
#	install -d $(DESTDIR)$(PREFIX)/bin/
#	install openlara $(DESTDIR)$(PREFIX)/bin/OpenLara

#uninstall :
#	rm -f $(DESTDIR)$(PREFIX)/bin/OpenLara

#clean:
#	rm -f OpenLara
