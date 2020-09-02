#version 460

uniform sampler2D texture;
uniform float outLineSize = 0.01;
uniform float outLineR = 1.0;
uniform float outLineG = 1.0;
uniform float outLineB = 1.0;
uniform float outLineA= 1.0;


void main()
{   
    vec4 outLineColor = vec4(outLineR,outLineG,outLineB,outLineA);
	// lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    if(pixel.a == 0.0)
    {
        if(texture2D(texture, gl_TexCoord[0].xy + vec2(0.0, outLineSize)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy - vec2(0.0, outLineSize)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy + vec2(outLineSize, 0.0)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy - vec2(outLineSize, 0.0)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy + vec2(outLineSize, outLineSize)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy - vec2(outLineSize, outLineSize)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy + vec2(outLineSize, -outLineSize)).a != 0.0 ||
           texture2D(texture, gl_TexCoord[0].xy - vec2(outLineSize, -outLineSize)).a != 0.0
        )
        {
            pixel = outLineColor;
        }
    }


    // multiply it by the color
    gl_FragColor = pixel;
}