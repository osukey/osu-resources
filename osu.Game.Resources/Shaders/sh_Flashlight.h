﻿#ifdef GL_ES
    precision mediump float;
#else
    // Since glsl 1.1 doesn't define precision qualifiers but GL_ES does, 
    // Define them as nothing to avoid compilation issues.
    #define lowp
    #define highp
#endif

varying vec2 v_Position;
varying vec4 v_Colour;

uniform vec2 flashlightPos;
uniform vec2 flashlightSize;

uniform float flashlightDim;

const float smoothness = 1.1;

vec4 getColourAt(vec2, vec2, vec4);

void main(void)
{
    gl_FragColor = mix(getColourAt(flashlightPos - v_Position, flashlightSize, v_Colour), vec4(0.0, 0.0, 0.0, 1.0), flashlightDim);
}