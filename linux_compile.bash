#!/bin/bash

gcc *.c execution/*.c parser/*.c gnl/*.c general_utils/*.c -o minicub3d \
  -I minilibx-linux \
  -L minilibx-linux \
  -lmlx -lXext -lX11 -lm
