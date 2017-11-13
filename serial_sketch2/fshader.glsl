#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

in vec4 color;
out vec4 fColor;

//! [0]
void main()
{
    // Set fragment color from texture
    fColor=color;
}
//! [0]

