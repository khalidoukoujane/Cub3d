#!/bin/bash

gcc test.c -o minicub3d \
  -I minilibx-linux \
  -L minilibx-linux \
  -lmlx -lXext -lX11 -lm
