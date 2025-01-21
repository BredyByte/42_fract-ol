
# 👾 Fract'ol 👾 

> This repository contains "fract-ol" project that is part of the École 42 curriculum.

<img width="1101" alt="Screen Shot 2023-08-25 at 3 12 12 PM" src="https://github.com/Dvaid0805/42_fractol/assets/81176650/ee129708-1d0f-450d-8388-75e682391b43">

## 🔞 About the Project

The aim is to learn how to create graphical applications using the MLX42 library.

MLX42 is a powerful library from [codam-coding-college](https://github.com/codam-coding-college/MLX42) designed to simplify various tasks and provide additional features.

A program implements the following fractals:

- Mandelbrot set (selected with 1) 
- Julia set (selected with 2)
- Burning Ship (selected with 3)

By completing this project, students will gain experience creating 2D graphics applications and working with an open source library. The fractal visualizations also provide an interesting mathematical component.

## 🤙 Usage

Before running the program, ensure you have the necessary libraries installed, depending on your operating system.

### macOS

```bash
brew update
brew install glfw
```

If you are a student of 42 Málaga and encounter the error "command not found: brew" run the following command to install Homebrew:
```bash
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
```

### Linux

```bash
sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

In case you encounter any issues with compilation or functionality, refer to the MLX42 documentation available in the `assets/MLX42` folder. The documentation provides comprehensive information about the library, including troubleshooting tips and usage guidelines.

Once the libraries are installed, you can build and run the program using the following commands:

```
make
./fractol 1/2/3
```
Replace 1/2/3 with the desired fractal selection:
   * 1:Mandelbrot set
   * 2: Julia set
   * 3: Burning Ship fractal

## 🤦‍♂️ Understanding Fractals

The following resources provide useful background on fractals and complex numbers:

1. What's so special about the Mandelbrot Set? - Numberphile

   - https://www.youtube.com/watch?v=FFftmWSzgmk

1. Interactive Mandelbrot set

   - https://www.geogebra.org/m/BUVhcRSv
   
1. The Mandelbrot Set - Numberphile

   - https://www.youtube.com/watch?v=NGMRB4O922I
   
## Links

- MLX42 library documentation: https://github.com/codam-coding-college/MLX42
