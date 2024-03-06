#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

if(std::regex_match(str, regularExpr)){
    return true;
}

  return false;
}

void ContadorPopRural::processaLinha(const std::string &str) {

  std::stringstream ss(str);

  std::string nome_pais;
  unsigned populacao, porcentagem_urbana;
  
  ss >> nome_pais >> populacao >> porcentagem_urbana;
  
  unsigned popRural = floor(populacao - (populacao * (porcentagem_urbana/100.0)));
  
    std::cout << popRural << " pessoas vivem no campo no " << nome_pais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {

  std::regex regularExpr(R"(\b\d+\b(\s+\d+\b)*)");

  if(std::regex_match(str, regularExpr)){
    return true;
  }

  return false;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  
  std::regex regularExpr(R"(\b\d+\b)");
    std::sregex_iterator it(str.begin(), str.end(), regularExpr);
    std::sregex_iterator end;

    int contador = 0;
    while (it != end) {
        std::smatch match = (*it);
        int num = std::stoi(match.str());
        contador += num;
        it++;
    }

    std::cout << contador << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {

  std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
  if(std::regex_match(str, regularExpr)){
    return true;
  }
  return false;

}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  std::string equipe1, equipe2;
  unsigned int gols1, gols2;
  ss >> equipe1 >> gols1 >> equipe2 >> gols2;
  if (gols1 > gols2){
    std::cout << "Vencedor: " << equipe1 << std::endl;
  } else if (gols2 > gols1){
    std::cout << "Vencedor: " << equipe2 << std::endl;
  } else {
    std::cout << "Empate" << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  std::string palavra;
  int contador = 0;
  while (ss >> palavra){
    contador++;
  }
  std::cout << contador << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("^[a-zA-Z\\s*]+$");
  if(std::regex_match(str, regularExpr)){
    return true;
  }
  return false;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  std::vector<std::string> aux;
  std::string palavra;
  while (ss >> palavra){
    aux.push_back(palavra);
  }
  std::string inverso;
  for (auto it = aux.rbegin(); it != aux.rend(); ++it){
    inverso += (*it) + " ";
  }
  std::cout << inverso << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  
  std::regex regularExpr(dateFormat);
  if(std::regex_match(str, regularExpr)){
    return true;
  }
  return false;
}

void EscritorDeDatas::processaLinha(const std::string &str) {
 
  std::stringstream ss(str);
  std::map<int, std::string> meses = {
        {1, "Jan"}, {2, "Fev"}, {3, "Mar"}, {4, "Abr"},
        {5, "Mai"}, {6, "Jun"}, {7, "Jul"}, {8, "Ago"},
        {9, "Set"}, {10, "Out"}, {11, "Nov"}, {12, "Dez"}
    };

  size_t barra1 = str.find('/');
  size_t barra2 = str.rfind('/');
  std::string aux;

  if (barra1 != std::string::npos && barra2 != std::string::npos &&
        barra1 < barra2) {
        aux = str.substr(barra1 + 1, barra2 - barra1 - 1);
        int num = std::stoi(aux);
        if (num >= 1 && num <= 12) {
            aux = meses[num];
        }
    }

  std::cout << aux << std::endl;
}
