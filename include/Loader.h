#ifndef __LOADER_HPP
#define __LOADER_HPP

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "Triangle.h"
class Loader{
    public:
        Loader();
        void import( std::string filename );
        void loadData(std::vector<Triangle> &triangles);
    private:
        const aiScene *scene;
        Assimp::Importer *importer;
};

#endif
