#version 330 core
layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aColor;
layout(location=2) in vec3 aNormal;
layout(location=3) in vec2 aUV;
layout(location=4) in ivec4 aBoneIds;
layout(location=5) in vec4 aWeights;
out vec3 col;
out vec3 worldPos;
out vec3 worldNormal;
out float viewDepth;
out vec2 uv;
uniform mat4 model, view, projection;
uniform mat4 bones[128];
uniform int skinned;
uniform int zombiePose;
uniform float zombiePhase;
vec3 poseZombie(vec3 p) {
    if (zombiePose != 0) {
        float side = p.x < 0.0 ? -1.0 : 1.0;
        // The supplied static Reallusion mesh is a T-pose. Swing both arms down
        // from their shoulders and alternate the legs in the vertex shader.
        if (abs(p.x) > 21.0 && p.y > 100.0) {
            float shoulderX = side * 22.0;
            float shoulderY = 132.0;
            float angle = -side * (0.86 + 0.09 * sin(zombiePhase * 4.0 + side));
            vec2 d = p.xy - vec2(shoulderX, shoulderY);
            p.xy = vec2(shoulderX, shoulderY) + mat2(cos(angle), sin(angle), -sin(angle), cos(angle)) * d;
        }
        if (abs(p.x) > 8.0 && abs(p.x) < 34.0 && p.y > 8.0 && p.y < 94.0) {
            float swing = 0.17 * sin(zombiePhase * 5.0 + (side < 0.0 ? 0.0 : 3.14159));
            float c = cos(swing), s = sin(swing);
            float dy = p.y - 94.0, dz = p.z;
            p.y = 94.0 + c * dy - s * dz;
            p.z = s * dy + c * dz;
        }
    }
    return p;
}
void main() {
    vec3 posed = poseZombie(aPos);
    mat4 skin = mat4(1.0);
    float sum = dot(aWeights, vec4(1.0));
    if (skinned == 1 && sum > 0.001)
        skin = bones[aBoneIds.x]*aWeights.x + bones[aBoneIds.y]*aWeights.y + bones[aBoneIds.z]*aWeights.z + bones[aBoneIds.w]*aWeights.w;
    vec4 world = model * skin * vec4(posed, 1.0);
    worldPos = world.xyz;
    worldNormal = normalize(transpose(inverse(mat3(model * skin))) * aNormal);
    viewDepth = abs((view * world).z);
    col = aColor;
    uv = aUV;
    gl_Position = projection * view * world;
}
