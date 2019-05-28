
# include openCV
cv = `pkg-config --cflags --libs opencv`

odnn : main.cpp functions.cpp
		g++ $^ $(cv) -g -o $@ 