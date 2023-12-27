#pragma once
#include <fstream>
#include <math.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <GL/freeglut.h>

#define GL_MULTISAMPLE                    0x809D
#define GL_MULTISAMPLE_FILTER_HINT_NV     0x8534
#define WIDTH 1280
#define HEIGTH 720


using namespace std;

class OBJFile {
private:
	class Faces {
	public:
		int edge;
		int* verticies;
		int normals;
		Faces(int edge, int* verticies, int normals) {
			this->edge = edge;
			this->verticies = verticies;
			this->normals = normals;
		}
	};

	vector<float*> verticies;
	vector<float*> normals;
	vector<Faces> faces;
	unsigned int list;

public:
	//проверка строки для последующего определения типа
	static int count_char(string& str, char ch);
	static bool has_double_slash(string& str);

	float scalingFactor = 1; // Set your desired scaling factor here

	void apply_scaling(int* indices, int size);

	//функции для чтения разных типов f v/t/n && f v//n && f v и тд
	void face_3v(string& line);
	void face_3vt(string& line);
	void face_3vn(string& line);
	void face_3vtn(string& line);
	void face_4v(string& line);
	void face_4vt(string& line);
	void face_4vn(string& line);
	void face_4vtn(string& line);

	//загрузка и обработка данных из файла obj
	void loadOBJFile(string filename);

	//отрисовка
	void draw();
};