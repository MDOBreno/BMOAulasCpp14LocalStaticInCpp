//
//  main.cpp
//  BMOAulasCpp14LocalStaticInCpp
//
//  Created by Breno Medeiros on 06/06/21.
//

#include <iostream>


// Conclusoes principais dessa aula:
// 1) LocalStatic: É um atributo/metodo estatico que so pode ser usado em seu escopo de criacao,
//    porem o seu tempo de vida pode se estender para durante o tempoDeVida(LifeTime)  do
//    Programa inteiro.



int k=0; //Obs: Nas linhas abaixo declararemos 'i' e 'j', da no mesmo que declarar aqui fora como 'k'

//Funcao criada no escopo do arquivo main.cpp:
void Funcao() {
    static int i=0; // Atributo LocalStatic.
    // Obs: Veja q msm chamando varias vezes a linha acima, atribuir o valor 0 so ocorre na primeira vez
    i++;
    
    int j=0;        // Atributo comum
    j++;
    
    k++;
    
    std::cout << "i=" << i << " e " << "j=" << j << " e " << "k=" << k << std::endl;
}



class FilhoUnico{ //Um uso de LocalStatic é criar um atributo que somente seja criado uma vez na classe
private:
public:
    static FilhoUnico Get() { // Como este metodo é estatico, e a variavel abaixo tambem, seu LifeTime é infinito :D
        static FilhoUnico sInstancia /* =algo */; //Nessa linha o valor atribuido aqui nunca mais sera mudado
        return sInstancia;
    }
    void FazAlgumaCoisa() {
        //Faz alguma coisa
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    
    //A diferenca entre os Atributos "LocalStatic" e "comum":
    Funcao();
    Funcao();
    Funcao();
    Funcao();
    Funcao();
    
    
    FilhoUnico::Get().FazAlgumaCoisa();
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
