# fdf_wireframe_model
This project is about creating a simple wireframe model representation of a 3D land-scape by linking various points (x, y, z) thanks to line segments (edges) using the MiniLibX library.
- Functions allowed: open, close, read, write, malloc, free, perror, strerror, exit, All functions of the math
library, All functions of the MiniLibX.
- Project Requirements:
    - Render 3D isometric view given a map.fdf
    - Zoom in and out
    - Translate model
    - Rotate Model
    - Add one feature of choice (adjustable altitude) 

Example of a .fdf file map to be passed into the program
<pre>
$cat ./42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

Each number represents a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.
</pre>

### Project Documentations
make


### To be improved
- Handle non-exisitent input file and files without permission.
- To use MLX Images instead of plotting pixel
- Handle scaling issues from Double to Int will cause rounding errors after multiple zoom operations
- Add live rotation and translation while mouse is on hold
- Add colours
- Shade nodes to transform wireframe into solid 3D
