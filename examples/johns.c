/*
 * Examples of gnuplot_i.c usage
 * Compilation: gcc -Wall -g johns.c ../gnuplot_i.c -o johns
 *
 * This program produces an animated sine wave in a gnuplot window.
 * It does so by reeatedly calling gnuplot_resetplot() and gnuplot_cmd()
 * in a loop.
 * The gnuplot window closes after all equation-plots have been generated.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../gnuplot_i.h"

#define SECONDS 5

int main(int argc, char *argv[]) {
  gnuplot_ctrl *handle;

  printf("*** example of world gnuplot control through C ***\n");
  handle = gnuplot_init();

  gnuplot_setterm(handle, "wxt", 900, 400);
  gnuplot_resetplot(handle);
  gnuplot_cmd(handle, "unset key");
  gnuplot_cmd(handle, "set grid");
  gnuplot_cmd(handle, "set format ''");
  gnuplot_cmd(handle, "set tics scale 0");
  gnuplot_cmd(handle, "plot 'world.dat' with lines linestyle 1");

  sleep(SECONDS);

  gnuplot_close(handle);
  return 0;
}
