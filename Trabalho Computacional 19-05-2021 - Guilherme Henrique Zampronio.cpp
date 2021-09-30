#include <iostream>
#include <cmath>
#include <vector>
#include <locale>
#include <stdexcept>


using namespace std;

//void ImprimeTabela(vector<double>& vetorx, vector<double>& vetorfx);
void DerivadaDoisPontos(vector<double>& vetorx, vector<double>& vetorfx, double point);
void DerivadaTresPontos(vector<double>& vetorx, vector<double>& vetorfx, double point);

int main(){
	setlocale(LC_ALL, "portuguese");
	bool repeat, choosepoint;
	repeat = true;
	choosepoint = true;
	double x, fx, point;
	vector<double> vetorx;
	vector<double> vetorfx;
	
	while(repeat == true){
		cout << "Digite o ponto x e o seu respectivo f(x)" << endl; 
		cin >> x;
		cin >> fx;
		vetorx.push_back(x);
		vetorfx.push_back(fx);
		
		
		cout << "Deseja continuar inserindos os pontos? ( 0 - N�o ) ( 1 - Sim )" << endl;
		try{
			cin >> repeat;
		}
		catch(exception& e){
			cout << "Escolha 0 ou 1!" << e.what() << endl;
		}
	}

	
	while(choosepoint == true){
		cout << "Qual o ponto para determinarmos a derivada primeira?" << endl;
		cin >> point;

		DerivadaDoisPontos(vetorx, vetorfx, point);
		DerivadaTresPontos(vetorx, vetorfx, point);
		
		cout << "Deseja tentar determinar a derivada primeira com outro ponto? ( 0 - N�o ) ( 1 - Sim )" << endl;
		cin >> choosepoint;
	}
	
	return 0;
}



void DerivadaDoisPontos(vector<double>& vetorx, vector<double>& vetorfx, double point){
	int pointindex;
	bool central, progressiva, regressiva;
	
	for(pointindex = 0; pointindex < vetorx.size(); pointindex++){
		if(point == vetorx[pointindex]){
			break;
		}
	}
	
	if(point == vetorx.back()){
		progressiva = false;
		cout << "Desculpe n�o foi poss�vel fazer a diferen�a progressiva com dois pontos com esse ponto" << endl;
	}else{
		double DiferencaProgressiva;
		progressiva = true;
		DiferencaProgressiva = ( vetorfx[pointindex + 1] - vetorfx[pointindex] ) / ( vetorx[pointindex + 1] - vetorx[pointindex] );
		cout << "Diferen�a Progressiva de dois pontos : " << DiferencaProgressiva << endl;	
	}
	
	if(point == vetorx.front()){
		regressiva = false;
		cout << "Desculpe n�o foi poss�vel fazer a diferen�a regressiva com dois pontos com esse ponto" << endl;
	}else{
		double DiferencaRegressiva;
		regressiva = true;
		DiferencaRegressiva = ( vetorfx[pointindex] - vetorfx[pointindex - 1] ) / ( vetorx[pointindex] - vetorx[pointindex - 1] );
		cout << "Diferen�a Regressiva de dois pontos: " << DiferencaRegressiva << endl;
	}
	
	if(point == vetorx.front() || point == vetorx.back() ){
		central = false;
		cout << "Desculpe n�o temos pontos suficientes para fazer a diferen�a central com dois pontos" << endl;
	}else{
		double DiferencaCentral;
		central = true;
		DiferencaCentral = ( vetorfx[pointindex + 1] - vetorfx[pointindex - 1] ) / ( vetorx[pointindex + 1] - vetorx[pointindex - 1]);
		cout << "Diferen�a Central: " << DiferencaCentral << endl;
	}	
		
}

void DerivadaTresPontos(vector<double>& vetorx, vector<double>& vetorfx, double point){
	int pointindex;
	bool central, progressiva, regressiva;
	double h;
	
	for(pointindex = 0; pointindex < vetorx.size(); pointindex++){
		if(point == vetorx[pointindex]){
			break;
		}
	}
	
	h = vetorx[pointindex + 1] - vetorx[pointindex];
	
	if(point == vetorx.back() || pointindex + 1 == vetorx.size() - 1){
		progressiva = false;
		cout << "Desculpe n�o foi poss�vel fazer a diferen�a progressiva de tr�s pontos com esse ponto" << endl;
	}else{
		double DiferencaProgressiva;
		progressiva = true;
		DiferencaProgressiva = ( -3 * vetorfx[pointindex] + 4 * vetorfx[pointindex + 1] - vetorfx[pointindex + 2] ) / (2 * h);  
		cout << "Diferen�a Progressiva de tr�s pontos: " << DiferencaProgressiva << endl;	
	}
	
	if(point == vetorx.front() || pointindex == 1){
		regressiva = false;
		cout << "Desculpe n�o foi poss�vel fazer a diferen�a regressiva de tr�s pontos com esse ponto" << endl;
	}else{
		double DiferencaRegressiva;
		regressiva = true;
		DiferencaRegressiva = ( vetorfx[pointindex - 2] - 4 * vetorfx[pointindex - 1] + 3 * vetorfx[pointindex] ) / (2 * h);
		cout << "Diferen�a Regressiva de tr�s pontos: " << DiferencaRegressiva << endl;
	}	
	
}


