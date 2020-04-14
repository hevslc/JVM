#ifndef _METHOD_INFO_HPP_
#define _METHOD_INFO_HPP_

#include "Definitions.h"
#include "AttributeInfo.h"
#include "CpInfo.h"

/*!
   \brief Estrutura de um método na JVM.
 */
class MethodInfo
{
public:
  AcessFlags accessFlags; /*!< Flags de acesso do método */
  u2 nameIndex;           /*!< Indica onde está o nome do método na tabela constant_pool */
  u2 descriptorIndex;     /*!< Indica a posição do descritor do método na tabela constant_pool */
  u2 attributesCount;     /*!< Indica o tamanho o vetor que comporta os atributos do método */
  Attributes *attributes; /*!< Vetor de atributos */

  std::string name;       /*!< Nome do método */
  std::string descriptor; /*!< Descritor do método */

  ~MethodInfo();

  /*!
     \brief Inicializa um objeto MethodInfo.
     Basicamente decodifica nome e descritor do método.
     
     \param cp Tabela pool de constantes.
   */
  void init(ConstantPool &cp);

  /*!
     \brief Imprime os dados do método em uma saída.
     
     \param out Saída onde o método será impresso.
     \param cp Tabela pool de constantes.
   */
  void print(std::ostream &out, ConstantPool &cp);

private:
  /*!
     \brief Imprime o nome do método em uma saída.
     
     \param out Local onde será impresso o nome do método.
   */
  void printName(std::ostream &out);

  /*!
     \brief Imprime o descritor do método.
     
     \param out Onde será impresso o método.
   */
  void printDescriptor(std::ostream &out);
};

/*!
   \brief Vetor dos métodos da JVM.
 */
class Methods : public std::vector<MethodInfo*> {
public:
  Methods() {}

  /*!
     \brief Constrói um novo vetor de métodos.

     \param file        Arquivo .class.
     \param fieldsCount Número de Fields.
     \param cpTable     Pool de constantes.
   */
  Methods(std::ifstream& file, u2 fieldsCount, ConstantPool cpTable);

  /*!
     \brief Destrói o vetor de métodos.
   */
  ~Methods();

  /*!
     \brief Imprime o vetor no terminal.
   */
  void print(std::ostream& out, ConstantPool cpt);

};

#endif // _METHOD_INFO_HPP_