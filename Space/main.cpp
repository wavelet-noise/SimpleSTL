#include <memory>
#include "Game.h"
#include <stdio.h>
#include <iostream>
#include "..\Engine\Icosahedron.h"

int help(){
	std::cout<<"NAME"<<std::endl;
	std::cout<<"		SipmleSTL -- simple 3d editor with stl export"<<std::endl;
	std::cout<<"SYNOPSIS"<<std::endl;
	std::cout<<"		simplestl -obj modelname [-s filename.stl]"<<std::endl;
	std::cout<<"		simplestl -stl modelname [-s filename.stl]"<<std::endl;
	std::cout<<"		simplestl -g [cube, icosohydron, quad] [-s [filename]] [-m]"<<std::endl;
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc >= 2){
		if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "-?") || !strcmp(argv[1], "?") || !strcmp(argv[1], "help") || !strcmp(argv[1], "-help") || !strcmp(argv[1], "h")){
			help();
			return 0;
		}
		Game* game = new Game();
		game->Initialize();
		if(argc >= 3 && !strcmp(argv[1], "-g")){
			if(!strcmp(argv[2], "cube")){
				game->model = new Mesh(Icosahedron::getMesh());
				game->model->UnIndex();
				game->model->RecalcNormals();
				if(argc >= 5 && !strcmp(argv[3], "-s")){
					game->model->saveSTL(argv[4]);
				}
			}
		}
		if(argc >= 3 && !strcmp(argv[1], "-obj")){
			game->model = new Mesh();
			game->model->loadOBJ(argv[2]);
			game->model->UnIndex();
			game->model->RecalcNormals();
			if(argc >= 5 && !strcmp(argv[3], "-s")){
				game->model->saveSTL(argv[4]);
			}
		}
		game->Run();
		delete game->model;
		delete game;
	} else {
		help();
		return 0;
	}
	
	return 0;
}