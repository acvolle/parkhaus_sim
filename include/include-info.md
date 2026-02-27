 * car.h includes nothing

 * queue.h includes car.h

 * parking.h includes car.h

 * stats.h includes queue.h

 * simulation.h includes parking.h, stats.h, queue.h

 * ui.h includes simulation.h

 * main.c includes simulation.h and ui.h
