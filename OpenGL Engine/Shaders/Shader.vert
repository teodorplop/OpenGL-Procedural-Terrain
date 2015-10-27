// Shader-ul de varfuri  
 
 #version 130


in vec4 in_Position;
in vec4 in_Color;

out vec4 gl_Position; 
out vec4 ex_Color;

void main(void)
  {
    gl_Position = in_Position;
    ex_Color = in_Color;
   } 
 