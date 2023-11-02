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
$ cat ./42.fdf
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
Create and execute program
<pre>
$ make
$ ./fdf ./maps/42.fdf
</pre>
Controls
<pre>
Left click and drag to translate
Middle click and drag to rotate
Scroll to zoom
'+' to increase height
'-' to decrease height
'r' or '0' to reset model and present default view
'1' for iso view
'2' for plan view
'3' for front view
'4' for side view
'esc' to exit
'up' to rotate x
'down' to rotate x
'left' to rotate y
'right' to rotate y
'[' to rotate z
']' to rotate z
</pre>
Adjust Parameters
<pre>
Change Window Size (/srcs/fdf.c)
  line 68	data.win_size.x = 1500;
  line 69	data.win_size.y = 1500;
	
Change Default Model Offsets (/srcs/projection.c)
  line 25	data->zoom_xy = data->win_size.x / (2 * data->map_size.x);
  line 26	data->zoom_z = data->zoom_xy / 5;

Change Default Rotation Angle (/srcs/projection.c)
  line 31	data->angle.x = 30 * M_PI / 180;
  line 32	data->angle.y = -30 * M_PI / 180;
  line 33	data->angle.z = 30 * M_PI / 180;

Change Limits of Scale and Zoom (/srcs/projection.c)
  line 19	data->counter_zoom = 0;
  line 20	data->counter_scale = 0;
</pre>
### To be improved
- Handle non-exisitent input file and files without permission.
- To use MLX Images instead of plotting pixel
- Handle scaling issues from Double to Int will cause rounding errors after multiple zoom operations
- Add live rotation and translation while mouse is on hold
- Add colours
- Shade nodes to transform wireframe into solid 3D
