#include "OBJFile.h"

void OBJFile::loadOBJFile(string filename) {

	vector<string> lines;
	string line;
	ifstream iFile(filename);

	if (!iFile) {
		cout << "error load file - > " << filename << endl;
		exit(-1);
	}

	while (!iFile.eof()) {
		getline(iFile, line);
		lines.push_back(line);
	}
	iFile.close();

	float x, y, z;

	for (auto& line : lines) {
		if (line[0] == 'v') {
			if (line[1] == ' ') {
				sscanf_s(line.c_str(), "v %f %f %f", &x, &y, &z);
				verticies.push_back(new float[3]{ x, y, z });
			}
			else if (line[1] == 'n') {
				sscanf_s(line.c_str(), "vn %f %f %f", &x, &y, &z);
				normals.push_back(new float[3]{ x, y, z });
			}
		}
		else if (line[0] == 'f') {
			if (line[1] == ' ') {
				int edge = count_char(line, ' ');
				int count_slash = count_char(line, '/');
				if (count_slash == 0) {
					if (edge == 3)
						face_3v(line);
					else
						face_4v(line);
				}
				else if (count_slash == edge) {
					if (edge == 3)
						face_3vt(line);
					else
						face_4vt(line);
				}
				else if (count_slash == edge * 2) {
					if (has_double_slash(line)) {
						if (edge == 3)
							face_3vn(line);
						else
							face_4vn(line);
					}
					else {
						if (edge == 3)
							face_3vtn(line);
						else
							face_4vtn(line);
					}
				}
			}
		}
	}

	list = glGenLists(1);
	glNewList(list, GL_COMPILE);
	for (Faces& face : faces) {
		if (face.normals != -1)
			glNormal3fv(normals[face.normals]);
		else
			glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		for (int i = 0; i < face.edge; i++) {
			glVertex3fv(verticies[face.verticies[i]]);
		}
		glEnd();

		if (face.normals == -1)
			glEnable(GL_LIGHTING);
	}

	glEndList();
	cout << "Model : " << filename << endl;
	cout << "Verticies : " << verticies.size() << endl;
	cout << "Normals : " << normals.size() << endl;
	cout << "Faces : " << faces.size() << endl;

	for (float* f : verticies)
		delete f;
	verticies.clear();

	for (float* f : normals)
		delete f;
	normals.clear();
	faces.clear();
}