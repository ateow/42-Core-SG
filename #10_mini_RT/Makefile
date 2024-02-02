NAME = miniRT
BONUS = miniRT_bonus

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./mlx_linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRCS = main.c\
		colour.c\
		rt_readfile_0.c\
		rt_freestruct_0.c\
		rt_makestruct_0.c\
		rotate.c\
		rt_makestruct_scene.c\
		rt_makestruct_lights.c\
		rt_makestruct_plane.c\
		rt_makestruct_sphere.c\
		rt_makestruct_cylinder.c\
		rt_makestruct_cone.c\
		render_utils.c\
		rgb_math_0.c\
		xyz_math_0.c\
		xyz_math_1.c\
		trace_light_ray.c\
		trace_shadow.c\
		trace_get_surfnorm.c\
		intersection_main.c\
		intersection_cylinder.c\
		intersection_sphere.c\
		intersection_plane.c\
		intersection_cone.c\
		ui_main_keyhook.c\
		ui_win_resize.c\
		ui_objs.c\
		ui_objs_sphere_control.c\
		ui_objs_plane_control.c\
		ui_objs_cylinder_control.c\
		ui_objs_cone_control.c\
		ui_objs_display_utils.c\
		ui_objs_display_cy_co.c\
		ui_objs_display_pl_sp.c\
		generate_skin_bump.c\
		map_checkerboard.c\
		map_skin_bump.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
AR = ar rc
RM = rm -rf

all: $(NAME) $(BONUS)
bonus: $(BONUS)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(MINILIBX) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(BONUS): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(FLAGS) -o $(BONUS) $(MINILIBX) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


$(OBJS): $(SRCS)
	@$(CC) $(FLAGS) -c $(SRCS)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(MINILIBX):
	@make -C $(MINILIBX_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(OBJS)
	@$(RM) $(BONUS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
