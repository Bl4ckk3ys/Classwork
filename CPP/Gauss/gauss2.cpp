#include <iostream>

int main(){

    int N;
    std::cout << "Введите N: ";
    std::cin >> N; 
    std::cout << std::endl;
    double arr[N][N],b[N];
    int index[N];
    
    for(int i = 0; i<N ; i++){
        index[i] = i;
        for(int j = 0; j<N; j++){
            std::cout << "Введите элемент arr[" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
            std::cout << std::endl;
        }
        std::cout << "Введите элемент b[" << i << "]: ";
            std::cin >> b[i];
            std::cout << std::endl;
    }

bool flag = false;
    for(int i = 0; i<N; i++){
        if (arr[i][i]==0){
            for (int c = i; c<N; c++){
                if(arr[c][i]!=0){
                    flag = true;
                    index[c] = i;
                    index[i] = c;
                    int tmp = b[i];
                    b[i] = b[c];
                    b[c] = tmp;
                    for(int j = 0; j<N; j++){
                        tmp = arr[c][j];
                        arr[c][j] = arr[i][j];
                        arr[i][j]= tmp;
                    }
                    break;
                }
            }
            if (flag) flag = false; break;
            std::cout<<"Система не имеет решений"<< std::endl;
        } 
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            arr[i][j]/=arr[i][i];
            }
        b[i]/=arr[i][i];
    }

   
    for (int i = 0; i<N; i++){
         for (int k = i+1; k < N; k++){
            double R = arr[k][i];
            for (int j = 0; j < N; j++){
                arr[k][j] -= arr[i][j]*R;
            }
            b[k] -= b[i]*R;
        } 
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            std::cout << " arr[" << i << "][" << j << "]: "<<arr[i][j];
        }
        std::cout<< " = "<<b[i]<<std::endl;
    }
}