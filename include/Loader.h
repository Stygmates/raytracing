#ifndef __LOADER_HPP
#define __LOADER_HPP

#include <string>
#include <vector>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "Shape.h"

/**
 * @brief The Loader class: Helper class that loads an obj into an array of triangles
 */
class Loader{
    public:
    /**
         * @brief Loader Loader constructor
         */
        Loader();

        /**
         * @brief import Import the file specified with filename
         * @param filename The path to the obj
         */
        void import( std::string filename );

        /**
         * @brief loadData Loads the triangles into an array of triangles
         * @param triangles The array of triangles where the triangles from the obj will be stored
         */
        void loadData(std::vector<Shape*> &shapes);
    private:
        /**
         * @brief scene Necessary attribute to use assimp
         */
        const aiScene *scene;

        /**
         * @brief importer Necessary attribute to use assimp
         */
        Assimp::Importer *importer;
};

#endif
