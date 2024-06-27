
#include <iostream>
#include <thread> //execução simultânea de múltiplas tarefas
#include <chrono> //manipulação de tempo
#include <string> //manipulação de cadeias de caracteres 
#include <vector> //armazenar elementos de qualquer tipo.
#include <fstream> //arquvos


#ifdef _WIN32
    #include <windows.h> //windows 
#endif

void limpa_tela(){
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

using namespace std;

class jogo {
    public:
    int esperanca = 10;

void inicio()
{   
    while (true) {
    int a;
    cout << "Bem vindo!!\n\n1.Iniciar jogo\n2.Creditos\n3.Salvos\n4.Sair\n"<< endl;
    cin >> a;
    limpa_tela();

    if( a == 1){
        iniciar();
    }
    else if(a == 2){
        mostrarCreditos();
    }else if(a == 3){
        carregarProgresso();
        cout<<"\n";
        system("pause");
        limpa_tela();
    }else if(a == 4){
        cout <<"saindo....."<< endl;
    }
}
}

void print_texto(const string& texto) { // referencia  . não pode modificar a string 
    string palavra; 
    for (char c : texto){ // percorre cada caractere
        if(c != ' ' && c != '\n'){ //adicionado à string palavra
            palavra += c;
        }else {
            cout << palavra << " "; //Processamento de Palavras
            cout.flush(); //força a saída imediata do texto
            palavra.clear();
            this_thread::sleep_for(chrono::milliseconds(100));
            if(c == '\n'){
                cout << endl;
            }
        }
    }
    cout << palavra << endl;
}

void print_story() 
{   //Definição de um Array de Strings
    const char* story[] = {
        "=-=-=-=-=- ______     ______     ______   ______   ______   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=",
        "=-=-=-=-=-/\\  ___\\   /\\  __ \\   /\\  ___\\ /\\  ___\\ /\\  ___\\  =-=-=-=-=-=-=-=-=-",
        "=-=-=-=-=-\\ \\ \\____  \\ \\ \\/\\ \\  \\ \\  __\\ \\ \\  __\\ \\ \\  __\\  =-=-=-=-=-=-=",
        "=-=-=-=-=- \\ \\_____\\  \\ \\_____\\  \\ \\_\\    \\ \\_\\    \\ \\_____\\ =-=-=-=-=-=-",
        "=-=-=-=-=-  \\/_____/   \\/_____/   \\/_/     \\/_/     \\/_____/   =-=-=-=-=-=-=-=-=\n",
        "=-=-=-=-=-                                                           -=-=-=-=-=-=-=-=\n"
        "=-=-=-=-=-  __         ______     __   __   ______                     -=-=-=-=-=-=-=- ",
        "=-=-=-=-=- /\\ \\       /\\  __ \\   /\\ \\ / /  /\\  ___\\           =-==-=--=-==-=-=-",
        "-=-=-=-=-= \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\'/   \\ \\  __\\  -=-=-==-=-=-=-=-=-=-=",
        "-=-=-=-=-=  \\ \\_____\\  \\ \\_____\\  \\ \\__|    \\ \\_____\\ -=-=-=-=-=-=-=-=-=-=-=-",
        "=-=-=-=-=-   \\/_____/   \\/_____/   \\/_/      \\/_____/ --=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n",
        "                                   <enter>                                       \n"
    };

    for (const char* line : story) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cin.get();
    limpa_tela();
    inicio();
}

void texto_hist()
{
    const string texto = "Em uma pequena cozinha, onde os aromas se misturam com sussurros, vivia Cafe,\num jovem de aroma envolvente que escondia um fardo invisivel por tras de sua\nfragrancia encantadora. Ele foi tocado por um amor intenso com Pao, cuja presenca tornava\na cozinha um lugar acolhedor e iluminado. Juntos, compartilharam risos e lagrimas, construindo\nreceitas de sonhos sobre alicerces de esperanca. No entanto, o calor do amor se desfez,\ne Pao desapareceu como uma migalha na noite, deixando Cafe perdido em um labirinto\nde perguntas sem respostas. Seu coracao, outrora inteiro, tornou-se um quebra-cabeca de pedacos\nperdidos. Vagando pela cozinha, tentando decifrar os enigmas do destino, Cafe\nse afogava em lembrancas. Ainda assim, ele continuava sua jornada, carregando o peso de um amor nao\ncorrespondido, guardando memorias em um cofre de emocoes. Sua vida tornou-se\numa danca entre a luz e a escuridao, equilibrando dor e esperanca, com a melodia suave de\numa historia de amor que nunca chegou ao seu desfecho, ecoando eternamente na alma.\n\n";
    print_texto(texto);
    system("pause");
    limpa_tela();

}

void print2()
{
    const char* story[] = {
    "=-=-=-=-=-=-=-    ____        =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=-   /    \\       =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=-   |----|       =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=-  /      \\      =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- |  . . . |>    =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- |  . . . |  \\  =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- |  . . . |   } =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- |  , , , |  /  =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- |  , , , |>    =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- |        |     =-=-=-=-=-=-=-",
    "=-=-=-=-=-=-=- \\________/     =-=-=-=-=-=-=-" 
    };

    for (const char* line : story){
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cin.get();
    limpa_tela();
}
void iniciar() 
{
    texto_hist();
    print2();
    escolha();
}

void texto_hist2()
{
    const string texto = "-Cha: Cafe, faz tempo que nao te vejo perfumando a cozinha com alegria. O que aconteceu com aquele brilho no seu aroma?\n";
    print_texto(texto);
}

void escolha(){
    cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
    cin.get();
    limpa_tela();

    while (true) {
    cout << "Cafe encontra um velho amigo, Cha, na prateleira da cozinha.<Enter>\n\n";
    cin.get();
    texto_hist2();
    cout << "1.Pao se foi e levou consigo a minha alegria. Nao sei se algum dia conseguirei superar isso.\n"
         << "2.As vezes, sinto que ele nunca me amou de verdade. Talvez eu tenha sido apenas uma companhia temporaria.\n"
         << "3.Estou tentando seguir em frente, mas parece que cada passo que dou me leva de volta ao inicio.\n" << endl;

    int opc;
    cin >> opc;
    limpa_tela();
    if (opc == 1){
    esperanca += 10;
        cout << "+10 pontos (Reconhecer a dor e considerar a mudanca)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena2();
    }else if(opc == 2){
        cout << " -5 pontos (Dúvidas sobre o amor, mas reconhecimento da situacao)";
        esperanca -= 5;
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena2();
    }else if(opc == 3){
        esperanca -= 10;
        cout << "-10 pontos (Sentimento de estagnacao)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena2();
    }
    }   
}

void texto_hist3(){
    const string texto = "- Acucareiro: Cafe, Pao deixou isso para voce. Acho que deveria ler.\n";
    print_texto(texto);
}

void cena2(){
    while (true) {
    cout << "Cafe esta na bancada onde costumava encontrar Pao, quando o acucareiro lhe entrega uma carta deixada por ele.\n\n";
    cin.get();
    texto_hist3();
    cout <<"1.Eu nao sei se quero saber o que ele escreveu. Cada palavra dele pode ser um espinho a mais no meu coracao.\n"
         << "2.Obrigado. Talvez essa carta traga as respostas que procuro, ou talvez apenas mais perguntas.\n"
         << "3.Vou le-la mais tarde. Nao sei se estou pronto para enfrentar o que quer que seja que ele tenha dito.\n" << endl;
    
    int opc2;
    cin >> opc2;
    limpa_tela();

    if(opc2 == 1){
        esperanca -= 5;
        cout << " -5 pontos (Medo da dor emocional)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena3();
    }else if(opc2 == 2){ 
        esperanca += 10;
        cout << "+10 pontos (Busca por respostas e encerramento)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena3();
    }else if(opc2 == 3){
        esperanca -= 5;
        cout << "-5 pontos (Adiar a confrontacao com a realidade)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena3();
    }
}
}

void texto_hist4(){
    const string texto = "- Leite: Cafe, voce precisa parar de viver no passado. Pao se foi e nao ha nada que possamos fazer sobre isso.\n";
    print_texto(texto);
}


void cena3(){
    while (true) {
    cout << "Cafe esta conversando com sua irma mais velha, Leite, sobre o desaparecimento de Pao.\n\n";
    cin.get();
    texto_hist4();
    cout <<  "1.Voce nao entende. Ele era tudo para mim. Como posso simplesmente esquecer?\n"
         <<  "2.Talvez voce tenha razao. Mas cada vez que tento seguir em frente, algo me puxa de volta.\n"
         << "3.Eu nao quero esquecer. Prefiro lembrar dos momentos felizes, mesmo que eles doam.\n" << endl;

    int opc3;
    cin >> opc3;
    limpa_tela();

    if(opc3 == 1){
        esperanca -= 10;
        cout << " -10 pontos (Negacao e desespero)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena4();
    }else if(opc3 == 2){ 
        esperanca += 5;
        cout << "+5 pontos (Aceitacao gradual)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena4();
    }else if(opc3 == 3){
        esperanca -= 5;
        cout << " -5 pontos (Preferencia por dor em vez de mudanca)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena4();
    }
}
}

void texto_hist5(){
    const string texto = "-Cafe (para si mesmo): Quem poderia ter deixado isso aqui? Sera que e alguma mensagem de Pao?\n";
    print_texto(texto);
}
void cena4(){
    while (true) {
    cout << "Cafe encontra um bilhete misterioso na despensa.\n\n";
    cin.get();
    texto_hist5();
    cout <<   "1.Vou abrir agora. Preciso saber se ele ainda pensa em mim.\n"
         <<  "2.Talvez eu devesse esperar. Pode ser apenas outra armadilha para meu coracao.\n"
         <<  "3.E se nao for dele? E se for alguem tentando brincar com meus sentimentos?\n" << endl;

    int opc4;
    cin >> opc4;
    limpa_tela();

    if(opc4 == 1){
        esperanca += 10;
        cout << " +10 pontos (Acao imediata para encontrar respostas)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena5();
    }else if(opc4 == 2){ 
        esperanca -= 5;
        cout << "-5 pontos (Procrastinacao devido ao medo)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena5();
    }else if(opc4 == 3){
        esperanca -= 10;
        cout << "  -10 pontos (Desconfianca e rejeicao)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena5();
    }

}
}

void texto_hist6(){
    const string texto = "- Cafe (para si mesmo): Esses sonhos estao me matando. Por que nao consigo parar de pensar nele?\n";
    print_texto(texto);
}
void cena5(){
    while (true) {
    cout << " Cafe tem um sonho vivido com Pao e acorda perturbado.\n\n";
    cin.get();
    texto_hist6();
    cout <<   "1.Preciso encontrar um jeito de exorcizar esses pensamentos. Talvez conversar com alguém possa ajudar.\n"
         <<  "2.E se esses sonhos forem uma mensagem? Talvez ele esteja tentando se comunicar comigo de alguma forma.\n"
         <<  "3.Talvez nunca deixe de sonhar com ele. Talvez isso seja minha penitência por amá-lo tanto\n" << endl;

    int opc5;
    cin >> opc5;
    limpa_tela();

    if(opc5 == 1){
        esperanca += 10;
        cout << " +10 pontos (Busca de apoio)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena6();
    }else if(opc5 == 2){ 
        esperanca += 5;
        cout << "+5 pontos (Considerar significados mais profundos)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena6();
    }else if(opc5 == 3){
        esperanca -= 5;
        cout << "  -5 pontos (Aceitacao da dor como constante)";
        cout << "\nSua esperanca = "<< esperanca << "\n" << endl;
        system("pause");
        limpa_tela();
        cena6();
    }
} 
}
void cena6(){
    if(esperanca >= 30){
    cout << "       _ _             _       " << endl;
    cout << "      (_) |           (_)      " << endl;
    cout << "__   ___| |_ ___  _ __ _  __ _ " << endl;
    cout << "\\ \\ / / | __/ _ \\| '__| |/ _` |" << endl;
    cout << " \\ V /| | || (_) | |  | | (_| |" << endl;
    cout << "  \\_/ |_|\\__\\___/|_|  |_|\\__,_|" << endl;
    cout << "                               " << endl;
    cout << "                               " << endl;
    cout <<"Cafe ganha, encontrando paz e novos propositos na cozinha.Pontuacao Total: "<< esperanca;
    cout <<"\n\n";
    }
    else{
    cout << "     _                _        " << endl;
    cout << "    | |              | |       " << endl;
    cout << "  __| | ___ _ __ ___ | |_ __ _ " << endl;
    cout << " / _` |/ _ \\ '__/ _ \\| __/ _` |" << endl;
    cout << "| (_| |  __/ | | (_) | || (_| |" << endl;
    cout << " \\__,_|\\___|_|  \\___/ \\__\\__,_|" << endl;
    cout << "                               " << endl;
    cout <<"Cafe perde, permanecendo velho e amargo, preso em sua tristeza e solidao.Pontuacao total: " << esperanca;
    cout <<"\n\n";
    }
    salvarProgresso(esperanca);
    encerrarPrograma();
}

void mostrarCreditos()
 {
    const char* story[] = {
    "-----------------------------------------",
    "              CREDITOS DO JOGO           ",
    "-----------------------------------------" ,
    "Desenvolvido, programado e testado por: Eu mesmo!",
    "-----------------------------------------" ,
    "Um agradecimento especial a:" ,
    "- Meu cafeh, por me manter acordado",
    "- Minha cadeira, por aguentar meu peso",
    "- Meu computador, por n explodir (ainda)",
    "-----------------------------------------",
    "Sobre o jogo:" ,
    "Este jogo foi desenvolvido com muita" ,
    "dedicacao, paciencia e (muitos) lanches.",
    "Espero que você tenha se divertido jogando",
    "tanto quanto eu me diverti criando. E se" ,
    "n, por favor, finja que sim!",
    "-----------------------------------------",
    "Obrigado por jogar! E lembre-se:",
    "Programadores precisam de elogios.",
    "-----------------------------------------"
    };
    
    for (const char* line : story){
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cin.get();
    limpa_tela();
 }
 
 private:
const string arquivoProgresso = "progresso.txt";

void salvarProgresso(int opcao) {
    ofstream arquivo(arquivoProgresso); //escreve
    if (arquivo.is_open()) { //verifica se foi aberto
        arquivo << opcao << endl;
        cout << "Progresso salvo." << endl;
    } else {
        cout << "Nao foi possivel abrir o arquivo para salvar o progresso." << endl;
    }
}

void carregarProgresso() {
    ifstream arquivo(arquivoProgresso); //leitura
    if (arquivo.is_open()) {
        int opcao;
        arquivo >> opcao;
        if (arquivo.good()) { //verifica se foi bem sucedida
            cout << "Ultimo progresso carregado: Pontuacao " << opcao << endl;
        } else {
            cout << "Nenhum progresso salvo encontrado." << endl;
        }
    } else {
        cout << "Nao foi possível abrir o arquivo para carregar o progresso." << endl;
    }
}
    void encerrarPrograma() {
        exit(0); // Encerra o programa com status de sucesso
    }
};


int main()
{
    jogo gerenciador;
    gerenciador.print_story();
    return 0;
}
