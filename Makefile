

CCLNFLAGS = -L$(CONCERTLIBDIR) -lconcert  -lm -pthread

CCFLAGS =  -fPIC -fexceptions -DNDEBUG -DIL_STD


XML_INCLUDES=-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/libxml++-2.6 -I/usr/lib/libxml++-2.6 -std=gnu++11 
CPLEX_INCLUDES=-I/usr/include/giomm-2.4 -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/giomm-2.4/giomm/ 


GANTT_CFLAGS = -I../../include -L../../lib -Wl,-R../../lib


INCLUDE_FILES= xmlParser.h model.h 

all: xmlParser.o Main.o model.o 
	@g++  $(CPLEX_LIBS) -L../xml/lib -Wl,-R../xml/lib $(CCFLAGS) model.o xmlParser.o Main.o -o sched `pkg-config --cflags --libs libxml++-2.6` $(CCLNFLAGS)


Main.o: Main.cpp $(INCLUDE_FILES)
	@g++  $(XML_INCLUDES) -std=c++11 -g -c -pthread Main.cpp

xmlParser.o: xmlParser.cpp $(INCLUDE_FILES)
	@g++ $(XML_INCLUDES) -std=c++11 -g -c -pthread xmlParser.cpp

model.o: model.cpp $(INCLUDE_FILES)
	@g++ $(INCLUDES) -std=c++11 -g -c -pthread model.cpp

clean:
	rm *.o sched *~ *.png 


