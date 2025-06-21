#!/bin/bash

if [ "$USER" == "ioulkhir" ]; then
  rm -fr parser/mini_main.c
fi

gcc *.c execution/*.c parser/*.c gnl/*.c general_utils/*.c -o minicub3d \
  -I mlx \
  -L mlx \
  -lmlx -lXext -lX11 -lm

  # -g -fsanitize=address \