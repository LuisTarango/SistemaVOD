#include <iostream>
#include <string>
#include "movieReport.hpp"
#include "seriesReport.hpp"


using namespace std;

int main(){
    //Variables para main
    movieReport mov;
    seriesReport ser;
    bool menuVal=true;  //Para continuar ciclo de menu
    bool loadedM=false; //Revisar si se cargo Archivo de Peliculas
    bool loadedS=false; //Revisar si se cargo Archivo de Series
    int menuOp;

    //Variables para Peliculas y Series
    int id;
    string title;
    int duration;
    string genre;
    double rating;
    int oscars;
    int lfRating;
    string lfGenre;
    int lfId;
    int lfSeasons;


    while (menuVal==true){//El menu seguira corriendo hasta que se detenga en caso 0
        cout<<"====================Menu====================\n\n";
        cout<<"===================Movies===================\n";
        cout<<"1.- Load From File\n";
        cout<<"2.- Add new Movie\n";
        cout<<"3.- Movie Report\n";
        cout<<"4.- Movie Report by Rating\n";
        cout<<"5.- Movie Report by Genre\n";
        cout<<"6.- Change a Movie's Oscars\n\n";
        cout<<"===================Series===================\n";
        cout<<"7.- Load Series from file\n";
        cout<<"8.- Series Report\n";
        cout<<"9.- Series Report by Rating\n";
        cout<<"10.- Series Report by Genre\n";
        cout<<"11.- Add an Episode to Series\n";
        cout<<"12.- Average Episode Rating \n\n";
        cout<<"==================Episodes==================\n";
        cout<<"13.- Episode Report\n";
        cout<<"14.- Episode Report by Rating\n\n";
        cout<<"0.-Exit"<<endl;
        cin>>menuOp;
        switch(menuOp){
            case 1:
                if (loadedM==false){//Verificar que solo se carguen una vez
                    mov.loadMovies();
                    loadedM=true;
                    system("pause");
                    break;}
                    cout<<"Files already Loaded\n";
                    system("pause");
                    break;
            case 2://Agregar nueva pelicula a Lista Y archivo csv
            if (loadedM==false){//Verificar que ya se cargaron Peliculas
                cout<<"Please load files before continuing\n";
                system("pause");
                break;
                }
                cout<<"Please enter the ID of the new movie\n";
                cin>>id;
                cout<<"Please enter the Title of the new movie\n";
                cin.ignore();
                getline(cin,title);
                cout<<"Please enter the Duration of the new movie\n";
                cin>>duration;
                cout<<"Please enter the Genre of the new movie\n";
                cin.ignore();
                getline(cin,genre);
                cout<<"Please enter the Rating of the new movie\n";
                cin>>rating;
                cout<<"Please enter the number of Academy Awards won by the new movie\n";
                cin>>oscars;

                mov.addNew(id,title,duration,genre,rating,oscars);
                system("pause");
                break;
            case 3://Mostrar TODAS las peliculas
                if (loadedM==false){//Verificar que ya se cargaron Peliculas
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                mov.dispMovies();
                system("pause");
                break;

            case 4://Mostrar peliculas por calificacion
                if (loadedM==false){//Verificar que ya se cargaron Peliculas
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                cout<<"Please enter the Rating (Integer from 1 to 5), of the movies you want to be displayed\n";
                cin>>lfRating;
                if (lfRating==1 || lfRating==2 || lfRating==3 || lfRating==4 || lfRating==5 ){
                    cout<<"Displaying movies with rating of "<<lfRating<<":\n";
                    mov.dispRating(lfRating);//Tambien calcula el RATING real, redondeando y sumando un punto si la peliculas tiene oscares.
                    system("pause");
                    break;
                }
                cout<<"Invalid Rating\n";
                system("pause");
                break;

            case 5://Mostrar peliculas por genero
                if (loadedM==false){//Verificar que ya se cargaron Peliculas
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                cout<<"Please enter the Genre of the movies you want to be displayed\n";
                cin.ignore();
                getline(cin,lfGenre);
                cout<<"Displaying "<<lfGenre<<" movies:\n";
                mov.dispGenre(lfGenre);
                system("pause");
                break;
            case 6://Cambia el numero de oscares de una pelicula (solo lista no archivo)
                if (loadedM==false){//Verificar que ya se cargaron Peliculas
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                cout<<"Enter Movie ID\n";cin>>lfId;
                cout<<"Enter new number of Oscars\n";cin>>oscars;
                mov.changeOscars(lfId,oscars);
                system("pause");
                break;
            case 7://Caragr archivo de peliculas
                if (loadedS==false){//Verificar que solo se carguen una vez
                    ser.loadSeries();
                    loadedS=true;
                    system("pause");
                    break;}
                    cout<<"Files already Loaded\n";
                    system("pause");
                    break;
            case 8://Mostrar TODAS las series
                if (loadedS==false){//Verificar que ya se cargaron Series
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                ser.dispSeries();
                system("pause");
                break;
            case 9://Mostrar series con cierta calificacion
                if (loadedS==false){//Verificar que ya se cargaron Series
                        cout<<"Please load files before continuing\n";
                        system("pause");
                        break;
                    }
                    cout<<"Please enter the Rating (Integer from 1 to 5), of the series you want to be displayed\n";
                    cin>>lfRating;
                    if (lfRating==1 || lfRating==2 || lfRating==3 || lfRating==4 || lfRating==5 ){
                        cout<<"Displaying series with rating of "<<lfRating<<":\n";
                        ser.dispRating(lfRating);
                        system("pause");
                        break;
                    }
                    cout<<"Invalid Rating\n";
                    system("pause");
                    break;
            case 10://Mostrar series de cierto Genere
                if (loadedS==false){//Verificar que ya se cargaron Series
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                cout<<"Please enter the Genre of the series you want to be displayed\n";
                cin.ignore();
                getline(cin,lfGenre);
                cout<<"Displaying "<<lfGenre<<" series:\n";
                ser.dispGenre(lfGenre);
                system("pause");
                break;
            case 11://Agregar nuevo Episodio a Serio
                if (loadedS==false){//Verificar que ya se cargaron Series
                    cout<<"Please load files before continuing\n";
                    system("pause");
                    break;
                }
                cout<<"Enter ID"<<endl;cin>>id;
                ser.addEpisode(id);
                cout<<"Episode Added\n";
                system("pause");
                break;
            case 12://Calcular promedio de calificaicon en base a calificacion de episodios
                if (loadedS==false){//Verificar que ya se cargaron Series
                        cout<<"Please load files before continuing\n";
                        system("pause");
                        break;
                    }
                ser.avgRating();
                system("pause");
                break;
            case 13://Mostrar todos los episodios de una serie
                if (loadedS==false){//Verificar que ya se cargaron Series
                        cout<<"Please load files before continuing\n";
                        system("pause");
                        break;
                    }
                    cout<<"Enter series ID\n";cin>>id;
                    ser.dispEpisodes(id);
                    
                system("pause");
                break;
            case 14://Mostrar los episodios con cierta calificacion de una serie
                if (loadedS==false){//Verificar que ya se cargaron Series
                        cout<<"Please load files before continuing\n";
                        system("pause");
                        break;
                    }
                cout<<"Enter de ID of the Series\n";cin>>lfId;
                cout<<"Please enter the Rating (Integer from 1 to 5), of the Episodes you want to be displayed\n";
                    cin>>lfRating;
                    if (lfRating==1 || lfRating==2 || lfRating==3 || lfRating==4 || lfRating==5 ){
                        cout<<"Displaying episodes with rating of "<<lfRating<<":\n";
                        ser.printEpisodesByRating(lfId,lfRating);
                        system("pause");
                        break;
                    }
                cout<<"Invalid Rating\n";;
                system("pause");
                break;
            case 0://Cerrar el programa
                cout<<"Exiting..."<<endl;
                menuVal=false;
                break;
            default:// Si se ingresa otra opcion
                cout<<"Invalid: Please enter valid option\n";
                system("pause");
                break;
        }
    }
    return 0;
}

