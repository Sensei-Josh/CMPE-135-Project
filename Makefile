all:
	g++ MyApp.cpp -o prog `../../wxWidgets-3.2.2.1/gtk-build/wx-config --cppflags --libs` 
	./prog
	
	
