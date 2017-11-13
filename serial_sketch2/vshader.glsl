#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform mat4 mvp_matrix;

in vec4 vPosition;
in vec4 vColor;

out vec4 color;
//! [0]
void main()
{
    // Calculate vertex position in screen space
    gl_Position = mvp_matrix * vPosition;

    color=vColor;
}
//! [0]
