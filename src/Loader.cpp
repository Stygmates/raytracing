
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <fstream>
#include "../include/Loader.h"
#include "Triangle.h"
#include "Color.h"

Loader::Loader()
{
}

void Loader::import( std::string filename )
{
    cerr << "Loading file" << endl;
    this->importer = new Assimp::Importer();
    this->scene = this->importer->ReadFile(filename, aiProcessPreset_TargetRealtime_Quality);
    if(this->scene == NULL)
    {
        std::cerr << "Loader::import: No scene loaded" << std::endl;
    }
    this->importer->SetPropertyInteger( AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT );
    cerr << "Importing file" << endl;
}

void Loader::loadData(std::vector<Shape*> &shapes)
{
    cerr << "Loading data" << endl;
    if(this->scene == NULL)
    {
        std::cerr << "Loader::loadData: No scene loaded" << std::endl;
        return;
    }
    if( this->scene->HasMeshes() )
    {
        for( unsigned int i = 0; i < this->scene->mNumMeshes; i++ )
        {
            vector<Point> positions;
            aiMesh *mesh = this->scene->mMeshes[ i ];

            aiMaterial *mtl = scene->mMaterials[mesh->mMaterialIndex];
            aiColor4D aiDiffuse;
            Color diffuse;
            if(aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &aiDiffuse) == AI_SUCCESS)
            {
                diffuse.set_red(aiDiffuse.r);
                diffuse.set_green(aiDiffuse.g);
                diffuse.set_blue(aiDiffuse.b);
            }

            aiColor4D aiSpecular;
            Color specular;
            if(aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &aiSpecular) == AI_SUCCESS)
            {
                specular.set_red(aiSpecular.r);
                specular.set_green(aiSpecular.g);
                specular.set_blue(aiSpecular.b);
            }

            aiColor4D aiAmbient;
            Color ambient;
            if(aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &aiAmbient) == AI_SUCCESS)
            {
                ambient.set_red(aiAmbient.r);
                ambient.set_green(aiAmbient.g);
                ambient.set_blue(aiAmbient.b);
            }
            float shininess = 0.f;
            float aiShininess = 0.f;
            if(aiGetMaterialFloat(mtl, AI_MATKEY_SHININESS, &aiShininess) == AI_SUCCESS)
            {
                shininess = aiShininess;
            }
            Material material(ambient, diffuse, specular, shininess);

            for( unsigned int j = 0; j < mesh->mNumVertices; j++ )
            {
                const aiVector3D& position = mesh->mVertices[ j ];
                Point v = Point( position.x, position.y, position.z );
                positions.push_back( v );
            }
            for( unsigned int j = 0; j < mesh->mNumFaces; j++ )
            {
                const aiFace& face = mesh->mFaces[ j ];
                if( face.mNumIndices == 3 )
                {
                    Point p1(positions[face.mIndices[0]].get_x(), positions[face.mIndices[0]].get_y(), positions[face.mIndices[0]].get_z());
                    Point p2(positions[face.mIndices[1]].get_x(), positions[face.mIndices[1]].get_y(), positions[face.mIndices[1]].get_z());
                    Point p3(positions[face.mIndices[2]].get_x(), positions[face.mIndices[2]].get_y(), positions[face.mIndices[2]].get_z());
                    Triangle *t = new Triangle(p1, p2, p3, material);
                    shapes.push_back(t);
                }
            }
        }
    }
    cerr << "Loading data done" << endl;
}
