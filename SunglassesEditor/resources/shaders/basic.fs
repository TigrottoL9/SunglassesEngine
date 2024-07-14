#version 460

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

void main()
{
    //Info della scena, TODO: falle diventare uniform
    vec3 ligthDir = normalize(vec3(0, 1, 0.5));
    vec4 ambient = vec4(0.79, 0.94, 0.97, 1);
    vec3 normal = normalize(fragNormal);

    //Colore texture
    vec4 texelColor = texture(texture0, fragTexCoord);

    //Calcolo diffuse
    float dot = dot(ligthDir, normal);
    dot = pow(dot * 0.5 + 0.5, 2.0);

    //Calcola colore finale del pixel
    finalColor = texelColor*colDiffuse*vec4(dot, dot, dot, 1);
    finalColor += texelColor*(ambient/10.0)*colDiffuse;
}
