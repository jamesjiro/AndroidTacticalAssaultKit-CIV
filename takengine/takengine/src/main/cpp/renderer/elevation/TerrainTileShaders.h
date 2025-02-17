#ifndef TAK_ENGINE_RENDERER_ELEVATION_TERRAINTILESHADERS_H_INCLUDED
#define TAK_ENGINE_RENDERER_ELEVATION_TERRAINTILESHADERS_H_INCLUDED

#include "renderer/Shader.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Elevation {
                struct TerrainTileShader
                {
                    TerrainTileShader() NOTHROWS;
                    TerrainTileShader(const TerrainTileShader &other) NOTHROWS;

                    TerrainTileShader &operator=(const TerrainTileShader &other) NOTHROWS;

                    TAK::Engine::Renderer::Shader2 base;
                    // base references
                    GLuint &handle;
                    GLint &uMVP;
                    GLint &uTexture;
                    GLint &uSunPosition;
                    GLint &uColor;
                    GLint &uInvModelView;
                    GLint &aTexCoords;
                    GLint &aVertexCoords;
                    GLint &aNormals;
                    GLint &uNormalMatrix;
                    // vertex shader
                    GLint uModelViewOffscreen {-1};
                    GLint uLocalTransform {-1};
                    GLint uTexWidth {-1};
                    GLint uTexHeight {-1};
                    GLint uElevationScale {-1};
                    GLint aNoDataFlag {-1};
                };

                struct TerrainTileShaders
                {
                    TerrainTileShader hi;
                    TerrainTileShader md;
                    TerrainTileShader lo;
                    /** if `drawMapResolution` <= threshold, use `hi` */
                    double hi_threshold;
                    /** if `drawMapResolution` <= threshold, use `md` */
                    double md_threshold;
                };
            }
        }
    }
}

#endif

