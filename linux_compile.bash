#!/bin/bash

gcc *.c */*.c -o minicub3d \
  -I minilibx-linux \
  -L minilibx-linux \
  -lmlx -lXext -lX11 -lm
