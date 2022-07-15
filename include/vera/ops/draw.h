#pragma once

#include <vector>

#include "vera/gl/vbo.h"
#include "vera/gl/shader.h"
#include "vera/shaders/defaultShaders.h"

#include "vera/types/boundingBox.h"
#include "vera/types/image.h"
#include "vera/types/font.h"
#include "vera/types/line.h"
#include "vera/types/mesh.h"
#include "vera/types/scene.h"
#include "vera/types/triangle.h"

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#include <emscripten/html5.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#endif

namespace vera {

enum PointShape {
    SQUARE_SHAPE = 0,
    SQUARE_OUTLINE_SHAPE,
    DOT_SHAPE,
    DOT_OUTLINE_SHAPE,
    CROSS_SHAPE,
    X_SHAPE
};

// GENERAL GL STATE
// ---------------------------------
bool fullscreen();
void fullscreen(bool _fullscreen);

void print(const std::string& _text);
void frameRate(int _fps);
// cursor()
// noCursor()

float pixelDensity();
void pixelDensity(float _density);

void clear();
void clear( float _brightness );
void clear( const glm::vec3& _color );
void clear( const glm::vec4& _color );

void fill( float _brightness );
void fill( float _red, float _green, float _blue);
void fill( float _red, float _green, float _blue, float _alpha);
void fill( const glm::vec3& _color );
void fill( const glm::vec4& _color );
void noFill();

void stroke( float _brightness );
void stroke( float _red, float _green, float _blue);
void stroke( float _red, float _green, float _blue, float _alpha);
void stroke( const glm::vec3& _color );
void stroke( const glm::vec4& _color );
void noStroke();
void strokeWeight(float _weight);

// MATRICES
// -----------------------------
void resetMatrix();
void applyMatrix(const glm::mat3& _mat );
void applyMatrix(const glm::mat4& _mat );
glm::mat4 getProjectionViewWorldMatrix();
const glm::mat4& getProjectionViewMatrix();
const glm::mat4& getProjectionMatrix();
const glm::mat4& getViewMatrix();
const glm::mat4& getWorldMatrix();
glm::mat4* getWorldMatrixPtr();

void rotate(float _rad);
void rotateX(float _rad);
void rotateY(float _rad);
void rotateZ(float _rad);

void scale(float _s);
void scale(float _x, float _y, float _z = 1.0f);
void scale(const glm::vec2& _s);
void scale(const glm::vec3& _s);

void translate(float _x, float _y, float _z = 0.0f);
void translate(const glm::vec2& _t);
void translate(const glm::vec3& _t);

void push();
void pop();

// colorMode()
// erase()
// noErase()

// POINTS
// -----------------------------
void pointSize( float _size );
void pointShape( PointShape _shape );
void points(const std::vector<glm::vec2>& _positions, Shader* _program = nullptr);
void points(const std::vector<glm::vec3>& _positions, Shader* _program = nullptr);
void points(const Line& _line, Shader* _program = nullptr);
void points(const Triangle& _triangle, Shader* _program = nullptr);
void points(const BoundingBox& _bbox, Shader* _program = nullptr);
void pointsBoundingBox(const glm::vec4& _bbox, Shader* _program = nullptr);

// arc()
// ellipse()
// circle()
// quad()
// square()
// triangle()

void line(float _x1, float _y1, float _x2, float _y2, Shader* _program = nullptr);
void line(const glm::vec2& _a, const glm::vec2& _b, Shader* _program = nullptr);
void line(const std::vector<glm::vec2>& _positions, Shader* _program = nullptr);
void line(float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, Shader* _program = nullptr);
void line(const glm::vec3& _a, const glm::vec3& _b, Shader* _program = nullptr);
void line(const std::vector<glm::vec3>& _positions, Shader* _program = nullptr);
void line(const Line& _line, Shader* _program = nullptr);
void line(const Triangle& _triangle, Shader* _program = nullptr);
void line(const BoundingBox& _bbox, Shader* _program = nullptr);
void lineBoundingBox(const glm::vec4& _bbox, Shader* _program = nullptr);

void triangles(const std::vector<glm::vec2>& _positions, Shader* _program = nullptr);
void triangles(const std::vector<glm::vec3>& _positions, Shader* _program = nullptr);

void rect(float _x, float _y, float _w, float _h, Shader* _program = nullptr);
void rect(const glm::vec2& _pos, const glm::vec2& _size, Shader* _program = nullptr);

// IMAGES
// -----------------------------
Image loadImage(const std::string& _name);
void image(const std::string &_path);
void image(const std::string &_path, float _x, float _y, float _width = 0, float _height = 0);
void image(const Image &_img);
void image(const Image *_img);
void image(const Image &_img, float _x, float _y, float _width = 0, float _height = 0);
void image(const Image *_img, float _x, float _y, float _width = 0, float _height = 0);
void image(const Texture &_tex);
void image(const Texture *_tex);
void image(const Texture &_tex, float _x, float _y, float _width = 0, float _height = 0);
void image(const Texture *_tex, float _x, float _y, float _width = 0, float _height = 0);
void image(const TextureStream &_stream);
void image(const TextureStream *_stream);
void image(const TextureStream &_stream, float _x, float _y, float _width = 0, float _height = 0, bool _debug = false);
void image(const TextureStream *_stream, float _x, float _y, float _width = 0, float _height = 0, bool _debug = false);
void image(const Fbo &_fbo);
void image(const Fbo *_fbo);
void image(const Fbo &_fbo, float _x, float _y, float _width = 0, float _height = 0);
void image(const Fbo *_fbo, float _x, float _y, float _width = 0, float _height = 0);
void imageDepth(const Fbo &_fbo, float _x, float _y, float _width = 0, float _height = 0, Camera* _cam = nullptr);
void imageDepth(const Fbo *_fbo, float _x, float _y, float _width = 0, float _height = 0, Camera* _cam = nullptr);
Vbo* getBillboard();

// tint(v1, v2, v3, [alpha])
// tint(value)
// tint(gray, [alpha])
// tint(values)
// tint(color)
// noTint()
// imageMode(mode)

// PIXELS
// -----------------------------
// pixels
// 
// blend(srcImage, sx, sy, sw, sh, dx, dy, dw, dh, blendMode)
// blend(sx, sy, sw, sh, dx, dy, dw, dh, blendMode)
// 
// copy(srcImage, sx, sy, sw, sh, dx, dy, dw, dh)
// copy(sx, sy, sw, sh, dx, dy, dw, dh)
//
// filter(filterType, [filterParam])
// filterType Constant: either THRESHOLD, GRAY, OPAQUE, INVERT, POSTERIZE, BLUR, ERODE, DILATE or BLUR. See Filters.js for docs on each available filter
// filterParam Number: an optional parameter unique to each filter, see above (Optional)
//
// loadPixels()
// get(int _x = 0, int _y = 0, int _width = 0, int _height = 0)
// set(int _x = 0, int _y = 0, const glm::vec4& _color)
// updatePixels(int _x = 0, int _y = 0, int _width = 0, int _height)

// FONT
// -----------------------------
Font* getFont();
Font* getFont(const std::string& _name);
Font* loadFont(const std::string& _file, const std::string& _name = "default");
void  addFont(Font& _font, const std::string _name);
void  addFont(Font* _font, const std::string _name);

// TEXT
// -----------------------------
// textLeading()
// textStyle()
// textWidth()
// textAscent()
// textDescent()
// textWrap()

Font* textFont(const std::string& _name);
void textAlign(FontHorizontalAlign _align, Font* _font = nullptr);
void textAlign(FontVerticalAlign _align, Font* _font = nullptr);
void textAngle(float _angle, Font* _font = nullptr);
void textSize(float _size, Font* _font = nullptr);
void text(const std::string& _text, const glm::vec2& _pos, Font* _font = nullptr );
void text(const std::string& _text, float _x, float _y, Font* _font = nullptr);

// plane()
// box()
// sphere()
// cylinder()
// cone()
// ellipsoid()
// torus()
// p5.Geometry

// SHADERS
// -----------------------------
Shader  loadShader(const std::string& _fragFile, const std::string& _vertFile);
Shader  createShader(const std::string& _fragSrc = "", const std::string& _vertSrc = "");
Shader  createShader(DefaultShaders _frag, DefaultShaders _vert);

void    addShader(Shader& _shader, const std::string& _name);
void    addShader(Shader* _shader, const std::string& _name);
Shader* getShader();
Shader* getShader(const std::string& _name);
Shader* getFillShader();
Shader* getPointShader();
void    resetShader();
void    shader(Shader& _shader);
void    shader(Shader* _shader);
void    shader(const std::string& _name);

// TEXTURES
// -----------------------------
void texture(Texture& _texture, const std::string _name = "");
void texture(Texture* _texture, const std::string _name = "");
// textureMode()
// textureWrap()

// Interaction
// -----------------------------
// debugMode()
// noDebugMode()

// SCENE
// -----------------------------
void setScene(Scene& scene);
void setScene(Scene* scene);
Scene* getScene();

// CAMERA
// -----------------------------
// camera()
void perspective(float _fovy, float _aspect, float _near, float _far);
void ortho(float _left, float _right, float _bottom, float _top,  float _near, float _far);
// frustum()
Camera* createCamera(const std::string& _name = "unnamed");
void addCamera(Camera& _camera, const std::string& _name = "unnamed");
void addCamera(Camera* _camera, const std::string& _name = "unnamed");
void setCamera(Camera& _camera);
void setCamera(Camera* _camera);
void resetCamera();
Camera* getCamera();

// LIGHT
// -----------------------------
// ambientLight()
// specularColor()
// directionalLight()
// pointLight()
// lightFalloff()
// spotLight()
void lights();
void noLights();
Light* createLight(const std::string& _name = "default");
void addLight(Light& _light, const std::string& _name = "default");
void addLight(Light* _light, const std::string& _name = "default");

// MATERIAL
// -----------------------------
// normalMaterial()
// ambientMaterial()
// emissiveMaterial()
// specularMaterial()
// shininess()

// MODEL
// -----------------------------
void loadModel( const std::string& _filename );
void model(Vbo& _vbo, Shader* _program = nullptr);
void model(Vbo* _vbo, Shader* _program = nullptr);

// LABELS
// -----------------------------
void addLabel(Label& _label);
void addLabel(Label* _label);
void addLabel(const std::string& _text, glm::vec3* _position, LabelType _type = LABEL_CENTER, float _margin = 0.0f);
void addLabel(const std::string& _text, Node* _node, LabelType _type = LABEL_CENTER, float _margin = 0.0f);
void addLabel(const std::string& _text, Model* _node, LabelType _type = LABEL_CENTER, float _margin = 0.0f);
void addLabel(std::function<std::string(void)> _func, glm::vec3* _position, LabelType _type = LABEL_CENTER, float _margin = 0.0f);
void addLabel(std::function<std::string(void)> _func, Node* _node, LabelType _type = LABEL_CENTER, float _margin = 0.0f);
void addLabel(std::function<std::string(void)> _func, Model* _model, LabelType _type = LABEL_CENTER, float _margin = 0.0f);
void labels();
int labelAt(float _x, float _y);
Label* label(size_t _index);

};
