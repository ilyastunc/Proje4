#version 120

uniform sampler2D fbo_texture;
uniform float offset;
varying vec2 f_texcoord;

float vec3 InColor;
vec3 OutColor;
 
void main(void) {
    vec2 texcoord = f_texcoord;
    texcoord.x += sin(texcoord.y * 4*2*3.14159 + offset) / 100;
    InColor = texture1D(fbo_texture, texcoord);
    
}

