
#include <string>
#include <vector>
#include "../include/Loader.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <fstream>

Loader::Loader()
{
}

void Loader::import( std::string filename )
{
    this->importer = new Assimp::Importer();
    this->scene = this->importer->ReadFile(filename, aiProcessPreset_TargetRealtime_Quality);
    assert( this->scene != NULL );
    this->importer->SetPropertyInteger( AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT );
}

void Loader::loadData(std::vector<Triangle> &triangles)
{
    vector<glm::vec3> positions;
    if( this->scene->HasMeshes() )
    {
        for( unsigned int i = 0; i < this->scene->mNumMeshes; i++ )
        {
            aiMesh *mesh = this->scene->mMeshes[ i ];
            for( unsigned int j = 0; j < mesh->mNumVertices; j++ )
            {
                const aiVector3D& position = mesh->mVertices[ j ];
                glm::vec3 v = glm::vec3( position.x, position.y, position.z );
                positions.push_back( v );
            }
            for( unsigned int j = 0; j < mesh->mNumFaces; j++ )
            {
                const aiFace& face = mesh->mFaces[ j ];
                if( face.mNumIndices == 3 )
                {
                    Point p1(positions[face.mIndices[0]].x, positions[face.mIndices[0]].y, positions[face.mIndices[0]].z);
                    Point p2(positions[face.mIndices[1]].x, positions[face.mIndices[1]].y, positions[face.mIndices[1]].z);
                    Point p3(positions[face.mIndices[2]].x, positions[face.mIndices[2]].y, positions[face.mIndices[2]].z);
                    Triangle t(p1, p2, p3);
                    triangles.push_back(t);
                }
            }
        }
    }
}
