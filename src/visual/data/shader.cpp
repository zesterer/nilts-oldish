//----STANDARD----
#include "stdio.h"
#include "fstream"
#include "vector"
#include "string"

//----LIBRARY----
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"

//----LOCAL----
#include "shader.h"
#include "common/io.h"

using namespace std;
using namespace gl;

namespace Nilts
{
	namespace Visual
	{
		namespace Data
		{
			void Shader::loadFromFiles(string vertex_file_path, string fragment_file_path)
			{
				// Read the Vertex Shader code from the file
				IO::output("Loading Vertex Shader Code from:" + vertex_file_path);
				string VertexShaderCode;
				ifstream VertexShaderStream(vertex_file_path.c_str(), ios::in);
				if(VertexShaderStream.is_open())
				{
					string Line = "";
					while(getline(VertexShaderStream, Line))
						VertexShaderCode += Line + "\n";
					VertexShaderStream.close();
				}

				// Read the Fragment Shader code from the file
				IO::output("Loading Fragment Shader Code from: " + fragment_file_path);
				string FragmentShaderCode;
				ifstream FragmentShaderStream(fragment_file_path.c_str(), ios::in);
				if(FragmentShaderStream.is_open())
				{
					string Line = "";
					while(getline(FragmentShaderStream, Line))
						FragmentShaderCode += Line + "\n";
					FragmentShaderStream.close();
				}

				this->loadFromStrings(VertexShaderCode, FragmentShaderCode);
			}

			void Shader::loadFromStrings(string VertexShaderCode, string FragmentShaderCode)
			{
				// Create the shaders
				GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
				GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

				GLint Result = 0;//GL_FALSE;
				int InfoLogLength;

				// Compile Vertex Shader
				IO::output("Compiling Vertex Shader");
				char const * VertexSourcePointer = VertexShaderCode.c_str();
				glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
				glCompileShader(VertexShaderID);

				// Check Vertex Shader
				glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
				glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
				vector<char> VertexShaderErrorMessage(InfoLogLength);
				glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
				fprintf(stdout, "%s", &VertexShaderErrorMessage[0]);

				// Compile Fragment Shader
				IO::output("Compiling Fragment Shader");
				char const * FragmentSourcePointer = FragmentShaderCode.c_str();
				glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
				glCompileShader(FragmentShaderID);

				// Check Fragment Shader
				glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
				glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
				vector<char> FragmentShaderErrorMessage(InfoLogLength);
				glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
				fprintf(stdout, "%s", &FragmentShaderErrorMessage[0]);

				// Link the program
				IO::output("Linking program");
				GLuint ProgramID = glCreateProgram();
				glAttachShader(ProgramID, VertexShaderID);
				glAttachShader(ProgramID, FragmentShaderID);
				glLinkProgram(ProgramID);

				// Check the program
				glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
				glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
				vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
				glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
				fprintf(stdout, "%s", &ProgramErrorMessage[0]);

				//Delete the individual shaders (they're now packaged as part of a shader 'program')
				glDeleteShader(VertexShaderID);
				glDeleteShader(FragmentShaderID);

				this->gl_id = ProgramID;
			}

			void Shader::enable()
			{
				glUseProgram(this->gl_id);
			}
		}
	}
}
