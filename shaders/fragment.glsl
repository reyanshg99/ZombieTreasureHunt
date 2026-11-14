#version 330 core
in vec3 col;
in vec3 worldPos;
in vec3 worldNormal;
in float viewDepth;
in vec2 uv;
out vec4 FragColor;
uniform int flatMode;
uniform int flashlightOn;
uniform int useTexture;
uniform sampler2D albedo;
uniform vec3 fogColor;
uniform vec3 lightDir;
uniform vec3 baseColor;
uniform vec3 cameraPos;
uniform vec3 cameraDir;
void main() {
    vec3 texel = useTexture == 1 ? texture(albedo, uv).rgb : vec3(1.0);
    float diffuse = max(0.0, dot(normalize(worldNormal), normalize(lightDir)));
    float cone = dot(normalize(cameraDir), normalize(worldPos - cameraPos));
    float beam = smoothstep(0.82, 0.96, cone) * (1.0 - smoothstep(4.0, 25.0, viewDepth)) * float(flashlightOn);
    float light = flatMode == 1 ? 1.0 : (0.32 + diffuse * 0.38 + beam * 0.72);
    float fog = flatMode == 1 ? 0.0 : clamp((viewDepth - 34.0) / 55.0, 0.0, 0.38);
    FragColor = vec4(mix(baseColor * col * texel * light, fogColor, fog), 1.0);
}
