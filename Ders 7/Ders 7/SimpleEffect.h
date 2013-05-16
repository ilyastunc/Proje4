//
//  SimpleEffect.h
//  Ders 7
//
//  Created by Gurel Erceis on 4/15/13.
//  Copyright (c) 2013 Yogurt3D. All rights reserved.
//

#ifndef Ders_7_SimpleEffect_h
#define Ders_7_SimpleEffect_h
#include "Effect.h"

class SimpleEffect: public Effect{
public:
    SimpleEffect(int* screen_width, int* screen_height):Effect("effect_simple.frag",screen_width, screen_height){
        UniformOffset = glGetUniformLocation(programID, "offset");
        if (UniformOffset == -1) {
            fprintf(stderr, "Could not bind attribute %s\n", "offset");
        } 
    }
    virtual void draw(){
        glUseProgram(programID);
        //GLfloat move = glutGet(GLUT_ELAPSED_TIME) / 1000.0 * 2*3.14159 * .75;  // 3/4 of a wave cycle per second
        //glUniform1f(UniformOffset, move);
        Effect::draw();

		float3 InColor = tex2D(fbo_texture, IN.UV).xyz;
		float3 OutColor;
		OutColor.r = tex1D(ColorCorrMap, InColor.r).r;
		OutColor.g = texture1D(ColorCorrMap, InColor.g).g;
		OutColor.b = texture1D(ColorCorrMap, InColor.b).b;
    }
private:
    GLuint UniformOffset;
};

#endif
