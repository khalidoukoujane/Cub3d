# Executable
NAME = cub3D

# Compilation
CC = cc
COMPL_FLAGS = -lmlx -framework OpenGL -framework AppKit
COMPL_FLAGS = -I mlx -L mlx -lmlx -lXext -lX11 -lm
COMPL_FLAGS =
LINK_FLAGS = 
# -g -fsanitize=thread

COMPILE = $(CC) $(COMPL_FLAGS)
LINK = $(CC) $(LINK_FLAGS)


# obj dirs
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR)/parser $(OBJ_DIR)/execution $(OBJ_DIR)/general_utils $(OBJ_DIR)/gnl
PARS = parser
GNL = gnl
EXEC = execution

UTILS_FILES = collision.c  ft_isalnum.c  ft_isprint.c             ft_lstclear_bonus.c   ft_lstmap_bonus.c   ft_memcmp.c   ft_putchar_fd.c  ft_split.c     ft_strlcpy.c  ft_strrchr.c  radian.c \
		ft_atoi.c    ft_isalpha.c  ft_itoa.c                ft_lstdelone_bonus.c  ft_lstnew_bonus.c   ft_memcpy.c   ft_putendl_fd.c  ft_strcmp.c    ft_strmapi.c  ft_strtrim.c  \
		ft_bzero.c   ft_isascii.c  ft_lstadd_back_bonus.c   ft_lstiter_bonus.c    ft_lstsize_bonus.c  ft_memmove.c  ft_putnbr_fd.c   ft_striteri.c  ft_strncmp.c  ft_tolower.c \
		ft_calloc.c  ft_isdigit.c  ft_lstadd_front_bonus.c  ft_lstlast_bonus.c    ft_memchr.c         ft_memset.c   ft_putstr_fd.c   ft_strlcat.c   ft_strnstr.c  ft_toupper.c

UTILS = $(addprefix general_utils/, $(UTILS_FILES:.c=.o))

# INC
INC = general_utils/utils.h gnl/get_next_line.h cub.h structs.h

# SRC
SRC = $(PARS)/config.c $(PARS)/ft_error.c $(PARS)/ft_spliter.c $(PARS)/grep_file_data.c $(PARS)/is_match.c $(PARS)/map_config.c $(PARS)/parser.c \
		$(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c \
		$(UTILS) \
		$(EXEC)/equ_utils.c $(EXEC)/events.c $(EXEC)/init.c $(EXEC)/ray_utils.c $(EXEC)/render.c $(EXEC)/utils.c $(EXEC)/wrappers.c \
		main.c

# OBJ
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(LINK) $(OBJ) -o $@
	@echo "[CREATING the legendary executable $@...]"

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)
	@echo "[CREATING object directories...]"

$(OBJ_DIR)/%.o: %.c $(INC) | $(OBJ_DIRS)
	@$(COMPILE) -c $< -o $@
	@echo "[COMPILING $<...]"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[CLEANING object files...]"

fclean: clean
	@rm -f $(NAME)
	@echo "[CLEANING the executable...]"

re: fclean all
