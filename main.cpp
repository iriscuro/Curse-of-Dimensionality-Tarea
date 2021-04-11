#include <iostream>

#include <random>
///Medir tiempo:
#include <iomanip>
#include <chrono>
using namespace std;

///Generar double aleatorio:

int main()
{
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(1.0, 2.0);
//    for (int n = 0; n < 10; ++n) {
//        // Use dis to transform the random unsigned int generated by gen into a
//        // double in [1, 2). Each call to dis(gen) generates a new random double
//        std::cout << dis(gen) << ' ';
//    }
//    cout << '\n \n';
    int num_d = 10;
    int can_o = 10000;
    float obj[can_o][num_d]={0};
    float mat_i[can_o][can_o]={0}; //matriz de incidencia

    ///MATRIZ DE NUMEROS ALEATORIOS
    for( int i=0;i<can_o;i++){
        for(int j=0;j<num_d;j++){
            obj[i][j] = dis(gen);
        }
    }
    cout<<endl;

    ///MATRIZ DE DISTANCIA
    ///Medir tiempo:

    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();

    float resp;
    float sum=0;
    int id;
   // for(int x=0;x<can_o;x++){
        for(int j=0;j<can_o-1;j++){
            for(int i=j+1;i<can_o;i++){
                    sum=0;
                    for(int n=0;n<num_d;n++){
                        sum += pow(obj[j][n]- obj[i][n],2 );

                    }
                    resp = sqrt(sum);

                    mat_i[i][j] = resp;
                    resp = 0;

            }
          //  mat_i[j][j] = 0;

        }
  //  }
    end = chrono::high_resolution_clock::now();

    int64_t duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time.

    cout<<"time: "<< duration<<"\n";



    ///CONTENIDO DE MAT_I
//     for(int a=0;a<can_o;a++){
//        for(int b=0;b< can_o;b++){
//            cout<< mat_i[a][b]<< " ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    ///CONTENIDO DE OBJ
//    for(int a=0;a<can_o;a++){
//        for(int b=0;b< num_d;b++){
//            cout<< obj[a][b]<< " ";
//        }
//        cout<<endl;
//    }


}

