#include <mlx.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int main()
{

	void	*mlx;
	void	*mlx_win;
    t_data img;
	char	*relative_path = "./ironman.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 640, "hello");
    img.img= mlx_new_image(mlx, 640, 640);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
		img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0*50 , 1*50 );
	mlx_loop(mlx);
}