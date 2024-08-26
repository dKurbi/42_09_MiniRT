# MiniRT - My First RayTracer with miniLibX

## Overview

**MiniRT** is an introductory project to the world of **Ray Tracing**, an advanced technique for rendering three-dimensional computer-generated images. Unlike rasterization, Ray Tracing is known for offering a higher level of visual realism, though at the cost of increased computational demands.

This project was developed in **C** using **miniLibX**, and its goal is to generate images from scenes described in `.rt` files. Each scene is viewed from a specific angle and position, consisting of simple geometric objects like spheres, planes, and cylinders, along with a lighting system.

## Key Features

- **Basic geometric objects:** Spheres, planes, and cylinders.
- **Transformations:** Apply translation and rotation to objects, lights, and cameras.
- **Lighting management:** Ambient light, diffuse light, and hard shadows.
- **Graphical interface:** Display the rendered scene in a window with event handling (close window with `ESC` or the close button).
- **File format:** The program accepts scene descriptions in `.rt` files.

## System Requirements

- **Language:** C
- **Libraries:** miniLibX, Math Library (-lm), Libft (authorized)
- **Platform:** Unix (Linux or macOS)

## Usage

### Compilation

The project includes a **Makefile** with the following rules:
- `make all` - Compile the project.
- `make clean` - Remove object files.
- `make fclean` - Remove object files and the executable.
- `make re` - Clean and recompile the project.

### Execution

To run the program, simply compile it and then pass a `.rt` file as an argument:

```bash
./miniRT [scene.rt]
```
## .rt File Format
Each .rt file describes a scene using identifiers for different components:

- Ambient Lighting: A [lighting ratio] [R,G,B colors]
- Camera: C [x,y,z coordinates] [orientation vector] [field of view]
- Light: L [x,y,z coordinates] [brightness] [R,G,B colors]
- Sphere: sp [x,y,z coordinates] [diameter] [R,G,B colors]
- Plane: pl [x,y,z coordinates] [normal vector] [R,G,B colors]
- Cylinder: cy [x,y,z coordinates] [orientation vector] [diameter] [height] [R,G,B colors]

## Example of .rt File

```bash
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,50,0 0.6 10,0,255
sp 0.0,0.0,20.6 12.6 10,0,255
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,255
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```

## Example Output
The program generates simple 3D images with the described characteristics. Examples include:

- Spheres illuminated by spotlights.
- Cylinders with rotation and translation transformations.
- Shadows cast by objects onto surfaces.

## Contributions
This project was developed as part of the curriculum at **42 Barcelona Fundación Telefónica**. Any suggestions or contributions are welcome.

## Credits
Developed by **[Diego Kurcbart](https://www.linkedin.com/in/diegokurcbart/)** and **[Insar Assambekov](https://github.com/InsAsam)** as part of the MiniRT project at 42 Barcelona.

License
This project is licensed under the MIT License - see the LICENSE file for details.
