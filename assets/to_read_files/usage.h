/*

  _______  _______  _______  _______ _________ _______  _
(  ____ \(  ____ )(  ___  )(  ____ \\__   __/(  ___  )( \
| (    \/| (    )|| (   ) || (    \/   ) (   | (   ) || (
| (__    | (____)|| (___) || |         | |   | |   | || |
|  __)   |     __)|  ___  || |         | |   | |   | || |
| (      | (\ (   | (   ) || |         | |   | |   | || |
| )      | ) \ \__| )   ( || (____/\   | |   | (___) || (____/\
|/       |/   \__/|/     \|(_______/   )_(   (_______)(_______/


Usage:

./fractol <fractol_index>

fractol_index {
	1: "Mandelbrot"
	2: "Julia"
	3: "Burning Ship"
}

example:
	./fractol 1
	./fractol 2 -0.8 0.156 (if fractol_index == 2
	you can add 2 more arguments to change the Julia set)
*/
