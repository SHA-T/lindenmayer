# Lindenmayer-System
This is an implementation of the context-free [Lindenmayer system](https://en.wikipedia.org/wiki/L-system) to create fractals.

A lot of natural phenomena like the looks of trees or snowflakes can be described by Lindenmayer fractals. Those fractals reproduce themself recursively with the same patterns and eventually create structures we know from nature.

You can create your own fractals in the main.cpp where you specify the initial word and the production rules.
The results will be saved as svg-files in the 'results' folder. In the folder 'examples' are some examples of common fractals.

## Examples
Fractal Tree:
Stage 1 | Stage 2 | Stage 3
:---:|:---:|:---:
![image](https://user-images.githubusercontent.com/50293935/153272618-fa48f0f0-1b24-4b68-a114-660a09970394.png) | ![image](https://user-images.githubusercontent.com/50293935/153273011-1601abea-f83f-4b2f-8396-641a4996b66a.png) | ![image](https://user-images.githubusercontent.com/50293935/153274667-3b386b4f-2913-40bc-8dbd-763820c9a588.png)
Stage 4 | Stage 5
![image](https://user-images.githubusercontent.com/50293935/153275281-e2f1b380-f089-4e34-b7ce-9c8fa330d039.png) | ![image](https://user-images.githubusercontent.com/50293935/153275382-3bf85602-8847-4e97-9c15-a5c5f0267b10.png)

Fractal Koch Snowflake:
Stage 1 | Stage 2 | Stage 3
:---:|:---:|:---:
![image](https://user-images.githubusercontent.com/50293935/153276783-d098b02d-a921-4760-a655-ef89ad75169d.png) | ![image](https://user-images.githubusercontent.com/50293935/153276918-9d934037-66eb-4a65-ab0b-82e731626365.png) | ![image](https://user-images.githubusercontent.com/50293935/153276980-063d3eab-a1c2-492a-a51d-b8c95348e363.png)
Stage 4 | Stage 5  | Stage 6
![image](https://user-images.githubusercontent.com/50293935/153278496-a0e9336e-d9db-4e81-b4fd-61bd0f4e60f0.png) | ![image](https://user-images.githubusercontent.com/50293935/153278587-fc5bf9be-1e08-4a1e-9c4a-a79e73b9a4ef.png) | ![image](https://user-images.githubusercontent.com/50293935/153278646-a54e3249-2bf5-4bba-a6dc-d1e289eba83c.png)

## Requirements
This program was tested on
- Fedora 33, 64-Bit
- GCC 10

but might also work on other versions
