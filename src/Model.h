#pragma once
#include <GL/glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <glm/glm.hpp>
#include <string>
#include <unordered_map>
#include <vector>

class Model {
public:
    Model() = default;
    ~Model();
    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;
    static bool validateAsset(const std::string& path, unsigned minMeshes=1, unsigned minAnimations=0, unsigned minBones=0);
    static bool hasAnimationClip(const std::string& path, const std::string& clip);
    static bool validateImage(const std::string& path);
    bool load(const std::string& path, const std::string& fallbackTexture = {});
    bool valid() const { return scene_ != nullptr && !meshes_.empty(); }
    void releaseGpu();
    void draw(GLuint shader, const glm::mat4& transform,
              const std::string& clip = {}, float seconds = 0.f,
              const glm::vec3& tint = glm::vec3(1.f));
private:
    struct Mesh { GLuint vao=0,vbo=0,ebo=0,texture=0; GLsizei indices=0; glm::vec3 color{1.f}; std::string materialName; };
    struct Vertex { glm::vec3 p,n,color; glm::vec2 uv; glm::ivec4 boneIds{0}; glm::vec4 weights{0.f}; };
    Assimp::Importer importer_;
    const aiScene* scene_=nullptr;
    std::vector<Mesh> meshes_;
    std::unordered_map<std::string,unsigned> boneIds_;
    std::vector<aiMatrix4x4> offsets_;
    GLuint fallbackTexture_=0;
    glm::mat4 globalInverse_{1.f};
    std::string directory_;
    GLuint cachedShader_=0;
    GLint modelUniform_=-1,bonesUniform_=-1,skinnedUniform_=-1,useTextureUniform_=-1,baseColorUniform_=-1,albedoUniform_=-1,zombiePoseUniform_=-1,zombiePhaseUniform_=-1;
    GLuint loadTexture(const std::string& path);
    void visitNode(aiNode* node, const aiMatrix4x4& parent,
                   const std::unordered_map<std::string,const aiNodeAnim*>& channels,
                   const aiAnimation* animation, double time, bool proceduralZombie, bool hitReaction,
                   std::vector<glm::mat4>& bones);
    glm::mat4 toGlm(const aiMatrix4x4& m) const;
    void destroy();
};
