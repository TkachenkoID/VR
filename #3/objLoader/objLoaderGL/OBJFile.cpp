#include "OBJFile.h"

void OBJFile::apply_scaling(int* indices, int size) {
	for (int i = 0; i < size; i++) {
		indices[i] = indices[i] * scalingFactor;
	}
}

int OBJFile::count_char(string& str, char ch) {
	int c = 0;
	int length = str.length() - 1;
	for (int i = 0; i < length; i++) {
		if (str[i] == ch)
			c++;
	}
	return c;
}

bool OBJFile::has_double_slash(string& str) {
	int length = str.length() - 2;
	for (int i = 0; i < length; i++) {
		if (str[i] == '/' && str[i + 1] == '/')
			return true;
	}
	return false;
}

void OBJFile::face_3v(std::string& line) {
	int v0, v1, v2;
	sscanf_s(line.c_str(), "f %d %d %d", &v0, &v1, &v2);
	int* v = new int[3]{ v0 - 1, v1 - 1, v2 - 1 };
	apply_scaling(v, 3);
	faces.push_back(Faces(3, v, NULL));
}

void OBJFile::face_3vt(std::string& line) {
	int v0, v1, v2, t0, t1, t2;
	sscanf_s(line.c_str(), "f %d/%d %d/%d %d/%d", &v0, &t0, &v1, &t1, &v2, &t2);
	int* v = new int[3]{ v0 - 1, v1 - 1, v2 - 1 };
	int* t = new int[3]{ t0 - 1, t1 - 1, t2 - 1 };
	apply_scaling(v, 3);
	apply_scaling(t, 3);
	faces.push_back(Faces(3, v, NULL));
}

void OBJFile::face_3vn(std::string& line) {
	int v0, v1, v2, n;
	sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d", &v0, &n, &v1, &n, &v2, &n);
	int* v = new int[3]{ v0 - 1, v1 - 1, v2 - 1 };
	apply_scaling(v, 3);
	faces.push_back(Faces(3, v, n - 1));
}

void OBJFile::face_3vtn(std::string& line) {
	int v0, v1, v2, t0, t1, t2, n;
	sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v0, &t0, &n, &v1, &t1, &n, &v2, &t2, &n);
	int* v = new int[3]{ v0 - 1, v1 - 1, v2 - 1 };
	int* t = new int[3]{ t0 - 1, t1 - 1, t2 - 1 };
	apply_scaling(v, 3);
	apply_scaling(t, 3);
	faces.push_back(Faces(3, v, n - 1));
}

void OBJFile::face_4v(std::string& line) {
	int v0, v1, v2, v3;
	sscanf_s(line.c_str(), "f %d %d %d %d", &v0, &v1, &v2, &v3);
	int* v = new int[4]{ v0 - 1, v1 - 1, v2 - 1, v3 - 1 };
	apply_scaling(v, 4);
	faces.push_back(Faces(4, v, NULL));
}

void OBJFile::face_4vt(std::string& line) {
	int v0, v1, v2, v3, t0, t1, t2, t3;
	sscanf_s(line.c_str(), "f %d/%d %d/%d %d/%d %d/%d", &v0, &t0, &v1, &t1, &v2, &t2, &v3, &t3);
	int* v = new int[4]{ v0 - 1, v1 - 1, v2 - 1, v3 - 1 };
	int* t = new int[4]{ t0 - 1, t1 - 1, t2 - 1, t3 - 1 };
	apply_scaling(v, 4);
	apply_scaling(t, 4);
	faces.push_back(Faces(4, v, NULL));
}

void OBJFile::face_4vn(std::string& line) {
	int v0, v1, v2, v3, n;
	sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d %d//%d", &v0, &n, &v1, &n, &v2, &n, &v3, &n);
	int* v = new int[4]{ v0 - 1, v1 - 1, v2 - 1, v3 - 1 };
	apply_scaling(v, 4);
	faces.push_back(Faces(4, v, n - 1));
}

void OBJFile::face_4vtn(std::string& line) {
	int v0, v1, v2, v3, t0, t1, t2, t3, n;
	sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &v0, &t0, &n, &v1, &t1, &n, &v2, &t2, &n, &v3,
		&t3, &n);
	int* v = new int[4]{ v0 - 1, v1 - 1, v2 - 1, v3 - 1 };
	int* t = new int[4]{ t0 - 1, t1 - 1, t2 - 1, t3 - 1 };
	apply_scaling(v, 4);
	apply_scaling(t, 4);
	faces.push_back(Faces(4, v, n - 1));
}

